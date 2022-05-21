#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N, K;
int b[2002][2002];
int s[4002][4002];
int get(int x, int y) {
  return s[x + K - 1][y + K - 1] + s[x - 1][y - 1] - s[x - 1][y + K - 1] - s[x + K - 1][y - 1];
}
int main() {
  cin >> N >> K;
  REP(i, N) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    if(c == 'W')y += K;
    ++b[x % (2 * K) + 1][y % (2 * K) + 1];
  }
  for(int i = 1;i < 4 * K + 1;++i) {
    for(int j = 1;j < 4 * K + 1;++j) {
      s[i][j] = s[i][j - 1] + b[(i - 1) % (2 * K) + 1][(j - 1) % (2 * K) + 1];
    }
  }
  for(int i = 1;i < 4 * K + 1;++i) {
    for(int j = 1;j < 4 * K + 1;++j) {
      s[i][j] += s[i - 1][j];
    }
  }
  int ans = 0;
  for(int i = 1;i < 2 * K + 1;++i) {
    for(int j = 1;j < 2 * K + 1;++j) {
      ans = max(ans, get(i, j) + get(i + K, j + K));
    }
  }
  cout << ans << endl;
}