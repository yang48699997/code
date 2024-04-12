#include <bits/stdc++.h>
#define ll long long
#define doit(i,j,k) for(int i=j[k];i!=k;i=j[i])
using namespace std;

const int N=550; 

int ans,stk[N];
struct DLX{
    static const int MAXSIZE=1e5+7;
    int n,m;
    int L[MAXSIZE],R[MAXSIZE],U[MAXSIZE],D[MAXSIZE];
    int sz[MAXSIZE],Lp[MAXSIZE],idx;
    int col[MAXSIZE],row[MAXSIZE];

    inline void build(int r,int c){
        n=r,m=c;
        for(int i=0;i<=c;i++) L[i]=i-1,R[i]=i+1,U[i]=D[i]=i;
        L[0]=c,R[c]=0,idx=c;
        memset(Lp,0,sizeof Lp);
        memset(sz,0,sizeof sz);
    }
    inline void Insert(int r,int c){
        row[++idx]=r,col[idx]=c,sz[c]++;
        U[idx]=c,D[idx]=D[c],U[D[c]]=idx,D[c]=idx;
        if(!Lp[r]) Lp[r]=L[idx]=R[idx]=idx;
        else{
            L[idx]=Lp[r],R[idx]=R[Lp[r]];
            L[R[Lp[r]]]=idx,R[Lp[r]]=idx;
        } 
    }
    inline void remove(int c){
        L[R[c]]=L[c],R[L[c]]=R[c];
        doit(i,D,c) doit(j,R,i) U[D[j]]=U[j],D[U[j]]=D[j],--sz[col[j]];
    } 
    inline void recover(int c){
        doit(i,U,c) doit(j,L,i) U[D[j]]=j,D[U[j]]=j,++sz[col[j]];
        L[R[c]]=c,R[L[c]]=c;
    }
    bool dance(int dep){
        if(!R[0]) {
            ans=dep;
            return true;
        }
        int c=R[0];
        doit(i,R,0) if(sz[i]<sz[c]) c=i;
        remove(c);
        doit(i,D,c){
            stk[dep]=row[i];
            doit(j,R,i) remove(col[j]);
            if(dance(dep+1)) return true;
            doit(j,L,i) recover(col[j]);
        }
        recover(c);
        return false;
    }  
};

int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m;
    DLX dlx={};
	dlx.build(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			if(x) dlx.Insert(i,j);
		}
	if(dlx.dance(0))while(ans--) cout<<stk[ans]<<' ';
	else cout<<-1;
	return 0;
}