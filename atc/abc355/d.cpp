#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type, less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    ordered_set st; 
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=i-st.order_of_key(make_pair(a[i].first,n-i));
        st.insert(make_pair(a[i].second,n-i));
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}