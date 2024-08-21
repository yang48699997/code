#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> l(n),r(n);
    int ans=0;
    vector<int> b;
    for(int i=0;i<n;i++){
        int cur = (i == 0 ? 0 : a[i-1] + 1); 
        auto it=lower_bound(b.begin(),b.end(),cur);
        l[i]=it - b.begin();
        auto it2 = lower_bound(b.begin() ,b.end() ,a[i]);
        if(it2==b.end())b.push_back(a[i]);
        else *it2=a[i];
    }
    b.clear();
    for(int i=n-1;i>=0;i--){
        int cur = (i == 0 ? 0 : a[i-1] +1);
        auto it = upper_bound(b.rbegin(),b.rend(),cur);
        r[i]=b.rend()-it;
        auto it2 = upper_bound(b.rbegin(),b.rend(),a[i]);
        if(it2==b.rbegin())b.push_back(a[i]);
        else {
            it2--;
            *it2=a[i];
        }
    }
    for(int i = 0;i<n;i++){
        ans=max(ans,l[i]+r[i]+1);
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