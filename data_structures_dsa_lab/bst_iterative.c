#include<stdio.h>
#include<stdlib.h>
#define bool int


struct tNode
{
    int data;
    struct tNode* left;
    struct tNode* right;
};


struct sNode
{
    struct tNode *t;
    struct sNode *next;
};
void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);


void inOrder(struct tNode *root)
{

    struct tNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;

    while (!done)
    {

        if(current != NULL)
        {

        push(&s, current);
        current = current->left;
        }


        else
        {
        if (!isEmpty(s))
        {
            current = pop(&s);
            printf("%d ", current->data);

            current = current->right;
        }
        else
            done = 1;
        }
    }
}

void preOrder(struct tNode *root)  //wrong
{

    struct tNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;

    while (!done)
    {

        if(current != NULL)
        {

            push(&s, current);
            printf("%d ", current->data);
            current = current->left;
        }


        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                //printf("%d ", current->data);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}

void push(struct sNode** top_ref, struct tNode *t)
{

    struct sNode* new_tNode = (struct sNode*) malloc(sizeof(struct sNode));

    if(new_tNode == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }

    new_tNode->t = t;


    new_tNode->next = (*top_ref);


    (*top_ref) = new_tNode;
}

bool isEmpty(struct sNode *top)
    {
    return (top == NULL)? 1 : 0;
}


struct tNode *pop(struct sNode** top_ref)
    {
    struct tNode *res;
    struct sNode *top;


    if(isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

struct tNode* createNode(int data)
    {
    struct tNode* tNode = (struct tNode*)
                        malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;

    return(tNode);
    }

struct tnode* insert(struct tNode* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int main()
{

struct tNode *root = NULL;
int i,values,n,num=0;

    printf("enter root node value");
    scanf("%d",&i);
    printf("enter the no. of nodes you want in tree");
    scanf("%d",&n);

    root = insert(root, i);

    printf("enter the values of childrens");

   	while(num<n){
   		scanf("%d",&values);
   		insert(root, values);
   		num++;
	}

printf("preorder\n");
preOrder(root);
printf("\ninorder\n");
inOrder(root);


return 0;
}
