#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=1e6+5;

void solve(){
    vector<int> p(N);
    vector<int> v(N);
    int l=0;
    int cnt=0;
    for(int i=2;i<N;i++){
        if(!v[i]){
            cnt++;
            p[l++]=i;
        }
        for(int j=0;j<l&&p[j]*i<N;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }    
    cout<<cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}