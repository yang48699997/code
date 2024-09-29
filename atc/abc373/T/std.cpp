#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M;
	ll K;
	cin >> N >> M >> K;
	vector<ll> A(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	ll Asum = accumulate(A.begin(), A.end(), ll(0));
	ll nleft = K - Asum;

	vector<ll> B = A;
	sort(B.rbegin(), B.rend());

	vector<ll> nB(N);
	for(int i = 0; i < N; i++){
		nB[i] = -B[i];
	}

	vector<ll> psums(N+1);
	for(int i = 0; i < N; i++){
		psums[i+1] = psums[i] + B[i];
	}

	auto get_max = [&](int k, ll V) -> ll {
		int idx = lower_bound(nB.begin(), nB.end(), -V) - nB.begin();
		idx = min(idx, k);
		return psums[idx] + V * (k - idx) - psums[k];
	};

	vector<ll> ans(N);
	if(N == 1){
		ans = {0};
	} else {
		for(int i = 0; i < N; i++){
			ll cur = A[i];
			int idx = lower_bound(nB.begin(), nB.end(), -cur) - nB.begin();
			ll s = -1; // no
			ll e = nleft + 1; // yes
			while(s + 1 < e){
				ll m = (s + e) / 2;
				ll votes = cur + m;

				bool guarantee = false;
				if(M == N){
					guarantee = true;
				} else {
					ll X = votes + 1;
					ll need = 0;
					if(idx >= M){
						need = get_max(M, X);
					} else {
						need = get_max(M+1, X) - (max(X, cur) - cur);
					}
					if(need > nleft - m){
						guarantee = true;
					} else {
						guarantee = false;
					}
				}
				if(guarantee){
					e = m;
				} else {
					s = m;
				}
			}

			if(e > nleft){
				ans[i] = -1;
			} else {
				ans[i] = e;
			}
		}
	}
	for(int i = 0; i < N; i++){
		cout << ans[i] << " \n"[i == N-1];
	}
}
