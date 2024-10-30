#include <stdio.h>
#include <stdlib.h>
struct node {
    int item;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d -> ", root->item);
    inorder(root->right);
}
void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d -> ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->item);
}
void insertNode(struct node** root, int value) {
    struct node* newNode = createNode(value);
    
    if (*root == NULL) {
        *root = newNode;
        printf("Inserted %d as root node.\n", value);
        return;
    }
    
    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    
    while (front < rear) {
        struct node* current = queue[front++];
        
        if (current->left == NULL) {
            current->left = newNode;
            printf("Inserted %d to the left of %d.\n", value, current->item);
            return;
        } else {
            queue[rear++] = current->left;
        }
        
        if (current->right == NULL) {
            current->right = newNode;
            printf("Inserted %d to the right of %d.\n", value, current->item);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}
struct node* findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
struct node* deleteNode(struct node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (value < root->item) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->item) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node found with the matching value
        
        // Case 1: No child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        
        // Case 2: One child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 3: Two children
        struct node* temp = findMin(root->right);
        root->item = temp->item;
        root->right = deleteNode(root->right, temp->item);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertNode(&root, value);
                break;

            case 2:
                printf("Inorder Traversal:\n");
                inorder(root);
                printf("NULL\n");
                break;

            case 3:
                printf("Preorder Traversal:\n");
                preorder(root);
                printf("NULL\n");
                break;

            case 4:
                printf("Postorder Traversal:\n");
                postorder(root);
                printf("NULL\n");
                break;

            case 5:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Node with value %d deleted if it existed.\n", value);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
