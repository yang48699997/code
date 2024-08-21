    #include <bits/stdc++.h>
    using namespace std;

    struct DSU{
        vector<int> fa,size;
        DSU(int n):fa(n),size(n,1){
            for(int i=0;i<n;i++)fa[i]=i;
        }
        int find(int x){
            if(fa[x]==x)return x;
            fa[x]=find(fa[x]);
            return fa[x];
        }
        bool merge(int x,int y){
            x=find(x);
            y=find(y);
            if(x==y)return false;
            size[x]+=size[y];
            fa[y]=x;
            return true;
        }
        int getCount(int x){
            x=find(x);
            return size[x];
        }
    };

    void solve() {
        int h, w, y;
        cin >> h >> w >> y;
        vector<vector<int>> a(h + 2, vector<int> (w + 2));
        vector<vector<pair<int, int>>> p(y + 1);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> a[i][j];
                if (a[i][j] <= y) p[a[i][j]].emplace_back(i, j);
            }
        }
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        DSU dsu((h + 2) * (w + 2));
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1) {
                    dsu.merge(0, i * (w + 2) + j);
                }
            }
        }
        int sum = dsu.getCount(0);
        for (int i = 1; i <= y; i++) {
            for (auto [x, y] : p[i]) {
                for (int j = 0; j < 4; j++) {
                    int nx = x + dir[j][0];
                    int ny = y + dir[j][1];
                    if (a[nx][ny] <= a[x][y]) {
                        dsu.merge(nx * (w + 2) + ny, x * (w + 2) + y);
                    }
                }
            }
            cout << h * w - dsu.getCount(0) + sum << "\n";
        }
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        solve();
        return 0;
    }