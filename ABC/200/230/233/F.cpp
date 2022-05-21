#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<ll>  a, b;
vector<ll> P;
bool search(int id, int prev, int obj, vector<int>& keiro, vector<vector<int>> const& G) {
  if(P[id] == obj) {
    return true;
  }
  for(auto x : G[id]) {
    if(x == prev)continue;
    keiro.emplace_back(x);
    if(search(x, id, obj, keiro, G)) {
      return true;
    }
    keiro.pop_back();
  }
  return false;
}
int main() {
  int N;
  cin >> N;
  P.resize(N);
  REP(i, N)cin >> P[i], P[i]--;
  int M;
  cin >> M;
  a.resize(M);
  b.resize(M);
  REP(i, M)cin >> a[i] >> b[i], a[i]--, b[i]--;
  map<pair<int, int>, int> edge;
  REP(i, M) {
    edge[make_pair(a[i], b[i])] = i;
    edge[make_pair(b[i], a[i])] = i;
  }
  vector<vector<int>> G(N);
  dsu uf(N);
  REP(i, M) {
    if(uf.same(a[i], b[i])) {
      continue;
    }
    uf.merge(a[i], b[i]);
    G[a[i]].emplace_back(b[i]);
    G[b[i]].emplace_back(a[i]);
  }
  vector<int> ans;
  vector<bool> checked(N);
  REP(i, N - 1) {
    int id = 0, cnt = 1e9;
    REP(j, N) {
      if(checked[j])continue;
      if(G[j].size() < cnt) {
        id = j, cnt = G[j].size();
      }
    }
    vector<int> keiro = { id };
    if(!search(id, -1, id, keiro, G)) {
      cout << -1 << endl;
      return 0;
    }
    for(int j = keiro.size() - 1;j > 0;j--) {
      P[keiro[j]] = P[keiro[j - 1]];
    }
    P[id] = id;
    reverse(keiro.begin(), keiro.end());
    REP(j, keiro.size() - 1) {
      ans.emplace_back(edge[make_pair(keiro[j], keiro[j + 1])]);
    }
    checked[id] = 1;
    G[id].clear();
    for(auto& p : G) {
      for(int j = p.size() - 1;j >= 0;j--) {
        if(p[j] == id) {
          p.erase(p.begin() + j);
        }
      }
    };
  }
  cout << ans.size() << endl;
  for(auto x : ans) {
    cout << x + 1 << " ";
  }
  cout << endl;
}