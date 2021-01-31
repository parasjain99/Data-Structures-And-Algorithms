#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();

int main()
{
   int choice, value;
   printf("\n:: Stack using Linked List ::\n");
    while(1)
    {
        /*clrscr();*/
        printf("Enter Choice (1: display, 2: insert (PUSH), 3: remove(POP)), 4: Exit..:");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1:
                display();
            break;
            case 2:
                printf("Enter Item to be insert :");
                scanf("%d",&value);
                push(value);
            break;
            case 3:
                pop();
            break;
            case 4:
                exit(1);
            default:
            printf("\nInvalid choice.");
            break;
        }
    }
}
void push(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
   printf("\nInsertion is Success!!!\n");
}
void pop()
{
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct Node *temp = top;
      printf("\nDeleted element: %d", temp->data);
      top = temp->next;
      free(temp);
   }
}
void display()
{
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct Node *temp = top;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL",temp->data);
   }
}
