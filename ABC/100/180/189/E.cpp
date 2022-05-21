#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using P = pair<ll, ll>;
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
int main() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    REP(i, N)cin >> X[i] >> Y[i];
    int M;
    cin >> M;
    vector<Matrix<ll>> B(M , Matrix<ll>().I(3));
    REP(i, M) {
        ll op;
        cin >> op;
        auto v = Matrix<ll>(3, 3);
        if(op == 1) {
            v[0][0] = 0;
            v[0][1] = 1;
            v[0][2] = 0;
            v[1][0] = -1;
            v[1][1] = 0;
            v[1][2] = 0;
            v[2][0] = 0;
            v[2][1] = 0;
            v[2][2] = 1;
        } else if(op == 2) {
            v[0][0] = 0;
            v[0][1] = -1;
            v[0][2] = 0;
            v[1][0] = 1;
            v[1][1] = 0;
            v[1][2] = 0;
            v[2][0] = 0;
            v[2][1] = 0;
            v[2][2] = 1;
        } else if(op == 3) {
            ll p;
            cin >> p;
            v[0][0] = -1;
            v[0][1] = 0;
            v[0][2] = 2 * p;
            v[1][0] = 0;
            v[1][1] = 1;
            v[1][2] = 0;
            v[2][0] = 0;
            v[2][1] = 0;
            v[2][2] = 1;
        } else {
            ll p;
            cin >> p;
            v[0][0] = 1;
            v[0][1] = 0;
            v[0][2] = 0;
            v[1][0] = 0;
            v[1][1] = -1;
            v[1][2] = 2 * p;
            v[2][0] = 0;
            v[2][1] = 0;
            v[2][2] = 1;
        }
        if(i == 0) {
            B[i] = v;
        } else {
            B[i] = v * B[i - 1];
        }
    }
    ll Q;
    cin >> Q;
    vector<P> ans;
    REP(i, Q) {
        ll a, b;
        cin >> a >> b, b--;
        if(a == 0) {
            ans.emplace_back(P(X[b], Y[b]));
            continue;
        }
        a--;
        Matrix<ll> mul(3, 1);
        mul[0][0] = X[b];
        mul[1][0] = Y[b];
        mul[2][0] = 1;
        auto tmp = B[a] * mul;
        ans.emplace_back(P(tmp[0][0], tmp[1][0]));
    }
    for(auto [l, r] : ans) {
        cout << l << " " << r << endl;
    }
}