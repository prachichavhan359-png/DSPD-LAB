#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node *create(int val) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->right = newnode->left = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val) {
    if (root == NULL) {
        return create(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

void Inorder(struct node *root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

void Preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct node *root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key<root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct node* delete(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = delete(root->left, key);
    } else if (key > root->data) {
        root->right = delete(root->right, key);
    } else {
              if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
   } else {
            printf("Cannot delete %d it is not a leaf node.\n", key);
        }
    }
    return root;
}

int main() {
    int key, choice, val;
    struct node *root = NULL;

    while (1) {
        printf("\nChoose Operation\n");
        printf("1.Search\n2.Insert\n3.Delete Leaf\n4.Display\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("%d is Found!\n", key);
                else
                    printf("NOT FOUND!\n");
                break;

            case 2:
                printf("Enter Data For Node: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                break;

            case 4:
                printf("Inorder Traversal:\n");
                Inorder(root);
                printf("\nPreorder Traversal:\n");
                Preorder(root);
                printf("\nPostorder Traversal:\n");
                Postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting..\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
