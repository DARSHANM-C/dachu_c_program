#include <stdio.h>
int main(void) {
  float p,t,r,interest;
  printf("enter the values of p,t,r\n");
scanf("%f%f%f",&p,&t,&r);
  interest=(p*t*r)/100;
  printf("the simple interest is%f",interest);
  return 0;
}
