#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string ss;
    cin>>ss;
    string s="!";
    for(int i=0;i<ss.length();i++){
        s+="#";
        s+=ss[i];
    }
    s+="#%";
    int n=s.length();
    vector<int> p(n);
    int c=0,r=0;
    for(int i=1;i<n-1;i++){
        int i_mir=2*c-i;
        if(r>i)p[i]=min(p[i_mir],r-i);
        while(s[i+1+p[i]]==s[i-1-p[i]])p[i]++;
        if(p[i]+i>r)r=p[i]+i,c=i;
    }
    int ans=0;
    for(int i=1;i<n-1;i++)ans=max(ans,p[i]);
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}