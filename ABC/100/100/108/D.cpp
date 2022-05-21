#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct edge {
  int to, cost;
};
int main() {
  ll L;
  cin >> L;

  int r = 0;
  while((1 << (r + 1)) <= L) {
    r++;
  }
  int N = r + 1;
  vector<vector<edge>> G(N);
  REP(i, N - 1) {
    G[i].emplace_back(edge{ i + 1,0 });
    G[i].emplace_back(edge{ i + 1,(1 << i) });

  }
  for(int i = N - 2;i >= 0;i--) {
    if((L - (1ll << (i))) >= (1 << r)) {
      G[i].push_back(edge{ N - 1,(L - (1ll << (i))) });
      L -= (1ll << (i));
    }
  }
  int m = 0;
  for(auto x : G)m += x.size();
  cout << N << " " << m << endl;
  REP(i, G.size()) {
    for(auto x : G[i]) {
      cout << i + 1 << " " << x.to + 1 << " " << x.cost << "\n";
    }
  }
}