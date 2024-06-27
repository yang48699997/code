/*
 * Author: Ram
 * Date: 2024-05-15
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;


#define LL long long
using namespace std;
const int maxn = 100010;
struct SegementTree {
	int ls, rs;
	long long sum, flag;
};
SegementTree tr[maxn * 200];
int tot, a[maxn], root[maxn], Time;
void pushup(int now) {
	tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum;
}
void build(int now, int l, int r) {
	tr[now].ls = tr[now].rs = tr[now].sum = tr[now].flag = 0;
	if(l == r) {
		tr[now].sum = a[l];
		tr[now].flag = 0;
		return;
	}
	int mid = (l + r) >> 1;
	tr[now].ls = ++tot; build(tot, l, mid);
	tr[now].rs = ++tot; build(tot, mid + 1, r);
	pushup(now);
}
void insert(int lnow, int rnow, int l, int r, int ql, int qr, LL val) {
	tr[rnow] = tr[lnow];tr[rnow].sum += val * (qr - ql + 1);
	if(l == ql && r == qr) {
		tr[rnow].flag += val;
		return;
	}
	int mid = (l + r) >> 1;
	if(qr <= mid) {
		tr[rnow].ls = ++tot; insert(tr[lnow].ls, tot, l, mid, ql, qr, val);
	} else if(ql > mid) {
		tr[rnow].rs = ++tot; insert(tr[lnow].rs, tot, mid + 1, r, ql, qr, val);
	} else {
		tr[rnow].ls = ++tot; insert(tr[lnow].ls, tot, l, mid, ql, mid, val);
		tr[rnow].rs = ++tot; insert(tr[lnow].rs, tot, mid + 1, r, mid + 1, qr, val);
	}
//	pushup(rnow);
}
LL query(int now, int l, int r, int ql ,int qr) {
	if(l >= ql && r <= qr) {
		return tr[now].sum;
	}
	int mid = (l + r) >> 1;
	LL ans = tr[now].flag * (qr - ql + 1);
	if(qr <= mid) ans += query(tr[now].ls, l, mid, ql, qr);
	else if(ql > mid) ans += query(tr[now].rs, mid + 1, r, ql, qr);
	else {
		ans += query(tr[now].ls, l, mid, ql, mid);
		ans += query(tr[now].rs, mid + 1, r, mid + 1, qr);
	}
	return ans;
}
int n,tag[maxn];
const int N=1e5+5;
int p[20];
int check(int l,int r,int mid,int k){
    if(mid==0){
        return true;
    }
    int res=0;
    int mi=mid,mx=min(mid*2,N)-1;
    int cnt=1;
    while(mx<N){
        res+=query(root[tag[r]],1,N,mi,mx)*cnt-query(root[tag[l-1]],1,N,mi,mx)*cnt;
        cnt++;
        mi=mx+1;
        mx=mi*2-1;
        if(mx>=N){
            res+=query(root[tag[r]],1,N,mi,N)*cnt-query(root[tag[l-1]],1,N,mi,N)*cnt;
            break;
        }
    }
    return res>k;
}
void solve(){
    int q;
    cin>>n>>q;
    for(int i=1;i<=N;i++)a[i]=0;
    tot=Time=0;
    int x;
    root[0]=++tot;
    build(tot,1,N);
    tag[0]=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x!=0){
            root[++Time]=++tot;
            insert(root[Time-1],root[Time],1,N,x,x,1);
        }
        tag[i]=Time;
    }
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        int mi=0,mx=1e5;
        while(mi<=mx){
            int mid=(mx-mi)/2+mi;
            if(check(l,r,mid,k))mi=mid+1;
            else mx=mid-1;
        }
        cout<<mi-1<<endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}