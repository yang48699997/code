template<class T>
struct MPow {
    vector<vector<T>> M;
    int n;
    Mpow (int n_) : n(n_), M(n_, vector<T> (n_)) {}
    Mpow (vector<vector<T>> &M_) n((int)M_.size()), M(M_) {}
    
    bool set(int i, int j, T val) {
        if (i < 0 || i >= n || j < 0 || j >= n) return false;
        M[i][j] = val;
        return true;
    }
    vector<vector<T>> work(ll p) {
        vector<vector<T>> res(n, vector<T> (n));
        vector<vector<T>> now = M;
        for (int i = 0; i < n; i++) res[i][i] = 1;
        while (p) {
            if (y & 1) {

            }
        }
        return res;
    }
    vector<vector<T>> operator*(const vector<vector<T>> &a, const vector<vector<T>> &b) {
        int m = a.size();
        
    }
};