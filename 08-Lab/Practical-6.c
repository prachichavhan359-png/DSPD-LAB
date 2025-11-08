#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if(root == NULL) return createNode(value);
    if(value < root->data) root->left = insert(root->left, value);
    else if(value > root->data) root->right = insert(root->right, value);
    return root;
}

void search(struct Node* root, int key) {
    if(root == NULL) {
        printf("NULL\n");
        return;
    }
    if(root->data == key) {
        printf("Found\n");
        return;
    }
    if(key < root->data) search(root->left, key);
    else search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if(root == NULL) return NULL;
    if(root->data == key) {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else {
            printf("Not a leaf node\n");
            return root;
        }
    }
    if(key < root->data) root->left = deleteLeaf(root->left, key);
    else root->right = deleteLeaf(root->right, key);
    return root;
}

void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    while(1) {
        printf("\n1.Search\n2.Insert\n3.Delete leaf\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("BST Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("BST Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
