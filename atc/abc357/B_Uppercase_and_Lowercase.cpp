#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s;
    cin>>s;
    int cnt1=0,cnt2=0;
    for(char c:s){
        if(c>='a'&&c<='z')cnt1++;
        else cnt2++;
    }
    if(cnt1>cnt2){
        for(char c:s){
            if(c>='a'&&c<='z');
            else c^=32;
            cout<<c;
        }
    }else{
        for(char c:s){
            if(c>='a'&&c<='z')c^=32;
            cout<<c;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}