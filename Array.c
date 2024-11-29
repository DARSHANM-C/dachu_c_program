#include <stdio.h>
struct student {
    char name [50];
    int age;
    float gender;
    int college;
    int department;
};
int main (){
    struct student s1;
    printf("Enter name:");
    scanf("%s",s1.name);
    printf("Enter age:");
    scanf("%d", &s1.age);
    printf("Enter gender:");
    scanf("%f", &s1.gender);
    printf("Ente college:");
    scanf("%s", &s1.college);
    printf("Enter department");
    scanf("%s", &s1.department);
    printf("\nstudent details:\n");
    printf("name:%s\nage:%d\ngender:%s\ncollage:%s\ndepartment:%2f\n",s1.name,s1.age,s1.gender,s1.college,s1.department);
    return 0;
}
