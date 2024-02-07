#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left, *right;
}node;

node *insert(node*, int);
void preorder(node*);
void postorder(node*);
void inorder(node*);
void delete(node*, int);

int main()
{
    node *root=NULL;
    int ch, Data;
    while(1)
    {
        printf("\nChoose an option: \n0.Exit \n1.Insert \n2.Preorder Traversal \n3.Postorder Traversal \n4.Inorder Traversal \n5.Delete");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Exiting.....");
                exit(0);
            case 1: printf("Enter data to insert: ");
                    scanf("%d", &Data);
                    root = insert(root, Data);
                    break;
            case 2: printf("Preorder Traversal -> ");
                    preorder(root);
                    break;
            case 3: printf("Postorder Traversal -> ");
                    postorder(root);
                    break;
            case 4: printf("Inorder Traversal -> ");
                    inorder(root);
                    break;
            /*case 5: printf("Enter data to be deleted: ");
                    scanf("%d",&data);
                    delete(root, data);
                    break;*/
            default: printf("Wrong Choice \n");
        }
    }
}

node *insert(node *root, int Data)
{
    if(root==NULL)
    {
        node *Newnode = (node*)malloc(sizeof(node));
        if(Newnode == NULL)
        {
            printf("Memory Allocation Failed");
            return root;
        }
        Newnode->data= Data;
        Newnode->left = Newnode->right = NULL;
        root = Newnode;
    }
    else if (Data < root->data)
        root->left = insert(root->left, Data);
    else if (Data>root->data)  
        root->right = insert(root->right, Data);
    else  
        printf("Duplicate Value not allowed");
    return root;
}

void preorder(node *root)
{
    if(root != NULL)
    {
        printf("%2d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%2d", root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%2d", root->data);
    }
}