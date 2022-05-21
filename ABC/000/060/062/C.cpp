#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll f(ll H, ll W) {
  ll ret = 1e18;
  auto ab = [](ll a, ll b, ll c) {
    return max({ a, b, c }) - min({ a, b, c });
  };
  for(ll i = 1;i < H;++i) {
    ll h1 = i * W;
    ll tmp = H - i;
    ll h2 = W * (tmp / 2);
    ll h3 = W * ((tmp + 1) / 2);
    ret = min(ret, ab(h1, h2, h3));
    tmp = W / 2;
    h2 = (H - i) * (W / 2);
    h3 = (H - i) * ((W + 1) / 2);
    ret = min(ret, ab(h1, h2, h3));
  }
  return ret;
}
int main() {
  ll H, W;
  cin >> H >> W;
  cout << min(f(H, W), f(W, H)) << endl;
}