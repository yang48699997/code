struct Sieve {
    int tot;
    int N;
    vector<int> prime, minP;
    vector<bool> v;
    Sieve(int n_) : N(n_ + 1), tot(0), prime(0), v(n_ + 1), minP(n_ + 1) {
        init();
    } 
    void init() {
        v[1] = 1;
        for (int i = 2; i < N; i++) {
            if (!v[i]) {
                prime.push_back(i);
                tot++;
            }
            for (int j = 0; i * prime[j] < N; j++) {
                v[i * prime[j]] = true;
                minP[i * prime[j]] = prime[j];
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
    }
    bool check(int x) {
        if (x <= 1 || x >= N) return false;
        return !v[x];
    }
    int getMinP(int x) {
        return minP[x];
    }
    int getTot() {
        return tot;
    }
};