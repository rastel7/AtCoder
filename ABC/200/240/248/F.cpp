#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
int main() {
    ll n, p;
    cin >> n >> p;
    ll dp[2][3010][2];
    REP(i, 2) REP(j, 3010) REP(k, 2) dp[i][j][k] = 0;
    dp[0][0][0] = dp[0][1][1] = 1;
    REP(i, n - 1) {
        REP(j, i + 2) {
            REP(a, 2) {
                REP(b, 2) {
                    REP(c, 2) {
                        if((a + b + c) <= 1)
                            dp[1][j + a + b + c][0] += dp[0][j][0];
                        else if((a + b) <= 1)
                            dp[1][j + a + b + c][1] += dp[0][j][0];
                        if((a + b + c) == 0)
                            dp[1][j + a + b + c][0] += dp[0][j][1];
                        else if((a + b) == 0)
                            dp[1][j + a + b + c][1] += dp[0][j][1];
                    }
                }
            }
        }
        for(int j = 0; j < i + 3; j++) {
            for(int k = 0; k < 2; k++) {
                dp[0][j][k] = dp[1][j][k] % p;
                dp[1][j][k] = 0;
            }
        }
    }

    for(int j = 0; j < n - 2; j++)
        cout << dp[0][j + 1][0] << " ";
    cout << dp[0][n - 1][0] << endl;
}