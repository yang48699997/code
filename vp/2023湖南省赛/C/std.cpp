#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
const int N = 500000 + 5;
char str[N];
struct Node
{
	int len, fa;
	int ch[26];
}node[N*4];
int tot = 1, last = 1;
int summ = 0;//不同的子串数
void extend(int c)
{
	int p = last, np = last = ++tot;
	node[np].len = node[p].len + 1;
	for (; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
	if (!p) {
		node[np].fa = 1; summ += node[np].len - node[node[np].fa].len;
	}
	else
	{
		int q = node[p].ch[c];
		if (node[q].len == node[p].len + 1) { node[np].fa = q; summ += node[np].len - node[node[np].fa].len; }
		else {
			int nq = ++tot;
			summ -= node[q].len - node[node[q].fa].len;
			node[nq] = node[q], node[nq].len = node[p].len + 1;
			node[q].fa = node[np].fa = nq;
			summ += node[q].len - node[node[q].fa].len;
			summ += node[np].len - node[node[np].fa].len;
			summ += node[nq].len - node[node[nq].fa].len;
			for (; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> str + 1;
	string t;
	cin >> t;
	t = ' ' + t;
	vector<int>sum(30);
	int all = 0;
	//int summ = 0;;
	for (int i = 1; i <= n - m + 1; i++) {
		int pre_tot = summ;
		extend(str[i] - 'a');
	//	summ = 0;
	//	for (int j = 2; j <= tot; j++) {
	//		summ += node[j].len - node[node[j].fa].len;
	//	}
		sum[str[i] - 'a'] += (summ - pre_tot);
	}
	all += summ;
	for (int i = n - m + 2; str[i]; i++) {
		int j = i - (n - m);
		int pre_tot = summ;
		extend(str[i] - 'a');
	//	summ = 0;
	//	for (int j = 2; j <= tot; j++) {
	//		summ += node[j].len - node[node[j].fa].len;
	//	}
		sum[str[i] - 'a'] += (summ - pre_tot);
		all += summ;
		all -= sum[t[j - 1] - 'a'];
		if (sum[t[j - 1] - 'a']) all++;
	}
    // cerr << summ;
	cout << all;
}