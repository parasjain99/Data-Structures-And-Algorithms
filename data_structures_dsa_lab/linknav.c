#include<stdio.h>
#include<stdlib.h>

 typedef struct ListNode{
 int data;
 struct ListNode* next;
 } node;

int Length(struct ListNode* head)
{
    struct ListNode* current=head;
    int count=0;
    while(current!=NULL)
    {
        printf("%d  ",current->data);
        count++;
        current=current->next;
    }

    return count;
}

void Insert(node **head,int data,int position)
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
    if(position==1){
        n->next=p;
        *head=n;
    }
    else{
        while((p!=NULL)&&(k<position)){
            k++;
            q=p;
            p=p->next;
        }
        q->next=n;
        n->next=p;
    }
}

void Delete(node **head,int position)
{
int k=1;
struct ListNode *p,*q;
if(*head==NULL){
    printf("List Empty\n");
    return;
}
p=*head;
if(position==1){
    *head=(*head)->next;
    free(p);
    return;
}
else{
    while((p!=NULL)&&(k<position)){
        k++;
        q=p;
        p=p->next;
    }
    if(p==NULL)
        printf("Position does not exist");
    else{
        q->next=p->next;
        free(p);
    }
    }
}

void reverse(node **head)
{
    node *a,*b,*c;
    a=b=c=*head;
    a=b->next->next;
    b=b->next;
    c->next=NULL;
    b->next=c;

    while(a!=NULL)
    {
        c=b;
        b=a;
        a=a->next;
        b->next=c;
    }
    *head=b;
}

void sort(node **head)
{
    int i,j,a,g;
    node *temp1;
    node *temp2;
    for(temp1= *head;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
        {
            if(temp2->data < temp1->data)
            {
                g=temp1->data;
                temp1->data=temp2->data;
                temp2->data=g;
            }
        }
    }
}

int main()
{
    int n=1,u,v,w,z;
    node *a;
    a=(node*)malloc(sizeof (node));
    a->next=NULL;
    printf("Enter the data of the first node\n");
    scanf("%d",&(a->data));
    while(n!=0)
    {
        printf("Choose what you want to do\n");
        printf("1. Insertion\n2. Deletion\n3. Reverse\n4. Sort\n");
        scanf("%d",&z);
        switch(z){
    case 1:{
        printf("Enter the data and the position and '0' terminates the program\n");
        scanf("%d",&u);
          if(u==0){
            break;}
        scanf("%d",&v);
        Insert(&a,u,v);
        printf("\nList Length = %d\n",Length(a));
        break;
    }
    case 2:{
         printf("Enter the position of the node you want to delete\n");
        scanf("%d",&v);
        Delete(&a,v);
        printf("\nList Length = %d\n",Length(a));
        break;
    }
    case 3:{
        reverse(&a);
        printf("\nList Length = %d\n",Length(a));
        break;
    }
    case 4:{
        sort(&a);
        printf("\nList Length = %d\n",Length(a));
        break;
    }
        }
    }
    return 0;
}
