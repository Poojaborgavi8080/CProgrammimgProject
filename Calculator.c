#include<stdio.h>
int main()
{
    char operator;
    printf("Enter operator : ");
    scanf("%c",&operator);
    int a,b;
    printf("Enter First value : ");
    scanf("%d",&a);
    printf("Enter Second Value : ");
    scanf("%d",&b);

    switch(operator)
    {
      case '+':
       
      printf("Addition is : %d",a+b);
      break;
      case '-':
      
      printf("Subtraction is : %d",a-b);
      break;
      case '*':
       
      printf("Multification is : %d",a*b);
      break;
      case '/':
      
      printf("Division is : %d",a/b);
      break;
      case '%':
      
      printf("Modulus is : %d",a%b);
      break;
      default:
      printf("Please enter valid operator");
    }
}