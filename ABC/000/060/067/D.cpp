#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
bool to_n(int now, int prev, vector<vector<int>> const& G, vector<ll>& p) {
  if(now == G.size() - 1)return true;
  for(auto& x : G[now]) {
    if(x != prev) {
      p.emplace_back(x);
      if(to_n(x, now, G, p)) {
        return true;
      }
      p.pop_back();
    }
  }
  return false;
}
int dfs(int now, int prev, vector<vector<int>> const& G) {
  ll ret = 1;
  for(auto x : G[now]) {
    if(x == prev) {
      continue;
    }
    ret += dfs(x, now, G);
  }
  return ret;
}
int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  vector<ll> keiro = { 0 };
  to_n(0, -1, G, keiro);
  int f = keiro[(keiro.size() - 1) / 2];
  int s = keiro[1 + (keiro.size() - 1) / 2];
  if(dfs(f, s, G) > dfs(s, f, G)) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
}