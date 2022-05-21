#include<bits/stdc++.h>
#include<atcoder/all>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
vector<int> G[2010];
mint dp[3][2010][2010];
int main() {
  ll N, M, K, S, T, X;
  cin >> N >> M >> K >> S >> T >> X, X--, S--, T--;
  REP(i, M) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  dp[0][S][0] = 1;
  REP(j, K) {
    REP(i, N) {
      REP(l, 2) {
        for(auto a : G[i]) {
          if(a == X) {
            dp[(l + 1) % 2][a][j + 1] += dp[l][i][j];
          } else {
            dp[l][a][j + 1] += dp[l][i][j];

          }
        }
      }
    }
  }
  cout << dp[0][T][K].val() << endl;
}