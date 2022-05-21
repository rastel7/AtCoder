#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll D, G;
ll p[15], c[15];
const ll MAX_P = 2 * 1e5, INF = 1e16;
ll dp[15][MAX_P];
void chmin(ll& a, ll b) {
  a = min(a, b);
}
int main() {
  cin >> D >> G;
  REP(i, D)cin >> p[i] >> c[i];
  REP(i, MAX_P)REP(j, 15)dp[j][i] = INF;
  dp[0][0] = 0;
  G /= 100;
  REP(i, D) c[i] /= 100;
  REP(i, D) {
    REP(j, MAX_P) {
      REP(k, p[i]) {
        chmin(dp[i + 1][j + (i + 1) * k], dp[i][j] + k);
      }
      chmin(dp[i + 1][j + (i + 1) * p[i] + c[i]], dp[i][j] + p[i]);
    }
  }
  ll ans = INF;
  for(ll point = G;point< MAX_P-10;point++)
    chmin(ans, dp[D][point]);
  cout << ans << endl;
}