#include<stdio.h>
void display(char [],int*,int*,int*);
 void sum(int,int,int);
int main()
{
    //int sum=0;
    
    char name[30];
    int mark1,mark2,mark3;
    
    display(name,&mark1,&mark2,&mark3);
    sum(mark1,mark2,mark3);
    return 0;
}
void display(char name[],int* mark1,int* mark2,int* mark3)
{
    printf("Enter Name : ");
    scanf(" %[^\n]",name);
    printf("Enter Three Subject Marks : \n");
    scanf("%d%d%d",mark1,mark2,mark3);

}
void sum(int a,int b,int c)
{
  int sum=a+b+c;
  printf("sum is : %d",sum);
  int avg=sum/3;
  printf("\nAverage is : %d",avg);
}