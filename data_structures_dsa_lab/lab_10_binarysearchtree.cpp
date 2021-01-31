#include<stdio.h>
#include<stdlib.h>

struct bst{
	int data;
	struct bst *left, *right;
};

struct bst *newnode(int value)
{
	struct bst *nn = (struct bst *)malloc(sizeof(struct bst));
	nn->data=value;
	nn->left = nn->right = NULL;
	return nn;
}

void inorder(struct bst *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

struct bst *insert(struct bst *node1,int data)
{
	if(node1==NULL)
	return newnode(data);

	else if(data < node1->data)
	node1->left = insert(node1->left,data);

	else
	node1->right = insert(node1->right,data);

	return node1;
}

int min(struct bst *root){
	struct bst *cptr = root;  //(struct bst*) malloc (sizeof(struct bst));
	while(cptr->left!=NULL){
		cptr=cptr->left;
	}
	return cptr->data;
}

int main()
{
    int x,n,i;
	struct bst *root = NULL;
	printf("enter root node data");
	scanf("%d",&x);
	root = insert(root,x);
	printf("number of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++){
            scanf("%d",&x);
            insert(root,x);
	}
    printf("inorder traversal is\n");
	inorder(root);
	printf("\nmin valuer is %d",min(root));

	return 0;
}
