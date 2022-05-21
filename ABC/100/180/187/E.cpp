#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll ans[201010];
vector<vector<int>> G;
int dist[201010];
void dfs(int id, int prev) {
  if(prev != -1) {
    dist[id] = dist[prev] + 1;
  }
  for(auto a : G[id]) {
    if(a == prev) continue;
    dfs(a, id);
  }
}
void dfs2(int id, int prev) {
  for(auto a : G[id]) {
    if(a != prev) {
      ans[a] += ans[id];
      dfs2(a, id);
    }
  }
}
int main() {
  int N;
  cin >> N;
  G.resize(N);
  vector<int> A(N - 1), B(N - 1);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    A[i] = a, B[i] = b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  dfs(0, -1);
  int Q;
  cin >> Q;
  while(Q--) {
    int t, e, x;
    cin >> t >> e >> x, e--;
    if(t == 1) {
      int id;
      if(dist[A[e]] < dist[B[e]]) {
        id = B[e];
        ans[0] += x;
        ans[id] += -x;
      } else {
        id = A[e];
        ans[id] += x;
      }
    } else {
      int id;
      if(dist[A[e]] < dist[B[e]]) {
        id = B[e];
        ans[id] += x;
      } else {
        id = A[e];
        ans[0] += x;
        ans[id] += -x;
      }
    }
  }
  dfs2(0, -1);
  REP(i, N)cout << ans[i] << endl;
}