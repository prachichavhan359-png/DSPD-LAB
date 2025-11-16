#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* left;
struct node* right;
};

void Inorder(struct node* t){
if(t!=NULL){
Inorder(t->left);
printf("%d,",t->data);
Inorder(t->right);
}

}
void Postorder(struct node* t){
if(t!=NULL){
Postorder(t->left);
Postorder(t->right);
printf("%d,",t->data);
}
}
void Preorder(struct node* t){
if(t!=NULL){
printf("%d,",t->data);
Preorder(t->left);
Preorder(t->right);
}

}
struct node* createNode(){

int n;

printf("Enter Element Of Node\n");
scanf("%d",&n);

struct node* newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = n;
if(n==0)
return 0;
printf("Enter Data For Left of %d Node\n",n);
    newnode->left = createNode();
printf("Enter Data For Right of %d Node\n",n);
newnode->right=createNode();
 
return newnode;
}

int main(){
struct node* root;
root= createNode();

printf("Inorder Traversal\n");
Inorder(root);
printf("Preorder Traversal\n");
Preorder(root);
printf("Postorder Traversal\n");
Postorder(root);
printf("\n program end");
return 0;

}