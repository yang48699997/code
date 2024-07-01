#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.length();
    for(int i=1;i<n;i++){
        for(int p=1;p<=i;p++){
            string res="";
            for(int j=p-1;j<n;j+=i)res+=s[j];
            if(res==t){
                cout<<"Yes";
                return;
            }
        }

    }
    cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}