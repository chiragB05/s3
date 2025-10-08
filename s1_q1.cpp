#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
} *startl = NULL, *startr = NULL, *temp, *newnode;
int n;
void create()
{
    int i;
    printf("Enter the number of nodes in double link list : ");
    scanf("%d", &n);
    if (n < 1)
        printf("linklist must have at least one node");
    else
    {
        for (i = 1; i <= n; i++)
        {
            newnode = (node *)malloc(sizeof(struct node));
            printf("Enter integer data for node %d: ",i);
            scanf("%d", &newnode->data);
            if (i == 1)
                startl = startr = temp = newnode;
            else
            {
                temp->next = newnode;
                newnode->prev = temp;
                temp = temp->next;
            }
            startr = temp;
            startl->prev = NULL;
            startr->next = NULL;
        }
	}
}
void display()
{
    printf("\nDoubly Linked List From Left To Right :");
    temp = startl;
    printf("STARTL-->");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\nDoubly Linked List From Right To Left :");
    temp = startr;
    printf("STARTR-->");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->prev;
    }
    printf("NULL");
    printf("\nNumber of nodes in double link list is:%d \n",n);
}
int main()
{
    int c = 1;
    while (c!=3)
    {
        printf("Operation on Doubly Linked List :\n");
        printf("\n1 : Create a Doubly Linked List.");
        printf("\n2 : Display a DLL.");
        printf("\n3 : Exit.");
        printf("\nEnter Operation You Want To Perform :");
        scanf("%d", &c);
        switch (c)
        {
        	case 1:
            	if (startl != NULL && startr != NULL)
                	printf("Doubly Linked List is Already Created.");
            	else
            	    create();
            	break;
        	case 2:
        	    if (startl == NULL && startr == NULL)
            	    printf("Doubly Linked List Is Empty.");
            	else
            	    display();
            	break;
        	case 3:(0);
        		default:
            			printf("ERROR.....INVALID OPERATION.\n");
            			break;
    	}
            display();
    }
}
