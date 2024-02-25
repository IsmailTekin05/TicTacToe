#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char a1,a2,a3,b1,b2,b3,c1,c2,c3 = ' ';
int player,computer={0};
bool thewinnerisplayer;

//Shows the player which number fills which blank.
void startingScreen(){
    printf("\t\t\t Tic-Tac-Toe\n\n");
    printf("Please enter the number in place the point you want to play.\n\n");

    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t-----------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t-----------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

//Prints the cardboard.
void template(){
printf("\t\t\t Tic-Tac-Toe\n\n");
printf("Choose the coordinate to play.\n\n");

printf("\t\t\t %c | %c | %c \n",a1,a2,a3);
printf("\t\t\t-----------\n");
printf("\t\t\t %c | %c | %c \n",b1,b2,b3);
printf("\t\t\t-----------\n");
printf("\t\t\t %c | %c | %c \n\n",c1,c2,c3);

printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

//Checks if cardboard aligned.
bool isitalinged(){
    if ((a1 == a2 && a2 == a3) && (a1 == 'X' || a1 == 'O'))
        return false;
    else if ((b1 == b2 && b2 == b3) && (b1 == 'X' || b1 == 'O'))
        return false;
    else if ((c1 == c2 && c2 == c3) && (c1 == 'X' || c1 == 'O'))
        return false;
    else if ((a1 == b1 && b1 == c1) && (a1 == 'X' || a1 == 'O'))
        return false;
    else if ((a2 == b2 && b2 == c2) && (a2 == 'X' || a2 == 'O'))
        return false;
    else if ((a3 == b3 && b3 == c3) && (a3 == 'X' || a3 == 'O'))
        return false;
    else if ((a1 == b2 && b2 == c3) && (a1 == 'X' || a1 == 'O'))
        return false;
    else if ((a3 == b2 && b2 == c1) && (a3 == 'X' || a3 == 'O'))
        return false;
    else
        return true;
}

//Checks if the given point is empty.
bool isitempty(int a,int arr[]){
    if(arr[a]==0)
        return true;
    else
        return false;
}

//Filling the point according to player or computer.
void filler(int x,int a,int arr[]){
    char sign;
    if(a==1)
        sign='X';
    else
        sign='O';
if(!isitempty(x,arr)){
    printf("Please enter a valid number.\n");
    int c;
    scanf("%d",&c);
    filler(c-1,1,arr);
    return;
}
        switch (x) {
            case (0):
                a1 = sign;
                break;
            case (1):
                a2 = sign;
                break;
            case (2):
                a3 = sign;
                break;
            case (3):
                b1 = sign;
                break;
            case (4):
                b2 = sign;
                break;
            case (5):
                b3 = sign;
                break;
            case (6):
                c1 = sign;
                break;
            case (7):
                c2 = sign;
                break;
            case (8):
                c3 = sign;
                break;
            default:
                printf("Please enter a valid value.\n");
                return;
        }
arr[x]=1;
}

//Checks if there's anymore space to be played.
bool isarrayfull(int arr[]){
    for (int i = 0; i <9 ; ++i) {
        if(arr[i]==0)
            return false;
    }
    return true;
}

//Find a random point and play as computer.
void computerfiller(int arr[]){
    for (;;) {
        int i = rand()%9;
        if(isitempty(i,arr)) {
            filler(i, 0,arr);
            arr[i]=1;
            return;
        }
    }

}

//Asks the player which point to be chosen and fills it.
void inputter(){
    int i = 0;
    int a;
    int arr[9]={0};

    do {
        i++;
        template();
        printf("Please enter the coordinate you want to put 'X'.\n");
        scanf("%d",&a);
        filler(a-1,1,arr);
        if(isarrayfull(arr) || !isitalinged()){
            thewinnerisplayer=true;
            break;}
        else{
        computerfiller(arr);
        thewinnerisplayer=false;}
    }
    while(i<5 && isitalinged());
template();
}

//Prints the score and asks if the player wants to player again.
void finisher(){
    if(!isitalinged()){
        if(thewinnerisplayer){
            printf("\n The winner is player. \n");
        player++;}
        else {
            printf("\n The winner is computer. \n");
        computer++;}
    }

    else
        printf("\n That's a tie.\n");
    printf("The score: Player %d - %d Computer.\n",player,computer);
    printf("Do you want to play again?\n (Y/N)\n");
    char a;
    scanf(" %c",&a);
    if( a == 'Y' || a == 'y'){
        a1 = a2 = a3 = ' ';
        b1 = b2 = b3 = ' ';
        c1 = c2 = c3 = ' ';
        inputter();
        finisher();
    }
    else
        printf("Thanks for playing!!\n");
}

//The game itself.
void tictactoe(){
startingScreen();
inputter();
finisher();
}

int main() {
    srand(time(0));
    tictactoe();
    return 0;
}
