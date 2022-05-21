#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
using S = ll;
S op(S l, S r) {
  return max(l, r);
}
S e() { return 0; }
int main() {
  ll N, Q;
  cin >> N >> Q;
  ll h = N, w = N;
  ll ans = (N - 2) * (N - 2);
  segtree<S, op, e> H(N + 1), W(N + 1);
  H.set(N, N);
  W.set(N, N);
  while(Q--) {
    ll i, x;
    cin >> i >> x;
    if(i == 1) {
      if(x >= w) {
        ans -= H.prod(0, x)-2;
      } else {
        ans -= h - 2;
        H.set(x, h);
        w = x;
      }
    } else {
      if(x >= h) {
        ans -= W.prod(0, x)-2;
      } else {
        ans -= w - 2;
        W.set(x, w);
        h = x;
      }
    }
  }
  cout << ans << endl;
}