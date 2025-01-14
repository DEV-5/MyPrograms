#include<ncurses.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
 int i;
 system("clear");
 initscr();
 mvprintw(0,0,"Enter a number:");
 //refresh();
 i = getch()-48;
//scanf("%d",&i);
 mvprintw(20,20,"Present value of i is:");
 refresh();
 while(1) 
 {
    if(i%2)
        i =3*i+1;
    else
        i/=2;
    
    mvprintw(20,42,"                            ",i);
    mvprintw(20,42,"%d",i);
    refresh();
    sleep(1);
    if (i==1)
        break;
 }
 
 mvprintw(40,20,"Success the value has reached zero");
 refresh();
 sleep(3);
 endwin();
 return 0;
}
