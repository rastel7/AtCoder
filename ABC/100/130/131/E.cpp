#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  if(K > (N - 1) * (N - 2) / 2) {
    cout << -1 << endl;
    return 0;
  }
  int now = (N - 1) * (N - 2) / 2;
  vector<vector<int>> G(N);
  REP(i, N) {
    if(i != 0) {
      G[0].emplace_back(i);
    }
  }
  for(int i = 1;i < N;++i) {
    for(int j = i + 1;j < N;++j) {
      if(now == K)break;
      G[i].emplace_back(j);
      now--;
    }
  }
  int cnt = 0;
  for(auto& e : G)cnt += e.size();
  cout << cnt << endl;
  REP(i, G.size()) {
    REP(j, G[i].size()) {
      cout << i + 1 << " " << G[i][j] + 1 << endl;
    }
  }
}