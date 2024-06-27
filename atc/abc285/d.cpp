#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<string> s(n),t(n);
    map<string,int> in;
    map<string,vector<string>> nxt;
    for(int i=0;i<n;i++){
        cin>>s[i]>>t[i];
        in[t[i]]++;
        nxt[s[i]].push_back(t[i]);
    }
    queue<string> q;
    for(int i=0;i<n;i++){
        if(!in.count(s[i]))q.push(s[i]);
    }
    while(!q.empty()){
        for(auto& e:nxt[q.front()]){
            in[e]--;
            if(in[e]==0)q.push(e);
        }
        q.pop();
    }
    for(int i=0;i<n;i++){
        if(in[s[i]]!=0){
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}