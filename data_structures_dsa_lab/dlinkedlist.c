#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct dnode{
int data;
struct dnode *next;
struct dnode *prev;
};
void insert(struct dnode **head, int data, int pos){
    int k=1;
    struct dnode *temp, *nn;
    nn=(struct dnode *) malloc(sizeof(struct dnode));
    if(!nn){
        printf("Memory Error");
        return;
    }
    nn->data=data;
    if(pos==1){
        nn->next=*head;
        nn->prev=NULL;
        if(*head)
        (*head)->prev=nn;

        *head=nn;
        return;
    }
    temp=*head;
    while((k<pos-1)&&temp->next!=NULL){
        temp=temp->next;
        k++;
    }
    if(k!=pos){
        printf("position doesen't exist");
    }
    nn->next=temp->next;
    nn->prev=temp;
    if(temp->next)
        temp->next->prev=nn;
    temp->next=nn;
    return;
}
int ListLength(struct dnode *head)
{
    struct dnode *current = head;
    int count=0;
    while(current!=NULL)
    {
        printf("%d\n",current->data);
        count++;
        current=current->next;
    }

    return count;
}
int main()
{
    int n=1,u,v;
    struct dnode *a;
    a=(struct dnode*)malloc(sizeof (struct dnode));
    a->next=NULL;
    printf("Enter the data of the first node\n");
    scanf("%d",&(a->data));
    while(n!=0)
    {
        printf("Enter the data and the position and '0' terminates the program\n");
        scanf("%d",&u);
          if(u==0)
            break;
        scanf("%d",&v);
        insert(&a,u,v);
        printf("%d\n",ListLength(a));
    }
    return 0;
}
