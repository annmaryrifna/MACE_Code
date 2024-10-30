#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

typedef struct Node node;
node *root = NULL, *ptr;

void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
void create();
node* deleteNode(node*, int); 
node* findMin(node*);

void create()
 {
    int item, n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
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

node* findMin(node *r) {
    if (r == NULL) {
        return NULL;
    } else if (r->left != NULL) {
        return findMin(r->left);
    }
    return r;
}

node* deleteNode(node *r, int p) { 
    if (r == NULL) {
        return NULL;
    }
    if (p > r->data) {
        r->right = deleteNode(r->right, p);
    } else if (p < r->data) {
        r->left = deleteNode(r->left, p);
    } else {
        if (r->left == NULL && r->right == NULL) {
            free(r);
            return NULL;
        } else if (r->left == NULL || r->right == NULL) {
            node *temp = r->left ? r->left : r->right;
            free(r);
            return temp;
        } else {
            node *temp = findMin(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }
    }
    return r;
}

void insert(node *r, node *p) {
    if (p->data < r->data) {
        if (r->left == NULL) {
            r->left = p;
        } else {
            insert(r->left, p);
        }
    } else {
        if (r->right == NULL) {
            r->right = p;
        } else {
            insert(r->right, p);
        }
    }
}

void inorder(node *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

void preorder(node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

int main() {
    int ch, val;
    while(1) {
        printf("\n*** Binary Search Tree Operations ***\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Enter value to delete: ");
                    scanf("%d", &val);
                    root = deleteNode(root, val); 
                    printf("Node deleted\n");
                }
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
