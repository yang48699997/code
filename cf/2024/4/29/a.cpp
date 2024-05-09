/*
 * Author: Ram
 * Date: 2024-04-29
 * Source: https://codeforces.com/contest/1937/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
int T;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> l,r;
    // l.push_back(-1);
    // r.push_back(n);
    for(int i=0;i<n;i++){
        if(s[i]=='<')r.push_back(i);
        else l.push_back(i);
    }
    vector<ll> pre1(n+1),pre2(n+1);
    for(int i=1;i<=n;i++){
        char c=s[i-1];
        pre1[i]=pre1[i-1];
        pre2[i]=pre2[i-1];
        if(c=='<')pre2[i]+=i;
        else pre1[i]+=i;
    }
    for(int i=0;i<n;i++){
        char c=s[i];
        ll ans=0;
        if(c=='<'){
            auto it1=upper_bound(l.begin(),l.end(),i);
            auto it2=lower_bound(r.begin(),r.end(),i);
            int m=it1-l.begin();
            int mm=r.end()-it2;
            if(m<mm){
                ans+=pre2[*(it2+m)+1]-pre2[i]-pre1[i];
                ans+=pre2[*(it2+m)+1]-pre2[i+1]-pre1[i];
            }else{
                ans+=pre2[n]+pre1[*(it1-mm)]-pre1[i]-pre2[i];
                ans+=pre2[n]+n+1+pre1[*(it1-mm)]-pre2[i+1]-pre1[i];
            }
        }else{
            auto it1=upper_bound(l.begin(),l.end(),i);
            auto it2=lower_bound(r.begin(),r.end(),i);
            int m=it1-l.begin();
            int mm=r.end()-it2;
            if(m>mm){
                ans+=pre2[n]+n+1+pre1[*(it1-mm-1)]-pre1[i+1]-pre2[i+1];
                ans+=pre2[n]+pre1[*(it1-mm-1)]-pre1[i]-pre2[i];
            }else{
                ans+=pre2[*(it2+m-1)+1]-pre2[i]-pre1[i+1];
                ans+=pre2[*(it2+m-1)+1]-pre2[i]-pre1[i];
            }
        }
        cout<<ans<<' ';
    }
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