#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    char val;
    struct NODE* left;
    struct NODE* right;
}Node;
Node* InitTree(){
    Node* root=(Node*)malloc(sizeof(Node));    
    root->val=NULL;
    root->left=NULL;
    root->right=NULL;
    return root;
}
void InsertTree(Node* node){
    if(node==NULL) return;
    scanf("%c",&(node->val));
    if(node->val==' ') return;
    node->left=(Node*)malloc(sizeof(Node));
    node->right=(Node*)malloc(sizeof(Node));
    InsertTree(node->left);
    InsertTree(node->right);
}
void pre(Node* node){
    if(node==NULL) return;
    if(node->val==' ') return;
    printf("%c",node->val);
    pre(node->left);
    pre(node->right);
}
void mid(Node* node){
    if(node==NULL) return;
    if(node->val==' ') return;
    mid(node->left);
    printf("%c",node->val);
    mid(node->right);
}
void pos(Node* node){
    if(node==NULL) return;
    if(node->val==' ') return;
    pos(node->left);  
    pos(node->right);
    printf("%c",node->val);
}
int main(){
    Node* root=InitTree();
    InsertTree(root);
    pre(root);
    printf("\n");
    mid(root);
    printf("\n");
    pos(root);
    printf("\n");
    return 0;
}