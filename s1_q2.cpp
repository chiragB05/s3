#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void printList(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
	{	
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void bubbleSort(struct Node* head) 
{
    int swap ,temp;
    struct Node* ptr1;
    struct Node* lptr = NULL;
    if (head == NULL) return;
    do 
	{
        swap = 0;
        ptr1 = head;
        while (ptr1->next != lptr) 
		{
            if (ptr1->data > ptr1->next->data) 
			{
                temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; 
    } while (swap);
}
struct Node* createLinkedList(int n) 
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) 
	{
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        struct Node* new_node = newNode(data);   
        if (head == NULL) 
		{
            head = tail = new_node;
        } 
		else 
		{
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}
int main() 
{
    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    struct Node* head = createLinkedList(n);
    printf("Original linked list:\n");
    printList(head);
    bubbleSort(head);
    printf("Sorted linked list:\n");
    printList(head);
    return 0;
}
