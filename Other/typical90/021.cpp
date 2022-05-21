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
int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M), B(M);
  vector<vector<int>> G(N);
  REP(i, M) {
    cin >> A[i] >> B[i], A[i]--, B[i]--;
    G[A[i]].emplace_back(B[i]);
  }
  StronglyConnectedComponents scc(G);
  ll ans = 0;
  map<ll, ll> mp;
  REP(i, N) {
    mp[scc.component[i]]++;
  }
  for(auto [l, r] : mp) {
    ans += r * (r - 1) / 2;
  }
  cout << ans << endl;
}