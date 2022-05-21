#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using mint = atcoder::modint1000000007;
using namespace std;
template< class T >
struct Matrix {
    vector< vector< T > > A;

    Matrix() {}

    Matrix(size_t n, size_t m) : A(n, vector< T >(m, 0)) {}

    Matrix(size_t n) : A(n, vector< T >(n, 0)) {};

    size_t size() const {
        if(A.empty()) return 0;
        assert(A.size() == A[0].size());
        return A.size();
    }

    size_t height() const {
        return (A.size());
    }

    size_t width() const {
        return (A[0].size());
    }

    inline const vector< T >& operator[](int k) const {
        return (A.at(k));
    }

    inline vector< T >& operator[](int k) {
        return (A.at(k));
    }

    static Matrix I(size_t n) {
        Matrix mat(n);
        for(int i = 0; i < n; i++) mat[i][i] = 1;
        return (mat);
    }

    Matrix& operator+=(const Matrix& B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                (*this)[i][j] += B[i][j];
        return (*this);
    }

    Matrix& operator-=(const Matrix& B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                (*this)[i][j] -= B[i][j];
        return (*this);
    }

    Matrix& operator*=(const Matrix& B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        vector< vector< T > > C(n, vector< T >(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < p; k++)
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        A.swap(C);
        return (*this);
    }

    Matrix& operator^=(long long k) {
        Matrix B = Matrix::I(height());
        while(k > 0) {
            if(k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return (*this);
    }

    Matrix operator+(const Matrix& B) const {
        return (Matrix(*this) += B);
    }

    Matrix operator-(const Matrix& B) const {
        return (Matrix(*this) -= B);
    }

    Matrix operator*(const Matrix& B) const {
        return (Matrix(*this) *= B);
    }

    Matrix operator^(const long long k) const {
        return (Matrix(*this) ^= k);
    }

    friend ostream& operator<<(ostream& os, Matrix& p) {
        size_t n = p.height(), m = p.width();
        for(int i = 0; i < n; i++) {
            os << "[";
            for(int j = 0; j < m; j++) {
                os << p[i][j] << (j + 1 == m ? "]\n" : ",");
            }
        }
        return (os);
    }


    T determinant() {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for(int i = 0; i < width(); i++) {
            int idx = -1;
            for(int j = i; j < width(); j++) {
                if(B[j][i] != 0) idx = j;
            }
            if(idx == -1) return (0);
            if(i != idx) {
                ret *= -1;
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T vv = B[i][i];
            for(int j = 0; j < width(); j++) {
                B[i][j] /= vv;
            }
            for(int j = i + 1; j < width(); j++) {
                T a = B[j][i];
                for(int k = 0; k < width(); k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return (ret);
    }
};

template <class T>
T modpow(T base, T exp, T MOD) {
    assert(MOD < 998244353 || typeid(T) == typeid(long long));
    T ret = 1;
    while(exp > 0) {
        if(exp & 1) ret = ret * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return ret;
}

int main() {
    const int MOD = 1e9 + 7;
    ll N, B, K;
    cin >> N >> B >> K;
    vector<int> C(K);
    REP(i, K)cin >> C[i];
    vector<vector<mint>> dp(64, vector<mint>(B));
    REP(i, K) {
        dp[0][(C[i]) % B]++;
    }
    vector<ll> pow10(64);
    REP(i, 63)
        pow10[i] = modpow(10ll, (1ll << i), B);
    REP(i, 62) {
        REP(j, B) {
            REP(k, B) {
                int next = (j * pow10[i] + k) % B;
                dp[i + 1][next] += dp[i][j] * dp[i][k];
            }
        }
    }

    vector<vector<mint>> ans(64, vector<mint>(B, 0));
    ans[0][0] = 1;
    for(int i = 0; i < 62; i++) {
        if((N & (1LL << i)) != 0LL) {
            for(int j = 0; j < B; j++) {
                for(int k = 0; k < B; k++) {
                    ll nex = (j * pow10[i] + k) % B;
                    ans[i + 1][nex] += ans[i][j] * dp[i][k];
                }
            }
        } else {
            for(int j = 0; j < B; j++) ans[i + 1][j] = ans[i][j];
        }
    }

    cout << ans[62][0].val() << endl;
}