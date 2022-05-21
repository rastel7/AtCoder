#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template <typename T> struct Mat {
    vector<vector<T>> mat;
    Mat() {}
    Mat(int x) : mat(1, vector<T>(x)) {}
    Mat(vector<T> x) : mat(1, vector<T>(x)) {}
    Mat(int y, int x) : mat(y, vector<T>(x)) {}
    Mat(vector<vector<T>> x) : mat(x) {}
    Mat operator+(const Mat &rb) const {
        assert(mat.size() == rb.mat.size());
        Mat<T> ret;
        vector<vector<T>> tmp(mat.size());
        ret.mat = tmp;
        for(int i = 0; i < (int)mat.size(); ++i) {
            ret.mat[i].resize(mat[i].size());
            for(int j = 0; j < (int)mat[i].size(); ++j) {

                ret.mat.at(i).at(j) = mat.at(i).at(j) + rb.mat.at(i).at(j);
            }
        }
        return ret;
    }
    Mat operator*(const Mat &rb) {
        assert(mat[0].size() == rb.mat.size());
        Mat<T> ret;
        ret.mat.resize(mat.size());
        for(int i = 0; i < (int)ret.mat.size(); ++i) {
            ret.mat[i].resize(rb.mat.size(), 0);
        }
        for(int i = 0; i < (int)mat.size(); ++i) {
            ret.mat[i].resize(mat[i].size());
            for(int j = 0; j < (int)mat[i].size(); ++j) {
                for(int k = 0; k < (int)mat.size(); ++k) {
                    ret.mat[i][j] += mat[i][k] * rb.mat[k][j];
                }
            }
        }
        return ret;
    }
    void operator+=(const Mat &rb) {
        assert(mat.size() == rb.mat.size());

        for(int i = 0; i < (int)mat.size(); ++i) {

            for(int j = 0; j < (int)mat[i].size(); ++j) {

                mat.at(i).at(j) += rb.mat.at(i).at(j);
            }
        }
    }
    long long longpow(long long n, long long a, long long mod) {
        if(a == 0)
            return 1;
        if(a == 1)
            return n % mod;
        if(a % 2 == 1)
            return (n * longpow(n, a - 1, mod)) % mod;
        ll t = longpow(n, a / 2, mod) % mod;
        return (t * t) % mod;
    }
    Mat matpow(int x) const {
        Mat ret = this->identity_element();
        Mat y = Mat(this->mat);
        while(x) {
            if(x % 2 == 1) {
                ret = ret * y;
            }
            y = y * y;
            x = x >> 1;
        }
        return ret;
    }
    Mat identity_element() const {
        Mat ret;
        ret.mat.resize(mat.size());
        for(int i = 0; i < (int)mat.size(); ++i) {
            ret.mat[i].resize(mat.size());
            ret.mat[i][i] = 1;
        }
        return ret;
    }
};
int main() {
    vector<vector<double>> tmp = {{2, 3, -4}, {11, 8, 7}, {2, 5, 3}};
    Mat<double> a(tmp);
    auto b = a.matpow(2);
    for(auto &x : b.mat) {
        for(auto &b : x) {
            cout << b << " ";
        }
        cout << endl;
    }
}