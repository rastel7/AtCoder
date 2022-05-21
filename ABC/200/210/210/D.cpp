#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 9e18;
const ll MOD = 1000000007;
int const MAX_N = 1050;

int main() {
    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> A(H + 1, vector<ll>(W + 1));
    REP(i, H) REP(j, W) cin >> A[i + 1][j + 1];
    ll ans = INF;
    vector<vector<ll>> dp(H + 1, vector<ll>(W + 1, INF));
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            dp[i][j] = min(dp[i][j - 1] + C, min(dp[i - 1][j] + C, A[i][j]));
        }
    }
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            ans = min(ans, min(dp[i][j - 1] + A[i][j] + C,
                               dp[i - 1][j] + A[i][j] + C));
        }
    }
    REP(i, H + 1) dp[i].clear();
    REP(i, H) reverse(A[i + 1].begin() + 1, A[i + 1].end());
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            dp[i][j] = min(dp[i][j - 1] + C, min(dp[i - 1][j] + C, A[i][j]));
        }
    }
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            ans = min(ans, min(dp[i][j - 1] + A[i][j] + C,
                               dp[i - 1][j] + A[i][j] + C));
        }
    }
    cout << ans << endl;
}