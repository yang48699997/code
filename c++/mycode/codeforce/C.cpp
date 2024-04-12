#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
#define yes "YES"
#define no "NO"
using ll = long long;
using namespace std;

const int MOD=998'244'353;
const int N=1e5+5;
const ll inf=1e18;

int T,n;
string s="314159265358979323846264338327950288";
struct node{
	int price;
	int time;
	node(int price,int time){
		this->price=price;
		this->time=time;
	}
	bool operator<(const node &node2)const{
		if(price!=node2.price)return price<node2.price;
		else return time<node2.time;
	}
};
template<class T>
int getMax(T a,T b){
	return max(a.price,b.price);
}
void solve(){
	node d1=node{100,20};
	node *d2=new node(10,29);
	node *d3=new node(110,2312);
	node *d4=new node(100,319);
	priority_queue<node> q;
	q.push(d1);
	q.push(*d2);
	q.push(*d3);
	q.push(*d4);
	while(!q.empty()){
		node cur=q.top();
		q.pop();
		cout<<cur.price<<sp<<cur.time<<endl;
	}
	cout<<getMax<node>(d1,*d2);
}

int main(){
	ios::sync_with_stdio(false); 
	cin.tie(0);
	// cin >> T;
	T=1;
	while(T--){
		solve();
		cout<<endl;
	}
	return 0;
}