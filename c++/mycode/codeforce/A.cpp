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
	int n,m,k;
	cin>>n>>m>>k;
	int a=1;
	vector<string> s(n);
	for(int i=0;i<n;i++)cin>>s[i];
	vector<pair<int,int>> p(k);
	vector<vector<int>> d(k,vector<int>(13));
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		p[i]={x,y};
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='.')continue;
			for(int l=0;l<k;l++){
				int dis=sqrt((i-p[l].first)*(i-p[l].first)+(j-p[l].second)*(j-p[l].second));
				if(dis*dis!=(i-p[l].first)*(i-p[l].first)+(j-p[l].second)*(j-p[l].second))dis++;
				if(dis<=12)d[l][dis]++;
			}
		}
	}
	for(int i=0;i<k;i++){
		for(int j=1;j<13;j++)d[i][j]+=d[i][j-1];
	}
	vector<vector<int>> dp(k+1,vector<int>(1<<12,0));
	vector<int> f(13);
	for(int i=1;i<13;i++)f[i]=3*f[i-1];
	
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