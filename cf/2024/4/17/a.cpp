#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=4e5+5;
int a[N];
int n;
bool check(){
    for(int i=1;i<=n;i++){
        if(a[i]<a[i-1])return false;
    }
    return true;
}
void f1(){
    for(int i=1;i<=n;i+=2){
        if(a[i-1]>a[i])swap(a[i-1],a[i]);
    }
}
void f2(){
    for(int i=2;i<=n;i+=2){
        if(a[i-1]>a[i])swap(a[i-1],a[i]);
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<=n;i++)cin>>a[i];
    int cnt=0;
    while(!check()){
        cnt++;
        if(cnt%2==1)f1();
        else f2();
    }
    cout<<cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}