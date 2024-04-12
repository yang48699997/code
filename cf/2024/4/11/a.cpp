/*
 * Author: Ram
 * Date: 2024-04-11
 * Source: https://codeforces.com/problemset/problem/296/B
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    ll ans=1;
    for(int i=0;i<n;i++){
      if(s1[i]=='?'){
         if(s2[i]=='?')ans=ans*100%mod;
         else ans=ans*10%mod;
      }else if(s2[i]=='?'){
         ans=ans*10%mod;
      }
    }
   ll res1=1,res2=1,res3=1;
   for(int i=0;i<n;i++){
      if(s1[i]=='?'){
         if(s2[i]=='?'){
            res1=res1*55%mod;
            res2=res2*55%mod;
            res3=res3*10%mod;
         }else{
            int cur=s2[i]-'0';
            res1=res1*(9-cur+1)%mod;
            res2=res2*(cur+1)%mod;
         }
      }else if(s2[i]=='?'){
         int cur=s1[i]-'0';
         res2=res2*(9-cur+1)%mod;
         res1=res1*(cur+1)%mod;
      }else{
         int x1=s1[i]-'0';
         int x2=s2[i]-'0';
         if(x1>x2){
            res2=res3=0;
         }else if(x1<x2){
            res1=res3=0;
         }
      }
   }
   ans=(ans-res1-res2+res3)%mod;
   if(ans<0)ans+=mod;
   cout<<ans;
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}