#include<stdio.h>
int main(){
intn,t1=0,t2=1,nextterm;
printf("enter the number of terms:");
scanf("%d",&n);
printf("fibonacci series:%d,%d",t1,t2);
for(int=3;i<=n;i++){
nextterm=t1+t2;
t1=t2;
t2=nextterm;
}
return0;
}