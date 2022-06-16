#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct Q {
  int y0, x0, y1, x2;
};
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  REP(i, H) {
    REP(j, W) { cin >> A[i][j]; }
  }
  vector<Q> ans;
  set<pair<int, int>> s;
  REP(i, H) REP(j, W) {
    if (A[i][j] % 2 == 0) continue;
    if (i != H - 1) {
      ans.emplace_back(Q{i, j, i + 1, j});
      A[i + 1][j]++;
      A[i][j]--;
      continue;
      if (A[i + 1][j] != 0 && !s.count({i + 1, j})) {
        ans.emplace_back(Q{i + 1, j, i, j});
        A[i + 1][j]--;
        A[i][j]++;
        s.insert({i + 1, j});
        continue;
      }
    }
    if (j != W - 1) {
      ans.emplace_back(Q{i, j, i, j + 1});
      A[i][j + 1]++;
      A[i][j]--;
      continue;
      if (A[i][j + 1] != 0 && !s.count({i, j + 1})) {
        ans.emplace_back(Q{i, j + 1, i, j});
        A[i][j + 1]--;
        A[i][j]++;
        s.insert({i, j + 1});
        continue;
      }
    }
  }
  cout << ans.size() << endl;
  for (auto [a, b, c, d] : ans) {
    printf("%d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);
  }
}