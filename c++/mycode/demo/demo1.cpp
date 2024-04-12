#include<iostream>

using namespace std;

typedef struct NODE{
    int val;
    struct NODE* left;
    struct NODE* right;
}node;

node* initNode(){
    node *root=(node*)malloc(sizeof(node));
    root->val=-1;
    root->left=nullptr;
    root->right=nullptr;
    return root;
}
node* find(node* root,int _val){
    if(root==nullptr) return nullptr;
    if(root->val==_val) return root;
    else if(root->val>_val){
        return find(root->left,_val);
    }else{
        return find(root->right,_val);
    }
}

void printBST(node *root){
    if(root==nullptr) return;
    printBST(root->left);
    cout<<root->val<<" ";
    printBST(root->right);
    return ;
}

void insert(node *root,int _val){
    if(root==nullptr) return ;
    if(root->val==_val) return ;
    else if(root->val>_val){
        if(root->left==nullptr) {
            root->left=initNode();
            root->left->val=_val;
        }else{
            insert(root->left,_val);
        }
    }else{
        if(root->right==nullptr){
            root->right=initNode();
            root->right->val=_val;
        }else{
            insert(root->right,_val);
        }
    }
    return ;
}
int main(){
    int n;
    node *root=initNode();
    cout<<"请输入要插入的点的数目\n";
    cin>>n;
    if(n==0) return 0;
    cin>>root->val;
    n--;
    while(n){
        int val;
        cin>>val;
        insert(root,val);
        n--;
    }
    //查找
    cout<<"请输入要查找的元素"<<endl;
    int tar;
    cin>>tar;
    if(find(root,tar)){
        cout<<"已找到"<<tar<<endl;
    }else{
        cout<<"未找到"<<tar<<endl;
    }
    //遍历
    printBST(root);
    return 0;
}
