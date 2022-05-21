#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
const int MAX_N = 500;
ll dp[MAX_N][MAX_N][MAX_N];
int main() {
    int N, M;
    cin >> N >> M;
    REP(i, MAX_N)
    REP(j, MAX_N)
    REP(k, MAX_N) { dp[i][j][k] = INF; }
    REP(i, MAX_N) dp[0][i][i] = 0;
    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--;
        dp[0][a][b] = c;
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, N) {
            REP(k, N) {
                dp[i + 1][j][k] = min(dp[i][j][k], dp[i][j][i] + dp[i][i][k]);
                if(dp[i + 1][j][k] != INF) {
                    ans += dp[i + 1][j][k];
                }
            }
        }
    }
    cout << ans << endl;
}