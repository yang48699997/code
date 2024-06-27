/*
 * Author: Ram
 * Date: 2024-05-18
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
#define endl '\n'
vector<int> e[N];
int a[N],ans;

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)e[i].clear(),cin>>a[i];
    ans=0;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end(),[&](int x,int y){
            return a[x]>a[y];
        });
    }
    int xx,yy,zz,q,z;
    for(int i=1;i<=n;i++){
        for(int x=0;x<e[i].size();x++){
            for(int y=x;y<e[i].size();y++){
                xx=e[i][x],yy=e[i][y];
                int res=a[i]+a[xx]+a[yy];
                if(xx==yy)res-=a[xx];
                zz=-1;
                for(int j=0;j<e[e[i][x]].size();j++){
                    z=e[e[i][x]][j];
                    if(z!=i&&z!=xx&&z!=yy){
                        zz=z;
                        res+=a[z];
                        break;
                    }
                }
                for(int j=0;j<e[e[i][y]].size();j++){
                    z=e[e[i][y]][j];
                    if(z!=i&&z!=xx&&z!=yy&&z!=zz){
                        res+=a[z];
                        break;
                    }
                }
                ans=max(ans,res);
            }
        }
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}