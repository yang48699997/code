#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double vectorNorm(const vector<double>& v) {
    double sum = 0.0;
    for (double x : v) {
        sum += x * x;
    }
    return sqrt(sum);
}

vector<vector<double>> householderMatrix(const vector<double>& x) {
    int n = x.size();
    vector<double> u = x;
    double normX = vectorNorm(x);
    u[0] += (x[0] >= 0 ? normX : -normX);
    double normU = vectorNorm(u);

    if (normU < 1e-10) {
        vector<vector<double>> H(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) H[i][i] = 1.0;
        return H;
    }

    for (int i = 0; i < n; i++) {
        u[i] /= normU;
    }

    vector<vector<double>> H(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            H[i][j] = -2.0 * u[i] * u[j];
        }
        H[i][i] += 1.0;
    }
    return H;
}

vector<double> matVecMult(const vector<vector<double>>& A, const vector<double>& v) {
    int m = A.size(), n = A[0].size();
    vector<double> result(m, 0.0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += A[i][j] * v[j];
        }
    }
    return result;
}

vector<vector<double>> matMult(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int m = A.size(), n = B[0].size(), p = A[0].size();
    vector<vector<double>> C(m, vector<double>(n, 0.0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

pair<vector<vector<double>>, vector<vector<double>>> qrDecomposition(const vector<vector<double>>& A) {
    int m = A.size(), n = A[0].size();
    vector<vector<double>> R = A;
    vector<vector<double>> Q(m, vector<double>(m, 0.0));
    for (int i = 0; i < m; i++) Q[i][i] = 1.0;

    for (int k = 0; k < n; k++) {
        vector<double> x(m - k, 0.0);
        for (int i = k; i < m; i++) {
            x[i - k] = R[i][k];
        }

        vector<vector<double>> Hk = householderMatrix(x);

        vector<vector<double>> H(m, vector<double>(m, 0.0));
        for (int i = 0; i < k; i++) H[i][i] = 1.0;
        for (int i = k; i < m; i++) {
            for (int j = k; j < m; j++) {
                H[i][j] = Hk[i - k][j - k];
            }
        }

        R = matMult(H, R);
        Q = matMult(Q, H);
    }

    return {Q, R};
}

void printMatrix(const vector<vector<double>>& A) {
    for (const auto& row : A) {
        for (double x : row) {
            cout << fixed << setprecision(4) << x << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "输入矩阵的行数和列数 (m n): " << endl;
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "输入矩阵元素:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    auto [Q, R] = qrDecomposition(A);

    cout << "正交矩阵 Q:" << endl;
    printMatrix(Q);

    cout << "上三角矩阵 R:" << endl;
    printMatrix(R);

    return 0;
}
