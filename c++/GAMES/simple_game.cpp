
//Author:Vasudev.M
//developing my first game : simple snake
//source video tutorial link: https://www.youtube.com/watch?v=W1e5wO7XR2w

#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<ncurses.h>
using namespace std;

//global variables
bool gameOver;
const int width = 30;//border width
const int height = 20;//border height
int x,y,fruitX,fruitY,score;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;//declaring Edirection variable;

void Setup()
{
    gameOver= false; 
    dir = STOP;
    score = 0;
    x = width/2;
    y = height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;
}

void Draw()
{
    system("clear");
    for(int h =0;h<height;h++)
    {
        for(int w = 0;w<width;w++)
        {
            //sleep(1.5);
            if ( h==0 ||  h==height-1)//top most and bottom most lines
                printf("#");
            else
            {
             if(w==0 || w==width-1)
                 printf("#");
             else if(w==x && h==y)
                 printf("0");
             else if(w==fruitX && h==fruitY)
                 printf("f");
             else 
                 printf(" ");
            }
        }
        printf("\n");
    }
}

void Logic()
{
    switch(dir)
    {
        case STOP:
            break;

        case UP:
            y++;
            break;
    
        case LEFT:
            x--;
            break;
    
        case RIGHT:
            x++;
            break;
    
        case DOWN:
            y--;
            break;

        default:
            printf("Debug Out:Incorrect direction\n");
    }
}

void Input()
{
    //_kbhit();
    //if ()
    char ch = getch();
    printf("you entered: %c\n");
    sleep(9);
    switch(ch)
    {
        case 'w':
            dir = UP;
            break;
        
        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;

        case 's':
            dir = DOWN;
            break;
        
        default:
            break;
    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}

