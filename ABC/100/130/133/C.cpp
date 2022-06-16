#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll L, R;
  cin >> L >> R;
  ll ans = 1e9;
  for (ll l = L; l <= R; ++l) {
    if (ans == 0) break;
    for (ll r = l + 1; r <= R; ++r) {
      if (ans == 0) break;
      ans = min(ans, l * r % 2019ll);
    }
  }
  cout << ans << endl;
}