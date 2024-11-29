inxlude<stdio.h>
int largest(int a,int b,intc){
if(a>=b&&a>=c)return a;
if(b>=a&&b>=c)returnb;
return c;
}
int main(){
int x,y,z;
printf("enter three numbers;");
scanf("d%d%d%d",&x,&y,&z);
printf("largest=%d\n",largest(x,y,z));
return 0;
}
