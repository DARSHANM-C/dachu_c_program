#include<stdio.h>
int main(){
intx=10;
int*ptr=&x;
printf("address of x:%pn",ptr);
printf("value of x:%d\n",*ptr);
return0;
}
