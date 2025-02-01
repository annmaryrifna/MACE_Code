#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
struct node *root = NULL; 
 
// Function to create a new node 
struct node *create_node(int item) 
{ 
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); 
    ptr->data = item; 
    ptr->left = NULL; 
    ptr->right = NULL; 
    return ptr; 
} 
struct node *insert_node(struct node *root, int item) 
{ 
    if (root == NULL) 
    { 
        printf("Node inserted: %d\n", item); 
        return create_node(item); 
    } 
    else if (item < root->data) 
    { 
        root->left = insert_node(root->left, item); 
    } 
    else 
    { 
        root->right = insert_node(root->right, item); 
    } 
    return root; 
} 
 
// Function to find the node with the smallest value in the BST 
struct node *find_min(struct node *root) 
{ 
    while (root->left != NULL) 
    { 
        root = root->left; 
    } 
    return root; 
} 
struct node *find_max(struct node *root) 
{ 
 
 
    while (root->right != NULL) 
    { 
        root = root->right; 
    } 
    return root; 
} 
// Function to delete a node from the BST 
struct node *delete_node(struct node *root, int item) 
{ 
    if (root == NULL) 
    { 
        printf("Node not found: %d\n", item); 
        return root; 
    } 
    if (item < root->data) 
    { 
        root->left = delete_node(root->left, item); 
    } 
    else if (item > root->data) 
    { 
        root->right = delete_node(root->right, item); 
    } 
    else 
    { 
        // Node with one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            printf("Node deleted: %d\n", item); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            printf("Node deleted: %d\n", item); 
            return temp; 
        } 
 
        // Node with two children 
        struct node *temp = find_min(root->right); 
        root->data = temp->data; 
        root->right = delete_node(root->right, temp->data); 
    } 
 
 
    return root; 
} 
 
// Function to perform in-order traversal of the BST 
void inorder_traversal(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder_traversal(root->left); 
        printf("%d ", root->data); 
        inorder_traversal(root->right); 
    } 
} 
 
// Function to perform pre-order traversal of the BST 
void preorder_traversal(struct node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d ", root->data); 
        preorder_traversal(root->left); 
        preorder_traversal(root->right); 
    } 
} 
 
// Function to perform post-order traversal of the BST 
void postorder_traversal(struct node *root) 
{ 
    if (root != NULL) 
    { 
        postorder_traversal(root->left); 
        postorder_traversal(root->right); 
        printf("%d ", root->data); 
    } 
} 
 
// Function to count the number of nodes in the BST 
int count_nodes(struct node *root) 
{ 
    if (root == NULL) 
    { 
        return 0; 
    } 
    return 1 + count_nodes(root->left) + count_nodes(root->right); 
} 
 
 
 
// Main function 
 
int main() 
{ 
    int choice, item; 
    while (1) 
    { 
        printf("\n1. Insert\n2. Delete\n3. In-order Traversal\n4. Pre-order 
Traversal\n5. Post-order Traversal\n6. Count Nodes\n7. Find Minimum and Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
        case 1: 
            printf("Enter the item to insert: "); 
            scanf("%d", &item); 
            root = insert_node(root, item); 
            break; 
        case 2: 
            printf("Enter the item to delete: "); 
            scanf("%d", &item); 
            root = delete_node(root, item); 
            break; 
        case 3: 
            printf("In-order Traversal of BST: "); 
            inorder_traversal(root); 
            printf("\n"); 
            break; 
        case 4: 
            printf("Pre-order Traversal of BST: "); 
            preorder_traversal(root); 
            printf("\n"); 
            break; 
        case 5: 
            printf("Post-order Traversal of BST: "); 
            postorder_traversal(root); 
            printf("\n"); 
            break; 
        case 6: 
            printf("Number of nodes in BST: %d\n", count_nodes(root)); 
            break; 
        case 7: 
            if (root == NULL) 
            { 
 
 
                printf("The tree is empty.\n"); 
            } 
            else 
            { 
                struct node *temp = find_min(root); 
                printf("Minimum value in BST: %d\n", temp->data); 
            } 
            break; 
        case 8: 
            if (root == NULL) 
            { 
                printf("The tree is empty.\n"); 
            } 
            else 
            { 
                struct node *temp = find_max(root); 
                printf("Maximum value in BST: %d\n", temp->data); 
            } 
            break; 
        case 9: 
            exit(0); 
            break; 
        default: 
            printf("Invalid choice! Try again.\n"); 
        } 
    } 
    return 0; 
} 
 
