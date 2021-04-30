#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//Function Declaration
int Random(int first, int last);
int RANDLOTTERY();
int PREDICTLOTTERY(int casino, int player);

//Global Variables
int GuessedCorreclty = 0;
char Order[5][10] = {"first","second","third","fourth","fifth"};

int main()
{
    //Local Variables
    int drawnNumber[5], predictDrawnNumber[5];

    //Set Seed for rand() Function
    srand(time(0));

    //Generate Random Numbers
    for(int i=0;i<5;i++)
        drawnNumber[i] = RANDLOTTERY();

    //Player Guesses
    printf("\n****** LOTTERY GAME ******\n\n");
    printf("Select five distinct integers between (1 and 40)\n");
    for(int i=0;i<5;i++)
    {
        printf("Integer %d : ",i+1);
        scanf("%d",&predictDrawnNumber[i]);
    }

    //Check Guessed Numbers
    for(int i=0;i<5;i++)
        PREDICTLOTTERY(drawnNumber[i],predictDrawnNumber[i]);

    if(GuessedCorreclty == 5) printf("\nYou win!");
    else printf("\nYou lose!");

    getch();
    return 0;
}

int Random(int first, int last)
{
    int r;
    last += (1-first);
    r = rand()%last + first;
    return r;
}

int RANDLOTTERY()
{
    static int _order=0;
    int r = Random(1,40);

    printf("The %s drawn number is: %d\n",Order[_order], r); _order++;
    return r;
}

int PREDICTLOTTERY(int casino, int player)
{
    GuessedCorreclty += casino == player ? 1 : 0;
}