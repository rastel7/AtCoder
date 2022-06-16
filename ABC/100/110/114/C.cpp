#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int ans = 0;
ll N;
void dfs(ll x) {
  if (x > N) {
    return;
  }
  if (x != 0) {
    int f = 0, t = 0, g = 0;
    ll cp = x;
    while (cp != 0) {
      if (cp % 10 == 3) {
        f++;
      } else if (cp % 10 == 5) {
        t++;
      } else if (cp % 10 == 7) {
        g++;
      } else {
        f = -1e9;
      }
      cp /= 10;
    }
    if (f > 0 && g > 0 && t > 0) {
      ans++;
    }
  }
  dfs(x * 10 + 3);
  dfs(x * 10 + 5);
  dfs(x * 10 + 7);
  return;
}
int main() {
  cin >> N;
  dfs(0);
  cout << ans << endl;
}