#include <bits/stdc++.h>
#include <string>
#define endl '\n'
using ll = long long;
using namespace std;


const int mod=998'244'353;
const int MOD=1e9+7;
const int N=1e6+5;
const ll INF=1e18;
const int inf=0x3f3f3f3f;

int to(string s){
    int ans=0;
    for(int i=1;i<s.length();i++){
        int cur=s[i]-'0';
        ans=ans*10+cur;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<string> s(n*2);
    for(int i=0;i<2*n;i++){
        cin>>s[i];
    }
    string ans;
    vector<int> l,a(n*2);
    vector<int> v(n+1); 
    set<int> st;
    for(int i=0;i<2*n;i++){
        string cur=s[i];
        int x=to(cur);
        a[i]=x;
    }
    for(int i=0;i<n*2;i++){
        if(s[i][0]=='+'){
            l.push_back(i);
            continue;
        }
        int x=a[i];
        if(v[x]==0){
            int j=0;
            for(;j<l.size();j++)if(a[l[j]]==x)break;
            v[x]=1;
            for(int c=j+1;c<l.size();c++)st.insert(l[c]);
            for(int b=j+1;b<l.size();b++){
                v[a[l[b]]]=2;
            }
            for(int c=l.size()-1;c>=j;c--)l.pop_back();
        }
        else if(v[x]==2){
            if(!st.empty()&&a[*prev(st.end())]==x){
                st.erase(st.find(*prev(st.end())));
            }else {
                cout<<"*";
                return ;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]==1)ans+="G";
        else ans+="S";
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