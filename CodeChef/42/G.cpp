#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  ll N, K;
  cin >> N >> K;
  ll first = K;
  ll ans = 0;
  REP(i, K) {
    if (K <= 0) break;
    ll num = (1ll << i);
    if (num - 1 > first) break;
    if (num * N <= K) {
      ans += N;
      K -= num * N;
      {
        auto k = K >> i;
        if (k & 1) {
          K += num;
          ans--;
        }
      }
    } else {
      ll add = K / num;
      ans += add;
      K -= add * num;
      break;
    }
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
}