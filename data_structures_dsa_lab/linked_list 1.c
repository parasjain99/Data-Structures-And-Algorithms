#include<stdio.h>
#include<stdlib.h>

 typedef struct ListNode{
 int data;
 struct ListNode* next;
 } node;

int ListLength(struct ListNode **head)
{
    struct ListNode *current = *head;
    int count=0;
    while(current!=NULL)
    {
        printf("%d\n",current->data);
        count++;
        current=current->next;
    }

    return count;
}

void InsertInLinkedList(node **head,int data,int position)
{
    int k=1;
    struct ListNode *p,*q,*n;
    n=(node *)malloc(sizeof(struct ListNode));

    if(!n){
        printf("Memory Error\n");
        return;
    }
    n->data=data;
    p=*head;
    //Inserting at the beginning
    if(position==1){
        n->next=p;
        *head=n;
    }
    else{
        //Traverse the list until the position where we want to insert
        while((p!=NULL)&&(k<position)){
            k++;
            q=p;
            p=p->next;
        }
        q->next=n;
        n->next=p;
    }
}


void delNode(node **head,int position)
{
    int k=1;
    struct ListNode *p,*q;
    //n=(node *)malloc(sizeof(struct ListNode));
    p=*head;
    //q=p;
    //Inserting at the beginning
    if(position==1){
        //*head=p->next;
        p=p->next;
        *head=p;
    }
    else{
        //Traverse the list until the position where we want to insert
        while((p!=NULL)&&(k<position)){
            k++;
            q=p;
            p=p->next;
        }
        q->next=p->next;
        q=p;
        //n->next=p;
    }
    free(p);
}

int main()
{
    int n=1,u,v,s,p;
    node *a;
    a=(node*)malloc(sizeof (node));
    a->next=NULL;
    printf("press 1 to create list\npress 2 to insert element\npress 3 to delete element\n");
    scanf("%d",&s);
    //printf("%d",s)
    while(s!=0){
    switch(s){
        case 1 : {  printf("enter number of elements");
                    scanf("%d",&p);
                    printf("Enter the data of the first node\n");
                    scanf("%d",&(a->data));
                    v=2;
                    while(p>1){
                    printf("Enter the data of %d position\n",v);
                    scanf("%d",&u);
                    v++;
                    InsertInLinkedList(&a,u,v);
                    p--;
                    }
                    printf("%d\n",ListLength(&a));
                    break;
        }
        case 2 : {

                            printf("Enter the data and the position\n");
                            scanf("%d",&u);
                            scanf("%d",&v);
                            InsertInLinkedList(&a,u,v);
                            printf("%d\n",ListLength(&a));
                            break;

                        }
        case 3 : {         printf("enter position");
                            scanf("%d",&v);
                            delNode(&a,v);
                            printf("success\n");
                            ListLength(&a);
                            break;
                        }
        case 4 : {
                        v=ListLength(&a);
                       printf("list length is %d",v);
                       break;

                    }
        default : {     printf("enter valid choice");
                        scanf("%d",s);
                        break;
                        }
    }
        printf("press 1 to create list\npress 2 to insert element\npress 3 to delete element\n");
        scanf("%d",&s);
    }
    return 0;
}
