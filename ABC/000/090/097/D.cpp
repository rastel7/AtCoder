#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  REP(i, N)cin >> P[i], P[i]--;
  dsu uf(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    if(!uf.same(a, b)) {
      uf.merge(a, b);
    }
  }
  int ans = 0;
  REP(i, N) {
    if(uf.same(i, P[i]))ans++;
  }
  cout << ans << endl;
}