#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=-1)b.push_back(i);
    }
    vector<int> ans(n);
    for(int i=0;i+1<b.size();i++){
        ans[b[i]]=a[b[i]];
        ans[b[i+1]]=a[b[i+1]];
        int l=b[i];
        int r=b[i+1];
        if(a[l]<=a[r]){
            int cnt1=0;
            for(int j=0;(1<<j)<=a[l];j++){
                cnt1=j;
            }
            int cnt2=0;
            for(int j=0;(1<<j)<=a[r];j++){
                cnt2=j;
            }
            int res=0;
            for(int j=0;j<=cnt1;j++){
                if((a[l]>>j)==(a[r]>>(cnt2-cnt1+j))){
                    res=j;
                    break;
                }
            }
            int op=res*2+cnt2-cnt1;
            // cout<<"*"<<op<<endl;
            if(op>r-l||(r-l-op)%2){
                cout<<-1;
                return;
            }
            for(int j=0;j<res;j++)ans[l+j+1]=ans[l+j]>>1;
            for(int j=0;j<res+cnt2-cnt1;j++)ans[l+res+j]=a[r]>>(res+cnt2-cnt1-j);
            if(op==0){
                for(int j=l;j<r;j+=2){
                    ans[j+1]=ans[j]<<1;
                    ans[j+2]=ans[j];
                }
                continue;
            }
            for(int j=l+2*res+cnt2-cnt1;j<r;j+=2){
                ans[j]=ans[j-1]<<1;
                ans[j+1]=ans[j-1];
            }
        }else{
            swap(l,r);
            int cnt1=0;
            for(int j=0;(1<<j)<=a[l];j++){
                cnt1=j;
            }
            int cnt2=0;
            for(int j=0;(1<<j)<=a[r];j++){
                cnt2=j;
            }
            int res=0;
            for(int j=0;j<=cnt1;j++){
                if((a[l]>>j)==(a[r]>>(cnt2-cnt1+j))){
                    res=j;
                    break;
                }
            }
            int op=res*2+cnt2-cnt1;
            if(op>l-r||(l-r-op)%2){
                cout<<-1;
                return;
            }
            for(int j=0;j<res;j++)ans[l-j-1]=ans[l-j]>>1;
            for(int j=0;j<res+cnt2-cnt1;j++)ans[l-res-j]=a[r]>>(res+cnt2-cnt1-j);
            if(op==0){
                for(int j=l;j>r;j-=2){
                    ans[j-1]=ans[j]<<1;
                    ans[j-2]=ans[j];
                }
                continue;
            }
            for(int j=l-2*res-cnt2+cnt1;j>r;j-=2){
                ans[j]=ans[j+1]<<1;
                ans[j-1]=ans[j+1];
            }
        }
    }
    if(b.size()==0){
        for(int i=0;i<n;i++){
            if(i%2)ans[i]=1;
            else ans[i]=2;
        }
    }else{
        ans[b[0]]=a[b[0]];
        for(int i=b[0]-1;i>=0;i--){
            if(ans[i+1]>1)ans[i]=ans[i+1]/2;
            else ans[i]=ans[i+1]*2;
        }
        for(int i=b.back()+1;i<n;i++){
            if(ans[i-1]>1)ans[i]=ans[i-1]/2;
            else ans[i]=ans[i-1]*2;
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<' ';
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