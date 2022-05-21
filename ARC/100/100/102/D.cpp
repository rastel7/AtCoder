#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct Edge {
  ll  to, cost;
};
int main() {
  ll L;
  cin >> L;
  ll r = 0;
  while((1 << (1 + r)) <= L && r < 19) {
    r++;
  }
  vector<vector<Edge>> G(r + 1);
  REP(i, r) {
    G[i].emplace_back(Edge{ i + 1,0 });
    G[i].emplace_back(Edge{ i + 1,(1 << i) });
  }
  for(ll t = r - 1;t >= 0;t--) {
    if(L - (1 << (t)) >= (1 << (r))) {
      G[t].emplace_back(Edge{ r,L - (1 << (t)) });
      L -= (1 << (t));
    }
  }
  int cnt = 0;
  for(auto a : G) {
    cnt += a.size();
  }
  cout << r + 1 << " " << cnt << "\n";
  REP(i, G.size()) {
    REP(j, G[i].size()) {
      cout << i + 1 << " " << G[i][j].to + 1 << " " << G[i][j].cost << "\n";
    }
  }
}