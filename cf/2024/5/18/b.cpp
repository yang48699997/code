/*
 * Author: Ram
 * Date: 2024-05-18
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s;
    cin>>s;
    string ans;
    stack<char> stk;
    vector<char> d(3);
    for(int i=0;i<s.length();i++){
        stk.push(s[i]);
        int cnt=0;
        if(stk.size()<3)continue;
        for(int j=0;j<3;j++){
            d[j]=stk.top();
            stk.pop();
            if(d[j]==s[i])cnt++;
        }
        if(cnt!=3){
            for(int j=2;j>=0;j--)stk.push(d[j]);
        }
    }
    if(stk.size()==0){
        cout<<"NAN";
        return;
    }
    while(stk.size()>0){
        ans+=stk.top();
        stk.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}