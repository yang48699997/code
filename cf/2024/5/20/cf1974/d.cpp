/*
 * Author: Ram
 * Date: 2024-05-20
 * Source: https://codeforces.com/contest/1974/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for(auto c:s){
        if(c=='N')cnt1++;
        else if(c=='S')cnt2++;
        else if(c=='E')cnt3++;
        else cnt4++;
    }
    if(cnt1%2!=cnt2%2){
        cout<<"NO";
        return ;
    }
    if(cnt3%2!=cnt4%2){
        cout<<"NO";
        return ;
    }
    if(cnt1==1&&cnt2==1&&cnt3==1&&cnt4==1){
        for(auto c:s){
            if(c=='N'||c=='S')cout<<'R';
            else cout<<'H';
        }
        return;
    }
    if(cnt1<=1&&cnt2<=1&&cnt3<=1&&cnt4<=1){
        cout<<"NO";
        return;
    }
    cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for(auto c:s){
        if(c=='N'){
            if(cnt1%2)cout<<'R';
            else cout<<'H';
            cnt1++;
        }
        else if(c=='S'){
            if(cnt2%2)cout<<'R';
            else cout<<'H';
            cnt2++;
        }
        else if(c=='E'){
            if(cnt3%2)cout<<'R';
            else cout<<'H';
            cnt3++;
        }
        else {
            if(cnt4%2)cout<<'R';
            else cout<<'H';
            cnt4++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}