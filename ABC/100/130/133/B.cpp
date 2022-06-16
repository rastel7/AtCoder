#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  REP(i, N) REP(j, D) cin >> X[i][j];
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int sum = 0;
      REP(d, D) { sum += (X[i][d] - X[j][d]) * (X[i][d] - X[j][d]); }
      int sq = sqrt(sum - 1);
      while (sq * sq < sum) sq++;
      if (sq * sq == sum) ans++;
    }
  }
  cout << ans << endl;
}