#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
  int N, C;
  cin >> N >> C;
  vector<vector<int>> imos(32, vector<int>(1e5 + 100));
  REP(i, N) {
    int l, r, c;
    cin >> l >> r >> c, r++;
    imos[c][l]++;
    imos[c][r]--;
  }

  REP(i, 31)REP(j, 1e5 + 10) {
    if(imos[i][j] == 1 && imos[i][j + 1] == -1) {
      imos[i][j] = 0, imos[i][j + 1] = 0;
    }
  }
  REP(i, 1e5 + 10) {
    REP(j, 31) {
      imos[j][i + 1] += imos[j][i];
    }
  }

  int ans = 0;
  REP(i, 1e5 + 10) {
    int sm = 0;
    REP(j, 31) {
      sm += imos[j][i];
    }
    ans = max(ans, sm);
  }
  cout << ans << endl;
}