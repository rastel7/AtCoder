#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define rep(i, j,n) for (int i = j; i <= (int)(n); i++)
using ll = long long;
using namespace std;
int a[201010], b[201010];
const ll inf = 1e18;
ll dp[201010][3][3];
void chmin(ll& a, ll b) {
  a = min(a, b);
}
int main() {
  ll N;
  cin >> N;
  REP(i, N) {
    cin >> a[i + 1];
  }
  REP(i, N) {
    cin >> b[i + 1];
  }
  REP(i, 201010)REP(j, 3)REP(k, 3)dp[i][j][k] = inf;
  dp[1][0][0] = a[1];
  dp[1][1][1] = 0;
  rep(i, 2, N)rep(j, 0, 1)rep(k, 0, 1)rep(prej, 0, 1) {
    chmin(dp[i][j][k], dp[i - 1][prej][k] + (j == 0 ? a[i] : 0) + (j == prej ? b[i - 1] : 0));
  }
  ll ans = inf;
  rep(j, 0, 1)rep(k, 0, 1)chmin(ans, dp[N][j][k] + (j == k ? b[N] : 0));
  cout << ans << endl;
}