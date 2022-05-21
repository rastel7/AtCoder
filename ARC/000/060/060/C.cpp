#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N, A;
int x[60];
ll dp[60][60][60 * 60];
int main() {
  cin >> N >> A;
  REP(i, N)cin >> x[i];
  dp[0][0][0] = 1;
  REP(i, N)REP(j, N)REP(k, 51 * 51) {
    dp[i + 1][j][k] += dp[i][j][k];
    dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
  }
  ll ans = 0;
  REP(j, N+1)REP(k, 51 * 51) {
    if(j == 0)continue;
    if(k % j != 0)continue;
    if(k / j == A) {
      ans += dp[N][j][k];
    }
  }
  cout << ans << endl;
}