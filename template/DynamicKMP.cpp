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