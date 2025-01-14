
//DATE:30-11-16
#include"Header.h"
 
void add(STUDENT**phead)
{
 STUDENT *temp;//temp=*phead i.e temp=head
 temp=malloc(sizeof(STUDENT));
 printf("\nEnter the name of the student: ");
 scanf("%s",temp->name); 
 printf("\nEnter the marks obtained by the student: ");
 scanf("%f",&(temp->marks));
 printf("\nEnter the roll number of the student: ");
 scanf("%d",&(temp->roll));
 
 temp->link=*phead;
 *phead= temp;
}
