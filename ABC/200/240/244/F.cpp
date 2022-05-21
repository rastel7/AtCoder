#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<int> G[20];
const int inf = 1e9;
int dp[1 << 20][20];
int main() {
  int n, m;
  cin >> n >> m;
  REP(i, m) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  int N = 1 << n;
  REP(i, N + 1)REP(j, n + 1) {
    dp[i][j] = inf;
  }
  queue<pair<int, int>> que;
  REP(i, n) {
    dp[(1 << i)][i] = 1;
    que.push({ 1 << i,i });
  }
  while(!que.empty()) {
    auto [s, i] = que.front();
    que.pop();
    for(auto a : G[i]) {
      auto x = s ^ (1 << a);
      if(dp[x][a] < inf)continue;
      dp[x][a] = dp[s][i] + 1;
      que.push({ x,a });
    }
  }
  dp[0][0] = 0;
  int ans = 0;
  REP(i, N) {

    int mn = inf;
    REP(j, n) {
      mn = min(mn, dp[i][j]);
    }
    ans += mn;
  }
  cout << ans << endl;
}