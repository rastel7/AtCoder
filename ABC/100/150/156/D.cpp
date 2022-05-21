#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
using mint = modint1000000007;
mint comb(int n, int r) {
    mint bunbo = 1, bunsi = 1;
    for(int i = 1; i <= r; ++i) {
        bunbo *= i, bunsi *= (n - i + 1);
    }
    return bunsi / bunbo;
}
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    mint ans = mint(2).pow(n) - 1;
    ans -= comb(n, a) + comb(n, b);
    cout << ans.val() << endl;
}