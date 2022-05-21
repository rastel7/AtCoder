#include <atcoder/all>
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
vector<ll> P, Q;
int N;
const ll MAX_N = 3 * 1e5 * 2;
int pc[MAX_N];
int GQ[MAX_N], GP[MAX_N];
int G[MAX_N];
ll dfs(int i, int target) {
    pc[i % N] = 1;
    pc[i + N] = 1;

    if(i % N == target % N)
        return 1;
    if(i > N)
        return 1 + dfs(G[i % N], target);
    else
        return 1 + dfs(G[i + N], target);
}
mint L[210101];
template <typename T> struct Combination {
    vector<T> _fact, _rfact, _inv;

    Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
        _fact[0] = _rfact[sz] = _inv[0] = 1;
        for(int i = 1; i <= sz; i++)
            _fact[i] = _fact[i - 1] * i;
        _rfact[sz] /= _fact[sz];
        for(int i = sz - 1; i >= 0; i--)
            _rfact[i] = _rfact[i + 1] * (i + 1);
        for(int i = 1; i <= sz; i++)
            _inv[i] = _rfact[i] * _fact[i - 1];
    }

    inline T fact(int k) const { return _fact[k]; }

    inline T rfact(int k) const { return _rfact[k]; }

    inline T inv(int k) const { return _inv[k]; }

    T P(int n, int r) const {
        if(r < 0 || n < r)
            return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int p, int q) const {
        if(q < 0 || p < q)
            return 0;
        return fact(p) * rfact(q) * rfact(p - q);
    }

    T H(int n, int r) const {
        if(n < 0 || r < 0)
            return (0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};

mint calc_L(ll i) {
    if(L[i]!=0){
        return L[i];
    }
    if(i == 0) {
        return L[i] = 2;
    }
    if(i == 1) {
        return L[i] = 1;
    }
    return L[i] = calc_L(i - 1)+ calc_L(i - 2);
}
int main() {
    calc_L(210000);
    cin >> N;
    P.resize(N), Q.resize(N);
    REP(i, N) cin >> P[i];
    REP(i, N) cin >> Q[i];
    REP(i, N) { GQ[Q[i]] = i, GP[P[i]] = i; }
    REP(i, N) {
        int hoge = G[i] = GQ[P[i]] + N;
        int hoge2 = G[i + N] = GP[Q[i]];
        cerr << hoge << " " << hoge2 << endl;
    }
    vector<ll> num;
    REP(i, N) {
        if(pc[i] == 0) {
            if(P[i] == Q[i]) {
                pc[i] = pc[i + N] = 1;
                num.emplace_back(1);
                continue;
            }
            pc[i] = 1;
            num.emplace_back((dfs(G[i], i)));
        }
    }
    Combination<mint> comb(MAX_N);
    mint ans = 1;
    for(auto i : num) {
        ans *= L[i];
    }
    cout << ans.val() << endl;
}