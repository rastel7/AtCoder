#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;

template< typename T >
struct Combination {
    vector< T > _fact, _rfact, _inv;

    Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
        _fact[0] = _rfact[sz] = _inv[0] = 1;
        for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
        _rfact[sz] /= _fact[sz];
        for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
        for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
    }

    inline T fact(int k) const { return _fact[k]; }

    inline T rfact(int k) const { return _rfact[k]; }

    inline T inv(int k) const { return _inv[k]; }

    T P(int n, int r) const {
        if(r < 0 || n < r) return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return fact(p) * rfact(q) * rfact(p - q);
    }

    T H(int n, int r) const {
        if(n < 0 || r < 0) return (0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};
int main() {
    int K;
    string S;
    cin >> K >> S;
    Combination<mint> comb(K + S.size() + 100);
    mint ans = 0;
    int N = S.size();
    for(int i = 0;i <= K;++i) {
        ans += mint(26).pow(i) * mint(25).pow(K - i) * comb.C(N + K - i - 1, N - 1);
    }
    cout << ans.val() << endl;
}