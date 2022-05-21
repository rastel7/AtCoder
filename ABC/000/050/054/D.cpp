#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int a[50], b[50], c[50];
int dp[50][500][500];
int INF = 1e9;
void chmin(int& a, int b) {
  a = min(a, b);
}
int main() {
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  REP(i, N)cin >> a[i] >> b[i] >> c[i];
  REP(i, 50)REP(j, 500)REP(k, 500) dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  REP(i, N)REP(j, 410)REP(k, 410) {
    chmin(dp[i + 1][j][k], dp[i][j][k]);
    chmin(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
  }
  int ans = INF;
  REP(i, 500)REP(j, 500) {
    if(i == 0 || j == 0)continue;
    if(i * Mb == j * Ma) {
      chmin(ans, dp[N][i][j]);
    }
  }
  if(ans == INF)ans = -1;
  cout << ans << endl;
}