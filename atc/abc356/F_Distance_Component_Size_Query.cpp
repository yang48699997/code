#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long;
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type, less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define endl '\n'
const ll inf = 3e18;
void solve(){
    int q;
    ll k;
    cin>>q>>k;
    ordered_set st1,st2;
    st1.insert(inf),st1.insert(-inf);
    st2.insert(inf),st2.insert(-inf);
    while(q--){
        int o;
        ll x;
        cin>>o>>x;
        if(o==1){
            if(st1.find(x)!=st1.end()){
                st1.erase(x);
                auto it = st1.lower_bound(x);
                ll nxt=*it;
                it--;
                ll pre=*it;
                if(nxt-x>k)st2.erase(x);
                if(nxt-pre>k)st2.insert(pre);
            }else{
                auto it = st1.lower_bound(x);
                ll nxt=*it;
                it--;
                ll pre=*it;
                st1.insert(x);
                if(nxt-x>k)st2.insert(x);
                if(x-pre<=k)st2.erase(pre);
            }
        }else{ 
            auto it=st2.lower_bound(x);
            ll nxt=*it;
            it--;
            ll pre=*it;
            int ans=st1.order_of_key(nxt)-st1.order_of_key(pre);
            cout<<ans<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}