#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

long long pre(vector<long long>& tree, int t) {
    long long ans = 0;
    while (t > 0) {
        ans += tree[t];
        t -= t & -t;
    }
    return ans;
}
long long dif(vector<long long>& tree, int l, int r) {
    return pre(tree, r + 1) - pre(tree, l);
}
int main() {
    int N;
    cin >> N;
    for(int t=0;t<N;t++) {
        int M;
        cin >> M;
        vector<long long> weight(M + 1);
        for (int i = 1; i < M + 1; i++) {
            cin >> weight[i];
        }
        vector<long long> tree(M + 1);
        for (int i = 1; i <= M; i++) {
            tree[i] += weight[i];
            int nxt = (i & (-i)) + i;
            if (nxt <= M ) {
                tree[nxt] += tree[i];
            }
        }
        long long ans = 0;
        int k = 1;
        for (; k <= M / 2; k++) {
            if(M%k!=0) continue;
            int l = 0;
            int r = l + k-1;
            long long Max = dif(tree, l, r);
            long long Min = Max;
            l = r +1;
            r = l + k-1;
            while (r < M) {
                long long temp = dif(tree, l, r)<<1>>1;
                Max = max(Max, temp);
                Min = min(Min, temp);
                ans = max(ans, Max - Min);
                l = r + 1;
                r = l + k-1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}