#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<mint> dp(W, 0);
  dp[0] = 1;
  REP(h, H) {
    vector<mint> next(W, 0);
    REP(i, 1 << (W - 1)) {
      bool t = 1;
      REP(w, W) {
        if(((i >> w) & 1) && ((i >> (w + 1)) & 1))t = 0;
      }
      if(t == 0)continue;
      REP(w, W) {
        if(w == 0) {
          if((i >> w) & 1) {
            next[w + 1] += dp[w];
          } else {
            next[w] += dp[w];
          }
        } else if(w == W - 1) {
          if((i >> (w - 1)) & 1) {
            next[w - 1] += dp[w];
          } else {
            next[w] += dp[w];
          }
        } else {
          if((i >> (w - 1)) & 1) {
            next[w - 1] += dp[w];
          } else if((i >> w) & 1) {
            next[w + 1] += dp[w];
          } else {
            next[w] += dp[w];
          }
        }
      }
    }
    swap(next, dp);
  }
  cout << dp[K - 1].val() << endl;
}