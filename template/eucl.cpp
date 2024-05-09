#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct triple{
    ll d,a,b;
};
triple eucl(ll x,ll y){
    if(y==0)return {x,1,0};
    ll k=x/y;
    auto [d,a,b]=eucl(y,x-k*y);
    return {d,b,a-k*b};
}