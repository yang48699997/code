/*
 * Author: Ram
 * Date: 2024-05-08
 * Source: https://codeforces.com/gym/105143/problem/I
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length();){
        if(s[i]=='0'){
            i++;
            continue;
        }
        ans++;
        int j=i+1;
        while(j<s.length()&&s[j]=='1')j++;
        i=j;
    }
    if(s.back()=='1')ans--;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}