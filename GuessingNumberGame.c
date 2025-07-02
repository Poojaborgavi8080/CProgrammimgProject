#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int random,guess;
    int No_Of_Guess=0;
    srand(time(NULL));

    printf("Welcome to world of Guessing Numbers \n ");
    random= rand() % 101; //Generating between  0 to 100

    do
    {
        printf("Enter your guess number between 0 to 100 \n");
        scanf("%d",&guess);
        No_Of_Guess++;

        if(guess<random)
        {
            printf("Guess Larger Number . \n");
        }
        else if(guess>random)
        {
            printf("Guess Smaller Number . \n");
        }
        else
        {
            printf(" Congratulation !!! \n You have successfully guessed the number in %d attempts . \n",No_Of_Guess);
        }
    }while(guess!=random);
        printf("\n Bye Bye, Thanks for Playing");
        printf("\n Developed By Miss.Pooja\n");
        return 0;
      

    }


