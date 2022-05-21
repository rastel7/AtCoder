#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template <typename T>
struct BIT {
    //一点加算
    int n;
    vector<T> bit;
    BIT(int n_) :n(n_ + 1), bit(n, 0) {}
    void add(int i, T x) {
        for(int idx = i;idx < n;idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }
    //(0,i]までの和
    T sum(int i) {
        T s(0);
        for(int idx = i;idx > 0;idx -= (idx & -idx)) {
            s += bit[idx];
        }
        return s;
    }
};
int main() {

}