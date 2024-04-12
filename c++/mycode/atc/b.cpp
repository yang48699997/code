#include <bits/stdc++.h>

#define endl '\n'
using ll = long long;
using namespace std;


const int mod=998'244'353;
const int MOD=1e9+7;
const int N=1e6+5;
const ll INF=1e18;
const int inf=0x3f3f3f3f;
int gcd(int x,int y){
    while(y){
        int temp=y;
        y=x%y;
        x=temp;
    }
    return x;
}
void solve(){
    int n;
	vector<int> a(n);
    int tot=0;
    int res=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int y;
        cin>>y;
        if(res==-1)res=y;
        else res=gcd(res,y);
        tot+=a[i];
    }
    vector<bool> v(tot+1);
    for(int i=0;i<=tot;i++){
        if(i%res==0)v[i]=true;
    }
}   
	
int main(){
	ios::sync_with_stdio(false); 
	cin.tie(0);
    solve();
    cout<<endl;
	return 0;
}