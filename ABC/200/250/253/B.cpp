#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> S(H);
  REP(i, H) cin >> S[i];
  int ly = -1, lx = -1, ry = -1, rx = -1;
  REP(y, H) REP(x, W) {
    if (S[y][x] == 'o') {
      if (ly != -1) {
        ry = y, rx = x;
      } else {
        ly = y, lx = x;
      }
    }
  }
  cout << abs(ry - ly) + abs(rx - lx) << endl;
}