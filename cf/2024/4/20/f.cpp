/*
 * Author: Ram
 * Date: 2024-04-20
 * Source: https://atcoder.jp/contests/abc350/tasks/abc350_f
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string s;
const int N=5e5+5;
int p[N];
void f(int l,int r,int op,int cnt){
    if(op==1){
        for(int i=l+1;i<r;i++){
            if(s[i]=='(')f(i,p[i],-1,cnt+1),i=p[i];
            else {
                if(cnt%2==0)cout<<s[i];
                else cout<<(char)(s[i]^32);
            }
        }
    }else{
        for(int i=r-1;i>l;i--){
            if(s[i]==')')f(p[i],i,1,cnt+1),i=p[i];
            else {
                if(cnt%2==0)cout<<s[i];
                else cout<<(char)(s[i]^32);
            }
        }
    }
}
void solve(){
    cin>>s;
    int n=s.length();
    stack<int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(')st.push(i);
        else if(s[i]==')'){
            int x=st.top();
            st.pop();
            p[x]=i;
            p[i]=x;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            f(i,p[i],-1,1);
            i=p[i];
        }else cout<<s[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}