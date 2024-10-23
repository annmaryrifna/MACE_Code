#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *left, *right;
};
typedef struct Node node;
node *root = NULL, *ptr; 
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
void create(int n);
void create(int n) 
{
    int item;

    for(int i=0;i<n;i++)
    {
    printf("Enter the item: ");
    scanf("%d", &item);
    ptr = (node *)malloc(sizeof(node));
    ptr->data = item;
    ptr->left = ptr->right = NULL;
    if (root == NULL) 
    {
        root = ptr;
    } else
     {
        insert(root, ptr);
    }
}
}
void insert(node *r, node *p)
 {
    if (p->data < r->data) {
        if (r->left == NULL)
         {
            r->left = p;
        } else {
            insert(r->left, p);
        }
    } else {
        if (r->right == NULL)
         {
            r->right = p;
        }
         else 
        {
            insert(r->right, p);
        }
    }
}
void inorder(node *p)
 {
    if (p != NULL) 
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}
void preorder(node *p)
 {
    if (p != NULL) 
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(node *p)
 {
    if (p != NULL) 
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}
int main() 
{
    int ch;
    while(1)
     {
        printf("\n*** Binary Search Tree Operations ***\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                create();
                break;
            case 2:
                if (root == NULL) 
                {
                    printf("Tree is empty!\n");
                } 
                else 
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                 {
                    printf("Tree is empty!\n");
                }
                 else
                 {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) 
                {
                    printf("Tree is empty!\n");
                }
                 else
                 {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                 break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
