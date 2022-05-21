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
  }
  ll tmp = 0;
  vector<ll> ans = { 0 };
  dsu uf(N);
  for(int i = N - 1;i >= 0;i--) {
    tmp++;
    for(auto r : G[i]) {
      if(!uf.same(r, i)) {
        uf.merge(i, r);
        tmp--;
      } 
    }
    if(i != 0)ans.emplace_back(tmp);
  }
  reverse(ans.begin(), ans.end());
  for(auto a : ans) {
    cout << a << endl;
  }
}