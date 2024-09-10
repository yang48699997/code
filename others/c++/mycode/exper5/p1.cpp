#include<iostream>
#include<vector>

using namespace std;

int N;//顶点个数
int E;//边的条数
void dfs(vector<int> &e,vector<int> &h,vector<int> &nxt,vector<bool> visited,int root){
    if(visited[root]) return ;
    visited[root]=true; 
    cout<<root+1<<" ";
    int next=h[root];
    while(next!=-1){
        root=e[next];
        next=nxt[next];
        dfs(e,h,nxt,visited,root);
    }
    return;
}
void bfs(vector<int> &e,vector<int> &h,vector<int> &nxt,int root){
    vector<bool> visited(N,false);
    vector<int> cur_arr;
    vector<int> nxt_arr;
    cur_arr.push_back(root);
    while(!cur_arr.empty()){
        nxt_arr.clear();
        for(int i=0;i<cur_arr.size();i++){
            int temp=cur_arr[i];
            if(visited[temp]) continue;
            visited[temp]=true;
            cout<<temp+1<<" ";
            int next=h[temp];
            while(next!=-1){
                if(!visited[e[next]]){
                    nxt_arr.push_back(e[next]);
                }
                next=nxt[next];
            }
        }
        cur_arr=nxt_arr;
    }
    return ;
}
int main(){
    cout<<"请输入顶点的个数"<<"\n";
    cin>>N;
    cout<<"请输入边的条数"<<"\n";
    cin>>E;
    vector<int> e(2*E);
    vector<int> h(N,-1);
    vector<int> nxt(2*E);
    for(int i=0;i<E;i++){//邻接表存无向图
        int x,y;
        cin>>x>>y;//一条无向边的两端节点
        x--;
        y--;
        e[2*i]=y;
        e[2*i+1]=x;
        nxt[2*i]=h[x];
        nxt[2*i+1]=h[y];
        h[x]=2*i;
        h[y]=2*i+1;
    }
    cout<<"请输入起点坐标"<<"\n";
    int root;
    cin>>root;
    root--;//因为存的点其实是从0开始的，而题目要求的是从1开始
    vector<bool> visited(N,false);
    cout<<"深度优先搜索序列为:\n";
    dfs(e,h,nxt,visited,root);
    cout<<"\n广度优先搜索序列为:\n";
    bfs(e,h,nxt,root);

    return 0;
}

