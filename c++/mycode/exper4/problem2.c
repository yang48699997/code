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
void PrintTree(Node* node,int n){
    if(node==NULL) return;
    if(node->val==' ') return;
    PrintTree(node->right,n+1);
    for(int i=0;i<n;i++){
        printf("  ");
    }   
    printf("%c\n",node->val);
    PrintTree(node->left,n+1);
    return;
}
int main(){
    Node* root=InitTree();
    InsertTree(root);
    PrintTree(root,1);
    return 0;
}