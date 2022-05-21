#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
//整数での三部探索
template<class F>
ll optimize(int low, int high, const F& f) {
  while(high - low > 2) {
    const int m1 = (low + high) / 2;
    const int m2 = m1 + 1;
    if(f(m1) < f(m2)) {
      low = m1;
    } else {
      high = m2;
    }
  }
  return f(low + 1);
}

void solve() {
  int n, m;
  cin >> n >> m;
  ll a = 0, b = 0, ans = numeric_limits<ll>::min();
  REP(i, n) {
    ll x, y;
    cin >> x >> y;
    auto f = [&](ll k) {
      return a + b * k + x * k * (k + 1) / 2;
    };
    if(x > 0) {
      ans = max(ans, f(1));
      ans = max(ans, f(y));
    } else {
      ans = max(ans, optimize(0, y + 1, f));
    }
    a = f(y);
    b += x * y;
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}