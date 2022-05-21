#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<int> G[210101];
const int INF = 1e9;
int main() {
  int N, M, S, T;
  cin >> N >> M;
  REP(i, M) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].emplace_back(v);
  }
  cin >> S >> T, S--, T--;
  vector<vector<int>> dp(4, vector<int>(N, INF));
  dp[0][S] = 0;
  queue<pair<int, int>> que;
  que.push({ S,0 });
  while(!que.empty()) {
    auto [id, cnt] = que.front();que.pop();
    for(auto a : G[id]) {
      if(dp[(cnt + 1) % 3][a] != INF)continue;
      dp[(cnt + 1) % 3][a] = dp[cnt][id] + 1;
      que.push({ a,(cnt + 1) % 3 });
    }
  }
  if(dp[0][T] == INF)dp[0][T] = -3;
  cout << dp[0][T]/3<< endl;
}