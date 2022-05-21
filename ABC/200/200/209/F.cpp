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
int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    REP(i, n) cin >> h[i];
    vector<mint> dp(1, 1);
    for(int i = 1; i < n; ++i) {
        vector<mint> p(i + 1);
        swap(dp, p);
        if(h[i - 1] <= h[i]) {
            mint s = 0;
            REP(j, i) {
                s += p[j];
                dp[j + 1] += s;
            }
        }
        if(h[i - 1] >= h[i]) {
            mint s = 0;
            for(int j = i - 1; j >= 0; j--) {
                s += p[j];
                dp[j] += s;
            }
        }
    }
    mint ans;
    REP(i, n) ans += dp[i];
    cout << ans.val() << endl;
}