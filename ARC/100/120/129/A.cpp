#include<bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;

int main() {
  ll N, L, R;
  cin >> N >> L >> R;
  ll ans = 0;
  REP(i, 64) {
    if(((N >> i) & 1ll) == 0)continue;
    ll low = (1ll << i);
    if(low > R)continue;
    ll num = min(((1ll << (i + 1)) - 1), R);
    num -= max(L - 1, (1ll << i) - 1);
    if(num > 0)ans += num;
  }
  cout << ans << endl;
}