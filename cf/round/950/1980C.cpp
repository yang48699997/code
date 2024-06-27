#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int m;
    cin>>m;
    map<int,int> mp;
    set<int> st;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])mp[b[i]]++;
        st.insert(b[i]);
    }
    int x;
    int cnt=0;
    while(m--){
        cin>>x;
        if(mp.count(x)){
            mp[x]--;
            if(mp[x]==0)mp.erase(x);
        }else if(!st.count(x)){
            cnt=max(0,cnt);
            if(!mp.size())cnt=1;
        }else cnt--;
    }   
    if(mp.size()==0&&cnt<=0)cout<<"YES";
    else cout<<"NO";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}