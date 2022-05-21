#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
mint dp[2010][2010], X[2010][2010], Y[2010][2010], Z[2010][2010];
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  REP(i, H)cin >> S[i];
  dp[1][1] = 1;
  for(int y = 1;y <= H;++y) {
    for(int x = 1;x <= W;++x) {
      if(y == 1 && x == 1)continue;
      char c = S[y - 1][x - 1];
      if(c == '#')continue;
      X[y][x] = X[y][x - 1] + dp[y][x - 1];
      Y[y][x] = Y[y - 1][x] + dp[y - 1][x];
      Z[y][x] = Z[y - 1][x - 1] + dp[y - 1][x - 1];
      dp[y][x] = X[y][x] + Y[y][x] + Z[y][x];
    }
  }
  cout << dp[H][W].val() << endl;
}