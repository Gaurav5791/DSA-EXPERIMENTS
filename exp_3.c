#include <stdio.h> 
#include <stdlib.h> 
typedef struct TreeNode { 
    int data; 
    struct TreeNode *leftChild; 
    struct TreeNode *rightChild; 
} TreeNode; 
TreeNode* createNode(int value) { 
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode)); 
    node->data = value; 
    node->leftChild = NULL; 
    node->rightChild = NULL; 
    return node; 
} 
void traverseInOrder(TreeNode* root) { 
    if (root) { 
        traverseInOrder(root->leftChild); 
        printf("%d ", root->data); 
        traverseInOrder(root->rightChild); 
    } 
} 
TreeNode* addNode(TreeNode* root, int value) { 
    if (!root)  
        return createNode(value); 
    if (value < root->data) 
        root->leftChild = addNode(root->leftChild, value); 
    else if (value > root->data) 
        root->rightChild = addNode(root->rightChild, value); 
    return root; 
} 
TreeNode* getMinNode(TreeNode* root) { 
    TreeNode* temp = root; 
    while (temp && temp->leftChild) 
        temp = temp->leftChild; 
    return temp; 
} 
TreeNode* removeNode(TreeNode* root, int value) { 
    if (!root) return NULL; 
 
    if (value < root->data) { 
        root->leftChild = removeNode(root->leftChild, value); 
    } 
    else if (value > root->data) { 
        root->rightChild = removeNode(root->rightChild, value); 
    } 
    else { 
        if (!root->leftChild) { 
            TreeNode* temp = root->rightChild; 
            free(root); 
            return temp; 
        } 
        else if (!root->rightChild) { 
            TreeNode* temp = root->leftChild; 
            free(root); 
            return temp; 
        } 
 
        TreeNode* successor = getMinNode(root->rightChild); 
        root->data = successor->data; 
        root->rightChild = removeNode(root->rightChild, successor->data); 
    } 
    return root; 
} 
int main() { 
    TreeNode* bstRoot = NULL; 
    int option, number; 
    while (1) { 
        printf("\n==== Binary Search Tree Menu ====\n"); 
        printf("1. Add element\n"); 
        printf("2. Remove element\n"); 
        printf("3. Show elements (Inorder)\n"); 
        printf("4. Quit\n"); 
        printf("Select an option: "); 
        scanf("%d", &option); 
        switch (option) { 
            case 1: 
                printf("Enter value to add: "); 
                scanf("%d", &number); 
                bstRoot = addNode(bstRoot, number); 
                printf("Value %d added.\n", number); 
                break; 
            case 2: 
                printf("Enter value to remove: "); 
                scanf("%d", &number); 
                bstRoot = removeNode(bstRoot, number); 
                printf("Value %d removed (if present).\n", number); 
                break; 
            case 3: 
                printf("BST (Inorder): "); 
                traverseInOrder(bstRoot); 
                printf("\n"); 
                break; 
            case 4: 
                printf("Goodbye!\n"); 
                return 0; 
            default: 
                printf("Invalid option, try again.\n"); 
} 
} 
    return 0; 
}