#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define sp ' '
#define yes "YES"
#define no "NO"
using ll = long long;
using namespace std;
using ull = unsigned long long;
// using namespace __gnu_pbds;
// typedef tree<int,null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mod=998'244'353;
const int MOD=1e9+7;
const int N=1e5+5;
const ll INF=1e18;
const int inf=0x3f3f3f3f;

int T;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=1;
	vector<bool> v(n+1);
	for(int i=2;i<=n;i++){
		for(int j=0;j<n;j++)v[j]=false;
		bool cur=false;
		for(int j=0;j<n-i+1;j++){
			bool k=false;
			if(s[j]=='1')k=true;
			if(v[j])cur=!cur;
			if(cur)k=!k;
			if(!k){
				v[j+1]=!v[j+1];
				v[j+i]=!v[j+i];
			}
		}
		bool ok=true;
		for(int j=n-i+1;j<n;j++){
			bool k=(s[j]=='1');
			if(v[j])cur=!cur;
			if(cur)k=!k;
			if(!k){
				ok=false;
				break;
			}
		}
		if(ok)ans=i;
	}
	cout<<ans;
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