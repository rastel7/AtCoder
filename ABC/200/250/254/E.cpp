#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<vector<ll>> dp;
vector<vector<int>> G;
void search(int id) {
  int d_1 = 0, d_2 = 0, d_3 = 0;
  set<int> s;
  queue<pair<int, int>> que;
  s.insert(id);
  que.push({0, id});
  while (!que.empty()) {
    auto [cost, next] = que.front();
    que.pop();
    if (cost >= 3) {
      continue;
    }
    for (auto a : G[next]) {
      if (!s.count(a)) {
        s.insert(a);
        if (cost == 0) {
          d_1 += a;
        } else if (cost == 1) {
          d_2 += a;
        } else if (cost == 2) {
          d_3 += a;
        }
        que.push({cost + 1, a});
      }
    }
  }
  dp[0][id] = id;
  dp[1][id] = id + d_1;
  dp[2][id] = id + d_2 + d_1;
  dp[3][id] = id + d_3 + d_2 + d_1;
}
int main() {
  ll N, M;
  cin >> N >> M;
  G.resize(N + 10);
  dp.resize(4);
  REP(i, 4) { dp[i].resize(N+10); }
  vector<ll> a(M), b(M);
  REP(i, M) {
    cin >> a[i] >> b[i];
    G[a[i]].emplace_back(b[i]);
    G[b[i]].emplace_back(a[i]);
  }
  int Q;
  cin >> Q;
  vector<ll> x(Q), k(Q);
  REP(i, Q) { cin >> x[i] >> k[i]; }
  REP(i, N + 1) { search(i); }
  REP(i, Q) { cout << dp[k[i]][x[i]] << "\n"; }
}