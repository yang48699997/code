#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MOD=998'244'353;
const int N=2e5+5;

int n,m,k;
int T;
/* 
	逆元求法(要求mod必须是质数)
	时间复杂度：O(n)


	1）首先通过循环计算出所有小于 N 的阶乘（对 p 取模）的结果，并存储在数组 fac[] 中（fac[i] = i! % p）。
	2）求解 m! 对 p 取模的逆元（即求 fac[m] 的逆元）。根据费马小定理，x 对 p 的逆元为 x^(p-2)。通过快速幂算法，求解 fac[m]^(p-2) % p，记为 M。
	3）求解 (n-m)! 对 p 取模的逆元：同上，即求解 fac[n-m]^(p-2) % p。
	4）利用逆元计算组合数，即：C(n,m) % p = ((fac[n] * M) % p * N) % p。
 */
ll fac[N];
void init(){
	fac[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%MOD;
	}
}
int powMod(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}
int inv(int x){
	return powMod(x,MOD-2);
}
int cal(int x,int y){
	return fac[x]*inv(fac[y])%MOD*inv(fac[x-y])%MOD;
}
void solve(){
	init();
	cin>>n>>m;
	cout<<cal(n,m);
}
	
int main(){
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cin >> T;
	while(T--){
		solve();
		cout<<endl;
	}
	return 0;
}