#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll f(ll a, ll d, ll n) { return a + d * (n - 1); }
int main() {
  ll X, A, D, N;
  cin >> X >> A >> D >> N;
  ll ans = 0;
  ll mn = min(f(A, D, 1), f(A, D, N));
  ll mx = max(f(A, D, 1), f(A, D, N));
  cerr << f(A, D, N) << ";" << f(A, D, 1) << endl;
  if (mn <= X && X <= mx && D != 0) {
    ll tmp = X - A;
    ll mod;
    if (tmp > 0) {
      mod = tmp % D;
    } else {
      tmp = abs(tmp);
      D = abs(D);
      mod = tmp % D;
    }
    ans = min(D - mod, mod);
  } else {
    ans = min(abs(X - f(A, D, 1)), abs(X - f(A, D, N)));
  }
  cout << ans << endl;
}