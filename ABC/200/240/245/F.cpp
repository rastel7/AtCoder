#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

struct StronglyConnectedComponents {
  int n;
  vector<vector<int>> G, rG;
  vector<int> order, component;
  vector<bool> used;
  void dfs(int v) {
    used[v] = 1;
    for(auto nv : G[v]) {
      if(!used[nv]) dfs(nv);
    }
    order.push_back(v);
  }
  void rdfs(int v, int k) {
    component[v] = k;
    for(auto nv : rG[v]) {
      if(component[nv] < 0) rdfs(nv, k);
    }
  }

  StronglyConnectedComponents(vector<vector<int>>& _G) {
    n = _G.size();
    G = _G;
    rG.resize(n);
    component.assign(n, -1);
    used.resize(n);
    for(int v = 0; v < n; v++) {
      for(auto nv : G[v]) rG[nv].push_back(v);
    }
    for(int v = 0; v < n; v++) if(!used[v]) dfs(v);
    int k = 0;
    reverse(order.begin(), order.end());
    for(auto v : order) if(component[v] == -1) rdfs(v, k), k++;
  }

  /// 頂点(u, v)が同じ強連結成分に含まれるか
  bool is_same(int u, int v) { return component[u] == component[v]; }

  /// 強連結成分を1つのノードに潰したグラフを再構築する
  vector<vector<int>> rebuild() {
    int N = *max_element(component.begin(), component.end()) + 1;
    vector<vector<int>> rebuildedG(N);
    set<pair<int, int>> connected;
    for(int v = 0; v < N; v++) {
      for(auto nv : G[v]) {
        if(component[v] != component[nv] and !connected.count(pair(v, nv))) {
          connected.insert(pair(v, nv));
          rebuildedG[component[v]].push_back(component[nv]);
        }
      }
    }
    return rebuildedG;
  }
};
int U[210101], V[210101];
vector<int> ans;
void dfs(int id, vector<vector<int>> const& G) {
  for(auto a : G[id]) {
    if(ans[a] != 0)continue;
    ans[a] = 1;
    dfs(a, G);
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  ans.resize(N);
  vector<vector<int>> G(N);

  REP(i, M) {
    int u, v;
    cin >> u >> v, u--, v--;
    U[i] = u, V[i] = v;
    G[u].emplace_back(v);
  }

  auto scc = StronglyConnectedComponents(G);
  REP(i, M) {
    if(scc.is_same(U[i], V[i])) {
      ans[U[i]] = 1, ans[V[i]] = 1;
    }
  }
  vector<vector<int>> gyaku(N);
  REP(i, M) {
    gyaku[V[i]].emplace_back(U[i]);
  }
  REP(i, N) {
    if(ans[i] == 1)dfs(i, gyaku);
  }
  int cnt = 0;
  REP(i, N)cnt += ans[i];
  cout << cnt << endl;
}