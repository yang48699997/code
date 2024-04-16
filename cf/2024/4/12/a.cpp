/*
 * Author: Ram
 * Date: 2024-04-12
 * Source: https://codeforces.com/contest/1954/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int T;
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int i=0;
    for(i=0;i<n;i++){
        if(s1[i]!=s2[i])break;
    }
    if(i==n){
        cout<<s1<<endl<<s2;
        return;
    }
    if(s1[i]>s2[i]){
        for(int j=i+1;j<n;j++){
            if(s1[j]>s2[j])swap(s1[j],s2[j]);
        }
    }else{  
        for(int j=i+1;j<n;j++){
            if(s1[j]<s2[j])swap(s1[j],s2[j]);
        }
    }
    cout<<s1<<endl<<s2;
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