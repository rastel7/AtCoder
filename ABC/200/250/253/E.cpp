#include <bits/stdc++.h>

#include <atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
mint op(mint l, mint r) { return l + r; }
mint e() { return 0; }
using segtree = atcoder::segtree<mint, op, e>;
segtree dp[1100];
int main() {
  ll N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < 1010; ++i) {
    dp[i] = segtree(vector<mint>(6000));
  }
  for (int i = 1; i <= M; ++i) {
    dp[1].set(i, 1);
  }
  for (int i = 2; i <= N; ++i) {
    mint allsum = dp[i - 1].all_prod();
    for (int j = 1; j <= M; ++j) {
      ll l = max<ll>(0, j - (K - 1));
      ll r = min<ll>(M, j + (K - 1));
      mint tmp =0;
      if (r < l) {
      } else {
         tmp = dp[i - 1].prod(l, r + 1);
      }
      dp[i].set(j, allsum - tmp);
    }
  }
  mint ans = dp[N].all_prod();
  cout << ans.val() << endl;
}