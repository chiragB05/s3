#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL,*t,*temp;
int n;
void create()
{
    int i;
    for (i=1;i<=n;i++)
    {
        temp=(node *)malloc(sizeof(struct node));
        printf ("\n Enter the data for node %d : ",i);        
        scanf ("%d",&temp->data);
        if (i==1)
           start=t=temp;
        else
        {
           t->next=temp;
           t=t->next;
        } 
    }
    t->next=NULL;
}
void display()
{
    if (start==NULL)
    	printf("\n Link list is empty..");
    else
    {
        printf ("\n\n start-->");
    	for (t=start;t->next!=NULL;t=t->next)
            printf ("%d-->",t->data);
    	printf("%d -->NULL\n\n",t->data);
    }
}
int main()
{
    int m=1,ch,i;
    while (m!=3)
    {
        printf ("\n    Select one of the following options:    \n");
        printf ("\n    1 : To create Singly linked list ");
        printf ("\n    2 : To display Singly linked list ");
        printf ("\n    3 : Exit. ");          
        printf ("\n\n  Enter your option :  ");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 1:
				if (start!= NULL)
                   printf("\n  Singly linked list already exists \n");      
                else
                {
                	printf("\n Enter the number of nodes : "); 
                    scanf ("%d",&n);
                    if (n<=0)
                        printf("\n Invalid data entered...\n");
                    else                            
                        create();
                }
                break;
            case 2: 
				if (start==NULL)
                    printf("\n Singly Link list is empty..");
                else
                    display(); 
                    break;
        }
        display();
	}       
}
