#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
vector<int> G[110000];
int used[110000];
string S;
vector<int> ans;
void dfs(int id) {
  used[id] = 1;
  S[id] ^= 1;
  ans.emplace_back(id);
  for(auto a : G[id]) {
    if(used[a] != 0)continue;
    dfs(a);
    ans.emplace_back(id);
    S[id] ^= 1;
    if(S[a] == 1) {
      ans.emplace_back(a), ans.emplace_back(id);
      S[id] ^= 1, S[a] ^= 1;
    }
  }
  return;
}
int main() {
  int N, M;
  cin >> N >> M;
  dsu uf(N);
  REP(i, M) {
    int u, v;
    cin >> u >> v, u--, v--;
    if(uf.same(u, v))continue;
    uf.merge(u, v);
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  cin >> S;
  for(auto& c : S) {
    c -= '0';
  }
  dfs(0);
  if(S[0] == 1) {
    ans.emplace_back(G[0][0]);
    ans.emplace_back(0);
    ans.emplace_back(G[0][0]);
  }

  cout << ans.size() << "\n";
  REP(i, ans.size()) {
    cout << ans[i]+1;
    if(i != ans.size() - 1)cout << " ";
  }
  cout << endl;
}