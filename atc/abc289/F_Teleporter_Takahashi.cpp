#include <bits/stdc++.h>
using namespace std;

#define endl '\n'   

vector<vector<int>> ans;
void dfs(int x,int a,int p){
    if((x-a)%2){
        ans[p].push_back(a+1);
        int cur=a+1;
        int nxt=0;
        while(cur!=x){
            ans[p].push_back(a+nxt);
            cur=2*(a+nxt)-cur;
            nxt^=1;
        }
    }else{
        ans[p].push_back(a);
        int cur=a;
        int nxt=1;
        while(cur!=x){
            ans[p].push_back(a+nxt);
            cur=2*(a+nxt)-cur;
            nxt^=1;
        }
    }
}
void solve(){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((ty-sy)%2||(tx-sx)%2){
        cout<<"No";
        return ;
    }    
    if(a==b&&(sx+tx!=2*a&&sx!=tx)){
        cout<<"No";
        return;
    }
    if(c==d&&(sy+ty!=2*c&&sy!=ty)){
        cout<<"No";
        return;
    }
    if(a==b&&c==d){
        if(sx==tx&&sy==ty){
            cout<<"Yes";
            return;
        }else if(sx!=tx&&sy!=ty){
            cout<<"Yes\n";
            cout<<a<<' '<<c;
            return;
        }else if(sx==tx&&a==sx){
            cout<<"Yes\n";
            cout<<a<<' '<<c;
        }else if(sy==ty&&c==ty){
            cout<<"Yes\n";
            cout<<a<<' '<<c;
        }else  cout<<"No";
        return;
    }
    cout<<"Yes\n";
    ans.clear();
    ans.resize(2);
    int p0,p1;
    if(a!=b){
        dfs(sx,a,0);
        p0=ans[0].size()-1;
        reverse(ans[0].begin(),ans[0].end());    
        dfs(tx,a,0);
    }else{
        ans[0].push_back(a);
        if(sx==tx){
            ans[0].push_back(a);
        }
    }
    if(c!=d){
        dfs(sy,c,1);
        reverse(ans[1].begin(),ans[1].end());    
        p1=ans[1].size()-1;
        dfs(ty,c,1);
    }else{
        ans[1].push_back(c);
        if(sy==ty){
            ans[1].push_back(c);
        }
    }
    if(a==b){
        while(ans[0].size()<ans[1].size()){
            ans[0].push_back(a);
            ans[0].push_back(a);
        }
    }else if(c==d){
        while(ans[1].size()<ans[0].size()){
            ans[1].push_back(c);
            ans[1].push_back(c);
        }

    }
    if(ans[0].size()<=ans[1].size()){
        int dif=ans[1].size()-ans[0].size();
        int nxt=0;
        if((sx-a)%2)nxt=1;
        int j=0;
        for(int i=0;i<ans[0].size();i++){
            cout<<ans[0][i]<<' '<<ans[1][i+j]<<'\n';
            if(i==p0){
                for(;j<dif;j++){
                    cout<<ans[0][i]<<' '<<ans[1][i+j+1]<<'\n';
                }
            }
        }
    }else{
        int dif=ans[0].size()-ans[1].size();
        int nxt=0;
        if((sy-c)%2)nxt=1;
        int j=0;
        for(int i=0;i<ans[1].size();i++){
            cout<<ans[0][i+j]<<' '<<ans[1][i]<<'\n';
            if(i==p1){
                for(;j<dif;j++){
                    cout<<ans[0][i+j+1]<<' '<<ans[1][i]<<'\n';
                }
            }
        }
    }
    // cerr<<max(ans[0].size(),ans[1].size());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}