#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15 + 1000;
const ll MOD = 1000000007;
using S = P;
using F = ll;
S op(S a, S b) {
    if(a.first < b.first)
        return a;
    else {
        return b;
    }
}
S e() { return P(1e18, -1); }
S mapping(F f, S x) { return P(min(x.first + f, (ll)(1e18)), x.second); }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
int main() {
    ll Q;
    cin >> Q;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(Q);
    REP(i, Q) { seg.set(i, P(INF, i)); }
    int id = 0;
    while(Q--) {
        int a;
        cin >> a;
        if(a == 1) {
            ll b;
            cin >> b;
            seg.set(id, P(b, id));
        } else if(a == 2) {
            ll b;
            cin >> b;
            seg.apply(0, id, b);
        } else {
            auto x = seg.all_prod();
            cout << x.first << endl;
            seg.set(x.second, P(INF, -1));
        }
        id++;
    }
}