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
const int N=1e6+5;
const ll INF=1e18;
const int inf=0x3f3f3f3f;

int n,m,k;
int T;

void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%k==0)cout<<x/k<<sp;
    }
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