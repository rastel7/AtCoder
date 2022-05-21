#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  REP(i, N) {
    if(G[i].size() > 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  set<int> s;
  REP(i, N) {
    if(s.count(i))continue;
    queue<pair<int, int>> que;
    que.push({ i,-1 });
    while(!que.empty()) {
      auto [now, prev] = que.front();
      que.pop();
      s.insert(now);
      for(auto next : G[now]) {
        if(next == prev)continue;
        if(s.count(next)) {
          cout << "No" << endl;
          return 0;
        }
        que.push({ next,now });
      }
    }
  }
  cout << "Yes" << endl;
}