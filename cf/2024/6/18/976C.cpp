#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
        a[i]=i;
    }
    sort(a.begin(),a.end(),[&](int x,int y){
        if(p[x].first!=p[y].first)return p[x].first<p[y].first;
        return p[x].second>p[y].second;
    });
    int pre=a[0];
    for(int i=1;i<n;i++){
        int cur=a[i];
        if(p[cur].second<=p[pre].second){
            cout<<cur+1<<' '<<pre+1;
            return;
        }
        pre=cur;
    }
    cout<<"-1 -1";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}