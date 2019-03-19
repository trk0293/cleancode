#include<stdio.h>
#include<stdlib.h>

#define max(x,y) ((x)>=(y))?(x):(y)

typedef struct BSTnode {
int data;
struct BSTnode* left;
struct BSTnode* right;
}node;

node* createNode(int data){
node* tmp = (node*)malloc(sizeof(node));
tmp->data = data;
tmp->left = NULL;
tmp->right = NULL;
return tmp;
}

int maxDepth(node* root){
if(root==NULL)return 0;
return max(maxDepth(root->left),maxDepth(root->right))+1;
}


//Driver program
int main(int argc,const char* argv[]){
node* root = createNode(10);
root->left = createNode(5);
root->right = createNode(15);
root->right->left =createNode(6);
root->right->right = createNode(20);
int depth = maxDepth(root);
printf("BST depth %d \n",depth);
return 0;
}
