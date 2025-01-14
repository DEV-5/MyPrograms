//DATE:30-11-16
#include"Header.h"

 void print(STUDENT*st)
{
 if(st==NULL){printf("\n the list is empty\n");return;}
 
 printf("\n   ________________________________________________________");
 for(st;st;st=st->link)
 {
  printf("\n  |name:%-20s |roll: %-10d |marks:%.2f|",st->name,st->roll,st->marks);
 }
 printf("\n  |__________________________|_________________|___________|\n");
 return;
}
