#include <stdio.h>
#include <stdlib.h>


typedef struct Student {
 int id;
 char nameStudent[50];
 float GPA;
} Student;

void inputStudent(Student *st){
     printf("Enter ID:");
     scanf("%d",&st->id);
     printf("Enter name:");
     getchar();
     fgets(st->nameStudent,sizeof(st->nameStudent),stdin); 
     fflush(stdin);
     printf("Enter GPA:");
     scanf("%f",&st->GPA);
     
}
void inputListStudent(Student *st,int n){
    for(int i=0;i<n;i++)
    {
        printf("Input Student %d\n",i+1);
        inputStudent(&st[i]);
    }
}
void ouputStudent(Student st) {
    printf("|");
 printf("%-9d",st.id);
 printf("|");
 printf("%-30s",st.nameStudent);
 printf("|");
 printf("%-11.1f",st.GPA);
 printf("|");
}
void ouputListStudent(Student listStudent[],int n){
    printf("\n<===================STUDENT LIST==================>\n");
    printf("+---------+---------------------------+-----------+\n");
    printf("|   ID    |            NAME           |    GPA    |\n");
    printf("+---------+---------------------------+-----------+\n");
    
    for(int i=0;i<n;i++){
     ouputStudent(listStudent[i]);
     printf("\n");
 }
 printf("+---------+---------------------------+-----------+\n");
}
void ouputStudentMaxGPA(Student st) {
   
 printf("ID : %d\n",st.id);
 printf("NAME : %s\n",st.nameStudent);
 printf("GPA : %.1f\n",st.GPA);
}
int findStudentMaxGPA(Student listStudent[],int n){
    int maxGPA=listStudent[0].GPA;
    int indexSt=0;
    for(int i=0;i<n;i++)
    {
        if(maxGPA<listStudent[i].GPA)
        {
            maxGPA=listStudent[i].GPA;
            indexSt=i;
        }
    }
    return indexSt;
}

int main() {
    // Khai báo danh sách N Sinh viên
    int n;
    printf("Enter number Student :");
    scanf("%d",&n);

 Student listStudent[n];
    // nh?p danh sách sinh viên
    inputListStudent(listStudent,n);
 // in ra danh sách Sinh viên
 ouputListStudent(listStudent,n);
 // Tìm ra sinh viên có di?m cao nh?t.
     // in ra di?m cao nh?t
 printf("Sinh Viên có di?m GPA cao nh?t :\n");    
 ouputStudentMaxGPA(listStudent[findStudentMaxGPA(listStudent,n)]);
 
 
 return 0;
}

