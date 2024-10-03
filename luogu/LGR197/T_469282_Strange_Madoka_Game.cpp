#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,a[3],b[3],M;

void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){
	if(!b){d=a;x=1;y=0;}
	else{
		Exgcd(b,a%b,d,x,y);
		ll t=x;x=y;y=t-(a/b)*y;
	}
}

ll IntChina(){
	ll Ans=0,Mi,x,y,d;
	for(ll i=1;i<=n;++i){
		Mi=M/a[i];
		Exgcd(Mi,a[i],d,x,y);
		Ans=((Ans+Mi*x*b[i])%M+M)%M;
	}return (Ans+M)%M;
}

ll query(ll x) {
    cout << "? " << x << endl;
    ll res;
    cin >> res;
    return res;
}
void solve() {
    ll p = 4e8;
    ll res = query(p);
    ll res2 = query(p - 1);
    n = 2;
    b[1] = res;
    b[2] = res2;
    a[1] = p;
    a[2] = p - 1;
    M = p * (p - 1);
    cout << "! " << IntChina() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}