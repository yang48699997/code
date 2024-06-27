#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct sgt{
    int n;
    vector<int> tre;
    vector<int> a;
    sgt(int n){
        this->n=n;
        tre.resize(n*4+5);
        a.resize(n+1);
    }
    void build(int p,int l,int r){
        if(l==r){
            tre[p]=a[l];
            return ;
        }
        int mid=(r+l)/2;
        build(p*2,l,mid);
        build(p*2+1,mid+1,r);
        tre[p]=tre[p*2]+tre[p*2+1];
    }
    void update(int p,int tar,int val,int l,int r){
        if(l==r){
            tre[p]=val;
            return ;
        }
        int mid=(l+r)/2;
        if(tar<=mid){
            update(p*2,tar,val,l,mid);
        }else{
            update(p*2+1,tar,val,mid+1,r);
        }
        tre[p]=tre[p*2]+tre[p*2+1];
    }
    int query(int p,int tl,int tr,int l,int r){
        if(tl<=l&&tr>=r){
            return tre[p];
        }
        int mid=(l+r)/2;
        int res=0;
        if(mid>=tl){
            res+=query(p*2,tl,tr,l,mid);
        }
        if(mid<tr){
            res+=query(p*2+1,tl,tr,mid+1,r);
        }
        return res;
    }
};

void solve(){
    int n,q;
    string s;
    cin>>n>>s>>q;
    vector<sgt> t(26,n);
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            if(s[j]-'a'==i)t[i].a[j+1]++;
        }
        t[i].build(1,1,n);
    }
    int c,l,r,x;
    char ch;
    vector<int> cnt(26);
    for(int i=0;i<n;i++)cnt[s[i]-'a']++;
    vector<int> now(26);
    while(q--){
        cin>>c;
        if(c==1){
            cin>>x>>ch;
            t[s[x-1]-'a'].update(1,x,0,1,n);
            cnt[s[x-1]-'a']--;
            s[x-1]=ch;
            t[s[x-1]-'a'].update(1,x,1,1,n);
            cnt[s[x-1]-'a']++;
        }else{
            cin>>l>>r;
            int nl=l,nr=r;
            for(int i=0;i<26;i++){
                now[i]=t[i].query(1,l,r,1,n);
            }
            for(int i=0;i<26;i++){
                if(now[i]!=0){
                    l=i;
                    break;
                }
            }
            for(int i=25;i>=0;i--){
                if(now[i]!=0){
                    r=i;
                    break;
                }
            }
            bool ok=true;
            for(int i=l+1;i<r;i++){
                if(now[i]!=cnt[i]){
                    ok=false;
                    break;
                }
            }
            if(!ok){
                cout<<"No"<<endl;
                continue;
            }
            for(int i=l;i<=r;i++){
                if(now[i]==0)continue;
                if(t[i].query(1,nl,nl+now[i]-1,1,n)!=now[i]){
                    ok=false;
                    break;
                }else nl+=now[i];
            }
            if(ok)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
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