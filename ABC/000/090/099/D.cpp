#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, C;
  cin >> N >> C;
  vector<vector<int>> D(C, vector<int>(C));
  REP(i, C)REP(j, C) {
    cin >> D[i][j];
  }
  vector<vector<int>> S(N, vector<int>(N));
  REP(i, N)REP(j, N)cin >> S[i][j], S[i][j]--;
  ll ans = 1e18;
  vector<vector<int>> cells(3, vector<int>(C, 0));
  REP(i, N)REP(j, N) {
    cells[(i + j) % 3][S[i][j]]++;
  }
  REP(a, C)REP(b, C)REP(c, C) {
    if(a == b || b == c || a == c)continue;
    ll tmp = 0;
    auto f = [&](int obj, vector<int> const& vec) {
      ll ret = 0;
      REP(i, vec.size()) {
        ret += D[i][obj] * vec[i];
      }
      return ret;
    };
    tmp = f(a, cells[0]) + f(b, cells[1]) + f(c, cells[2]);
   // cerr << a << ":" << b << ":" << c << "=" << tmp << endl;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}