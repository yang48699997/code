#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    set<char> dig,let;
    for(int i=0;i<10;i++){
        dig.insert('0'+i);
    }
    for(int i=0;i<26;i++){
        let.insert('a'+i);
    }
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(!dig.count(ch)&&!let.count(ch)){
            cout<<"NO";
            return;
        }
        if(i>0&&s[i]<s[i-1]){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
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