#include "stdio.h"
#include "string.h"
#include "ctype.h"
#ifdef _WIN32
#include "conio.h"
#else
#include "termios.h"
#include "unistd.h"
#endif

#define MAX_ATTEMPTS 3
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define FILENAME "users.txt"

// Hàm ẩn mật khẩu khi nhập
void get_password(char *password, int max_len) {
    int i = 0;
    char ch;
#ifdef _WIN32
    while (i < max_len - 1 && (ch = getch()) != '\r') {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else if (ch != '\b') {
            password[i++] = ch;
            printf("*");
        }
    }
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    while (i < max_len - 1 && (ch = getchar()) != '\n') {
        if (ch == 127 && i > 0) { // 127 là mã ASCII cho backspace trên Unix
            printf("\b \b");
            i--;
        } else if (ch != 127) {
            password[i++] = ch;
            printf("*");
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
    password[i] = '\0';
    printf("\n");
}

// Hàm kiểm tra định dạng mật khẩu
int is_valid_password(const char *password) {
    if (strlen(password) < 8) return 0;
    
    int has_upper = 0, has_lower = 0, has_digit = 0;
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) has_upper = 1;
        else if (islower(password[i])) has_lower = 1;
        else if (isdigit(password[i])) has_digit = 1;
    }
    return has_upper && has_lower && has_digit;
}

// Hàm kiểm tra đăng nhập
int check_login(const char *username, const char *password) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return 0;
    
    char file_username[MAX_USERNAME], file_password[MAX_PASSWORD];
    char line[200];
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^:]:%s", file_username, file_password);
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

// Hàm đăng ký người dùng
int register_user(const char *username, const char *password) {
    if (strlen(username) < 5) {
        printf("Tên đăng nhập phải có ít nhất 5 ký tự!\n");
        return 0;
    }
    if (!is_valid_password(password)) {
        printf("Mật khẩu phải có ít nhất 8 ký tự, chứa chữ hoa, chữ thường và số!\n");
        return 0;
    }
    
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Không thể mở file để lưu thông tin!\n");
        return 0;
    }
    
    fprintf(file, "%s:%s\n", username, password);
    fclose(file);
    return 1;
}

// Hàm thay đổi mật khẩu
int change_password(const char *username, const char *new_password) {
    if (!is_valid_password(new_password)) {
        printf("Mật khẩu mới phải có ít nhất 8 ký tự, chứa chữ hoa, chữ thường và số!\n");
        return 0;
    }
    
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Không thể mở file để đọc!\n");
        return 0;
    }
    
    char temp_filename[] = "temp.txt";
    FILE *temp_file = fopen(temp_filename, "w");
    if (!temp_file) {
        fclose(file);
        printf("Không thể tạo file tạm!\n");
        return 0;
    }
    
    char line[200], file_username[MAX_USERNAME], file_password[MAX_PASSWORD];
    int updated = 0;
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^:]:%s", file_username, file_password);
        if (strcmp(username, file_username) == 0) {
            fprintf(temp_file, "%s:%s\n", username, new_password);
            updated = 1;
        } else {
            fprintf(temp_file, "%s:%s\n", file_username, file_password);
        }
    }
    
    fclose(file);
    fclose(temp_file);
    
    if (!updated) {
        remove(temp_filename);
        printf("Không tìm thấy người dùng!\n");
        return 0;
    }
    
    remove(FILENAME);
    rename(temp_filename, FILENAME);
    return 1;
}

int main() {
    char username[MAX_USERNAME], password[MAX_PASSWORD], confirm_password[MAX_PASSWORD];
    int attempts = 0;
    int choice;
    
    while (1) {
        printf("\n1. Đăng nhập\n2. Đăng ký\n3. Thay đổi mật khẩu\n4. Thoát\nChọn: ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự newline
        
        if (choice == 4) {
            printf("Đã thoát chương trình.\n");
            return 0;
        }
        
        if (choice == 2) { // Đăng ký
            printf("Nhập tên đăng nhập: ");
            fgets(username, MAX_USERNAME, stdin);
            username[strcspn(username, "\n")] = 0;
            
            printf("Nhập mật khẩu: ");
            get_password(password, MAX_PASSWORD);
            
            printf("Xác nhận mật khẩu: ");
            get_password(confirm_password, MAX_PASSWORD);
            
            if (strcmp(password, confirm_password) != 0) {
                printf("Mật khẩu xác nhận không khớp!\n");
                continue;
            }
            
            if (register_user(username, password)) {
                printf("Đăng ký thành công!\n");
            } else {
                printf("Đăng ký thất bại!\n");
            }
            continue;
        }
        
        if (choice == 3) { // Thay đổi mật khẩu
            printf("Nhập tên đăng nhập: ");
            fgets(username, MAX_USERNAME, stdin);
            username[strcspn(username, "\n")] = 0;
            
            printf("Nhập mật khẩu hiện tại: ");
            get_password(password, MAX_PASSWORD);
            
            if (!check_login(username, password)) {
                printf("Tên đăng nhập hoặc mật khẩu không đúng!\n");
                continue;
            }
            
            printf("Nhập mật khẩu mới: ");
            get_password(password, MAX_PASSWORD);
            
            printf("Xác nhận mật khẩu mới: ");
            get_password(confirm_password, MAX_PASSWORD);
            
            if (strcmp(password, confirm_password) != 0) {
                printf("Mật khẩu xác nhận không khớp!\n");
                continue;
            }
            
            if (change_password(username, password)) {
                printf("Thay đổi mật khẩu thành công!\n");
            } else {
                printf("Thay đổi mật khẩu thất bại!\n");
            }
            continue;
        }
        
        if (choice == 1) { // Đăng nhập
            attempts = 0;
            while (attempts < MAX_ATTEMPTS) {
                printf("Nhập tên đăng nhập: ");
                fgets(username, MAX_USERNAME, stdin);
                username[strcspn(username, "\n")] = 0;
                
                printf("Nhập mật khẩu: ");
                get_password(password, MAX_PASSWORD);
                
                if (check_login(username, password)) {
                    printf("Đăng nhập thành công!\n");
                    break;
                } else {
                    attempts++;
                    printf("Đăng nhập thất bại! Còn %d lần thử.\n", MAX_ATTEMPTS - attempts);
                }
            }
            
            if (attempts >= MAX_ATTEMPTS) {
                printf("Đã hết số lần thử. Tài khoản bị khóa!\n");
                continue;
            }
        }
    }
    
    return 0;
}