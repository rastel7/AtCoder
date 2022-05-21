#include <atcoder/all>
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using mint0 = dynamic_modint<998244353>;

int main() {
    ll N, L;
    cin >> N >> L;
    vector<set<char>> S(N);
    vector<ll> A(N);
    REP(i, N) {
        string c;
        cin >> c;
        for(auto a : c) {
            A[i] |= (1 << (a - 'a'));
            S[i].insert(a);
        }
    }
    mint ans = 0;
    for(int i = 1; i < (1 << N); ++i) {
        int cnt = 0;
        ll bit = (1 << 26) - 1;
        REP(j, N) {
            if((i >> j) & 1) {
                cnt++;
                bit &= A[j];
            }
        }
        ans += ((cnt % 2 == 0) ? -1 : 1) * mint(__builtin_popcount(bit)).pow(L);
    }
    cout << ans.val() << endl;
}