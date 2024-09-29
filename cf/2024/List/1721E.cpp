#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class S>
struct Dynamic_KMP{
	vector<int> mp, kmp;
	S s;
	Dynamic_KMP() : mp(1, -1), kmp(1, -1) {}
	template<class C>
	void push(C c){
		s.push_back(c);
		int j = mp.back();
		while (j >= 0 && s[j] != c) j = kmp[j];
		j++;
		if (mp.back() != -1 && s[mp.back()] == c) kmp.back() = kmp[mp.back()];
		else kmp.back() = mp.back();
		mp.push_back(j);
		kmp.push_back(j);
	}
	void pop(){
		s.pop_back();
		mp.pop_back();
		kmp.pop_back();
		kmp.back() = mp.back();
	}
	int query(){
		return mp.back();
	}
};

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    Dynamic_KMP<string> dk;
    for (char c : s) dk.push(c);
    
    while (q--) {
        string t;
        cin >> t;
        int m = t.size();
        for (int j = 0; j < m; j++) {
            dk.push(t[j]);
            cout << dk.query() << " \n"[j == m - 1];
        }
        while (m--) dk.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}