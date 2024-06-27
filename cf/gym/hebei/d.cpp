#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=505;
int dp1[N],dp2[N];
void solve(){
    string s;
    int m;
    cin>>s>>m;
    for(int i=0;i<=m;i++)dp1[i]=dp2[i]=0;
    int c1=0,c2=0,p1=0,p2=0;
    for(char ch:s){
        if(ch=='c')c2++;
        else p2++;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='c'){
            c2--;
            
        }else{
            p2--;

        }
    }
    cout<<max(dp1[m],dp2[m]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}