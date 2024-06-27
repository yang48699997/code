#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    string s;
    cin>>n>>s;
    string ans;
    stack<char> stk;
    for(int i=0;i<n;i++){
        if(!stk.empty()&&stk.top()=='n'&&s[i]=='a'){
            stk.push('y');
            stk.push('a');
        }else stk.push(s[i]);
    }
    while(!stk.empty())ans+=stk.top(),stk.pop();
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}