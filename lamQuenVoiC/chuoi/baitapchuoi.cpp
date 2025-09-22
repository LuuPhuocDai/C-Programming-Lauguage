#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

// ham dem chuoi
int len(char chuoi[]){
	int i = 0;
	while(chuoi[i] != '\0'){
		i++;
	}
	return i;
}
// ham nhap chuoi
void nhapChuoi(char chuoi[], int size){
	printf("nhap chuoi: ");
	fgets(chuoi, size, stdin);
	int len1 = len(chuoi);
	if(chuoi[len1 - 1] == '\n'){
		chuoi[len1 - 1] = '\0';
	}
}
// ham xoa dau thua
void xoaDauThua(char chuoi[]){
	char temp[100];
	int ktra = 0;
	int len1 = len(chuoi);
	int i = 0, j = 0;
	// xoa dau thua o dau chuoi
	while(chuoi[i] == ' ' && len1 > i){
		i++;
	}
	// luu chuoi
	while(len1 > i){
		if(chuoi[i] != ' '){
			temp[j++] = chuoi[i];
			ktra = 1;
		}
		else{
		    if(ktra == 1){
			  temp[j++] = ' ';
			  ktra = 0;
		    }
		}
		i++;
	}
	// xoa dau cach o cuoi 
	if(j > 0 && temp[j - 1] == ' ') j--;
	// null
	temp[j] = NULL;
	// in lai cac ten
	for(int i = 0; i <= j; i++){
		chuoi[i] = temp[i];
	}
}
// ham in hoa dau
void inHoa(char chuoi[]){
	int len1 = len(chuoi);
	// in hoa chu cai dau cua chuoi
	if(chuoi[0] >= 'a' && chuoi[0] <= 'z'){
		chuoi[0] = toupper(chuoi[0]);
	}
	// duyet cac chuoi con lai
	for(int i = 1; i <= len1; i++){
		if(chuoi[i - 1] == ' ' && chuoi[i] >= 'a' && chuoi[i] <= 'z'){
			chuoi[i] = toupper(chuoi[i]);
		}
		else if(chuoi[i - 1] != ' ' && chuoi[i] >= 'A' && chuoi[i] <= 'Z'){
			chuoi[i] = tolower(chuoi[i]);
		}
	}
}
// ham ktra tinh doi xung cua chuoi
int ktrDXung(char chuoi[]){
	int len1 = len(chuoi);
	int i;
	for(i = 0; i < len1 / 2; i++){
		if(chuoi[i] != chuoi[len1-1-i]){
			return 0;
		}
	}
	return 1;
}
// ham ktr xem ky tu do co xuat hien khong
void TimVaDem(char chuoi[], char x){
	int len1 = len(chuoi);
	int dem = 0;
	for(int i = 0; i <= len1; i++){
		if(chuoi[i] == x){
			dem++;
		}
	}
	if(dem > 0){
		printf("%c co trong chuoi vua nhap va no xuat hien %d",x, dem);
	}else{
		printf("%c khong co trong chuoi vua nhap", x);
	}
}
// ham ktra chuoi trong mot cai chuoi
void ktraChuoiOfChuoi(char chuoi[], char ktra[]){
	
}



int main(){
	char chuoi[100];
    nhapChuoi(chuoi, sizeof(chuoi));
    xoaDauThua(chuoi);
	
	//ktra doi xung cua chuoi
	if(ktrDXung(chuoi) == 1){
		printf("chuoi doi xung ");
	}
	else{
		printf("chuoi khong doi xung");
	}
	
	inHoa(chuoi);
	printf("\n%s", chuoi);
	
	char x;
	printf("\nnhap ki tu x: ");
	scanf("%c", &x);
	
	TimVaDem(chuoi, x);
	
	
	
	
	
	
	return 0;
}
