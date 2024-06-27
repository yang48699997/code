/*
 * Author: Ram
 * Date: 2024-05-14
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    string s;
    cin>>n;
    int ans=0;
    while(n--){
        cin>>s;
        if(s.length()!=5)continue;
        if(s[2]!=s[4])continue;
        set<char> st;
        for(int i=0;i<4;i++){
            if(st.count(s[i])){
                ans--;
                break;
            }
            st.insert(s[i]);
        }
        ans++;
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