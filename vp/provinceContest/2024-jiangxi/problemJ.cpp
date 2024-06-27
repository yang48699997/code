#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
string t[6]={"1s","9s","1p","9p","1m","9m"};
void solve(){
    string s;
    cin>>s;
    map<string,int> cnt;
    for(int i=0;i<28;i+=2){
        cnt[s.substr(i,2)]++;
        // cerr<<s.substr(i,2)<<" \n"[i==26];
    }
    bool ok1=true;
    for(int i=0;i<6;i++){
        if(cnt[t[i]]==0){
            ok1=false;
            break;
        }
    }
    for(int i=1;i<=7;i++){
        string cur=to_string(i)+"z";
        if(cnt[cur]==0){
            ok1=false;
            break;
        }
    }
    if(ok1){
        cout<<"Thirteen Orphans";
        return;
    }
    bool ok2=true;
    for(int i=0;i<28;i+=2){
        if(cnt[s.substr(i,2)]!=2){
            ok2=false;
            break;
        }
    }
    if(ok2)cout<<"7 Pairs";
    else cout<<"Otherwise";
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