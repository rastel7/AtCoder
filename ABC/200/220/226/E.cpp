#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
using mint = modint998244353;
bool dfs(int const id, int const prev, vector<vector<int>> const& G, set<int>& passed) {
  passed.insert(id);
  for(auto const nex : G[id]) {
    if(passed.count(nex)) {
      return true;
    }
    if(dfs(nex, id, G, passed)) {
      return true;
    }
  }
  return false;
}
void add(int const id, int const prev, vector<vector<int>> const& G, set<int>& ch) {
  ch.insert(id);
  for(auto const nex : G[id]) {
    if(ch.count(nex))continue;
    add(nex, id, G, ch);
  }
}
int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(b), G[b].emplace_back(a);
  }
 
  REP(i, N) {
    if(G[i].size() == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout<<12312;
  set<int> checked;
  mint ans = 1;
  REP(i, N) {
    if(checked.count(i))continue;
    set<int> tmp;
    if(dfs(i, -1, G, tmp))ans *= 2;

    set<int> next;
    add(i, -1, G, next);
    int edge_cnt = 0;
    for(auto id : next) {
      edge_cnt += G[id].size();
    }
    edge_cnt /= 2;
    if(edge_cnt != ll(next.size())) {
      cout << 0 << endl;
      return 0;
    }
    checked.merge(next);
  }
  cout << ans.val() << endl;
}