#include<bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
void chmin(ll& a, ll b) {
    a = min(a, b);
}
void chmax(ll& a, ll b) {
    a = max(a, b);
}
ll A[110];
ll dp[110][110][110];
const ll INF = numeric_limits<ll>::max() / 2;
void res() {
    REP(i, 110)REP(j, 110)REP(k, 110) {
        dp[i][j][k] = -1;
    }
    dp[0][0][0] = 0;
}
int main() {
    ll N, X;
    cin >> N >> X;
    REP(i, N)cin >> A[i];
    ll ans = numeric_limits<ll>::max();
    for(ll i = 1;i <= N;++i) {
        res();
        REP(j, N) {
            REP(k, i+1) {
                REP(l, i) {
                    if(dp[j][k][l] == -1)continue;
                    chmax(dp[j + 1][k][l], dp[j][k][l]);
                    chmax(dp[j + 1][k + 1][(l + A[j]) % i], dp[j][k][l] + A[j]);

                }
            }
        }
        if(dp[N][i][X % i] == -1)continue;
        chmin(ans, (X - dp[N][i][X % i]) / i);
    }
    cout << ans << endl;
}