#include <stdio.h>
#include <windows.h>
void drawMagicBox(int num);
int getAbs(int x, int base);

int main()
{
    int num;
    do{
        printf("Enter number to draw magic box\n");
        scanf("%d",&num);
    }
    while(num%2==0 || num ==1);

    system("cls");

    drawMagicBox(num);

    return 0;
}


void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
    );
}


void drawMagicBox(int num){
    int x,y;

    for(int i=1;i<=num*num;i++){

        if(i==1){
            x = (num/2);
            y = 0;
        } else if ( (i-1)% num !=0 ){
            x = x-1;
            y = y-1;
        } else {
            y = y+1;
        }
        x = getAbs(x,num);
        y = getAbs(y,num);

        gotoxy(x*num,y);
        printf("%d",i);

    }
}



int getAbs(int num, int base){
    if(num < 0){
        return ((num+base)%base);
    } else{
        return num%base;
    }
}
