#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll dp[4][3010][3010];
ll g[3010][3010];
void chmax(ll& a, ll b) {
  a = max(a, b);
}
int main() {
  ll R, C, K;
  cin >> R >> C >> K;
  REP(i, K) {
    ll y, x, c;
    cin >> y >> x >> c, x--, y--;
    g[y][x] = c;
  }
  dp[0][0][0] = 0;
  REP(i, R)REP(j, C) {
    REP(k, 4) {
      chmax(dp[k][i][j + 1], dp[k][i][j]);
      if(k != 3) {
        chmax(dp[k + 1][i][j + 1], dp[k][i][j] + g[i][j]);
        chmax(dp[0][i + 1][j], dp[k][i][j] + g[i][j]);
      }
      chmax(dp[0][i + 1][j], dp[k][i][j]);
    }
  }
  ll ans = 0;
  REP(i, 4) {
    chmax(dp[i][R][C], dp[i][R - 1][C]);
    chmax(dp[i][R][C], dp[i][R][C - 1]);
    chmax(ans, dp[i][R][C]);
  }
  cout << ans << endl;
}