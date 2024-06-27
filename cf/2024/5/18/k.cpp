/*
 * Author: Ram
 * Date: 2024-05-18
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
set<int> res;
int fa[5],num[5];
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return ;
    num[x]*=num[y];
    fa[y]=x;
}
void get(vector<int> a,vector<int> op){
    sort(a.begin(),a.end());
    do{
        do{ 
            int ans=0;
            int ok1=-1,ok2=-1;
            for(int i=0;i<4;i++)fa[i]=i,num[i]=a[i];
            for(int i=0;i<3;i++){
                if(op[i]==0){
                    merge(i,i+1);
                }
            }
            ans+=num[find(0)];
            for(int i=0;i<3;i++){
                if(op[i]==1){
                    ans+=num[find(i+1)];
                }
                if(op[i]==2){
                    ans-=num[find(i+1)];
                }
            }
            res.insert(ans);
        }while(next_permutation(op.begin(),op.end()));
    }while(next_permutation(a.begin(),a.end()));
}
void solve(){
    vector<int> a(4);
    for(int i=0;i<4;i++)cin>>a[i];
    res.clear();
    vector<vector<int>> op;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                vector<int> now(3);
                now[0]=i;
                now[1]=j;
                now[2]=k;
                op.push_back(now);
            }
        }
    }
    for(int i=0;i<op.size();i++){
        get(a,op[i]);
    }
    cout<<res.size();
    // cout<<cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}