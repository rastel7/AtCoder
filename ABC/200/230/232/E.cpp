#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
ll H, W, K;

int main() {

  cin >> H >> W >> K;
  ll x_1, y_1, x_2, y_2;
  cin >> x_1 >> y_1 >> x_2 >> y_2;
  vector<mint> dp(4, 0);
  dp[0] = 1;
  while(K--) {
    vector<mint> next(4, 0);
    next[0] = dp[1] * (W - 1) + dp[2] * (H - 1);
    next[1] = dp[0] + (W - 2) * dp[1] + dp[3] * (H - 1);
    next[2] = dp[0] + (H - 2) * dp[2] + dp[3] * (W - 1);
    next[3] = dp[1] + dp[2] + dp[3] * (W - 2 + H - 2);
    dp = next;
  }
  mint ans = 0;
  if(x_1 == x_2 && y_1 == y_2) {
    ans = dp[0];
  } else if(x_1 == x_2) {
    ans = dp[1];
  } else if(y_1 == y_2) {
    ans = dp[2];
  } else {
    ans = dp[3];
  }
  cout << ans.val() << endl;
}