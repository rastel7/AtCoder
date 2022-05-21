#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll dp[3010][3010];
void chmin(ll& a, ll b) {
  a = min(a, b);
}
int main() {
  int N, M;
  cin >> N >> M;
  dp[0][0] = 0;
  vector<ll> S(N), T(M);
  REP(i, N)cin >> S[i];
  REP(i, M)cin >> T[i];
  REP(i,M+1)dp[0][i]=i;
  REP(i,N+1)dp[i][0]=i;
  REP(i, N )REP(j, M) {
    dp[i + 1][j + 1] = min({ dp[i][j + 1] + 1,dp[i + 1][j] + 1,dp[i][j] + ((S[i] == T[j]) ? 0ll : 1ll) });
  }
  cout << dp[N][M] << endl;
}