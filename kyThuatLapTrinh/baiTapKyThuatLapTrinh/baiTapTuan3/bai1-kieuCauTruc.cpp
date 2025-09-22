#include <stdio.h>
#include <math.h>

// dinh nghia cau truc point
struct Point {
    float x;
    float y;
};

// tinh khoang cach giua 2 diem
float distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// tinh dtich tam giac
float area(struct Point p1, struct Point p2, struct Point p3) {
    return fabs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

// ktra 3 dinh co tao ra tam giac khong 
int isTriangle(struct Point p1, struct Point p2, struct Point p3) {
    float s = area(p1, p2, p3);
    return (s > 0); 
}

//  tinh chu vi tam giac
float perimeter(struct Point p1, struct Point p2, struct Point p3) {
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    return a + b + c;
}

int main() {
    struct Point p1, p2, p3;

    // nhap toa do 3 diem
    printf("Nhap toa do diem 1 (x, y): ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Nhap toa do diem 2 (x, y): ");
    scanf("%f %f", &p2.x, &p2.y);
    printf("Nhap toa do diem 3 (x, y): ");
    scanf("%f %f", &p3.x, &p3.y);

    // ktra tam giac
    if (isTriangle(p1, p2, p3)) {
        printf("Ba diem tao thanh mot tam giac.\n");

        // Tinh vi in chu vi
        float p = perimeter(p1, p2, p3);
        printf("Chu vi tam giac: %.2f\n", p);

        // Tinh vi in dtich
        float s = area(p1, p2, p3);
        printf("Dien tich tam giac: %.2f\n", s);
    } else {
        printf("Ba diem khong tao thanh mot tam giac (thang hang).\n");
    }

    return 0;
}
