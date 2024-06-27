/*
 * Author: Ram
 * Date: 2024-05-15
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define endl '\n'
int a[N],b[N];
int n;
bool check(int x){
    map<int,int> mp1,mp2;
    for(int i=0;i<n;i++){
        if(b[i]==1){
            if(mp1.size()==0){
                mp2[a[i]]++;
            }else{
                auto it=mp1.lower_bound(x-a[i]);
                if(it==mp1.end())return false;
                int cur=it->first;
                mp1[cur]--;
                if(mp1[cur]==0)mp1.erase(it);
            }
        }else{
            if(mp2.size()==0){
                mp1[a[i]]++;
            }else{
                auto it=mp2.lower_bound(x-a[i]);
                if(it==mp2.end())return false;
                int cur=it->first;
                mp2[cur]--;
                if(mp2[cur]==0)mp2.erase(it);
            }
        }
    }
    return true;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int l=1,r=2e9+5;
    while(l<=r){
        int mid=(r-l)/2+l;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}