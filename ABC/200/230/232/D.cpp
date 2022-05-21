#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll dp[110][110];
template<class T>
void chmax(T& a, T b) {
  if(a < b)a = b;
}
int main() {
  REP(i, 110)REP(j, 110)dp[i][j] = 0;
  ll W, H;
  cin >> H >> W;
  vector<string> S(H);
  REP(i, H) {
    cin >> S[i];
  }
  dp[0][0] = 1;
  REP(i, H)REP(j, W) {
    if(S[i][j] == '#')continue;
    if(i != 0) {
      if(dp[i - 1][j] != 0)chmax(dp[i][j], dp[i - 1][j] + 1);
    }
    if(j != 0) {
      if(dp[i][j - 1] != 0)chmax(dp[i][j], dp[i][j - 1] + 1);
    }
  }
  ll ans = 0;
  REP(i, H + 1)REP(j, W + 1) {
    chmax(ans, dp[i][j]);
  }
  cout << ans << endl;
}