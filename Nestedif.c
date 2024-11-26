include <stdio.h>
int main(){
  int number;
  printf("Enter a number:");
  scanf("%d",&number);
  if(number%3==0) {
    if(number%5==0){
      printf("%d is divisible by 3 and 5\n", number);
  } else {
      printf("%d is divisible by 3\n", number);
    }
  } else {
    printf("%d is not divisible by 3\n", number);
  }
  {
    printf("deekshitha ");
  }
  return 0;
  }
