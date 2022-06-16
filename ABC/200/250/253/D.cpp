#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll N, A, B;
// 1000000000 2 3
// 166666666333333333
ll solve() {
  if (A == 1 || B == 1) {
    return 0;
  }
  if (A > B) swap(A, B);
  ll ans = N * (N + 1) / 2;
  /*
  for (long long a = A; a <= N; a += A) {
    ans -= a;
    ll g = a % B;
    if (g == 0) {
      ans += a;
    }
  }
  for (long long b = B; b <= N; b += B) {
    ans -= b;
  }*/

  ll a = N / A;
  a = (a + 1) * a / 2 * A;
  ans -= a;
  if (B % A != 0) {
    ll b = N / B;
    b = (b + 1) * b / 2 * B;
    ans -= b;
    ll gcd = A / __gcd(A, B) * B;
    //cerr << gcd << endl;
    ll ab = N / gcd;
    ab = (ab + 1) * ab / 2 * gcd;
    ans += ab;
  }
  return ans;
}
ll solve1() {
  ll ans = 0;
  for (ll i = 1; i <= N; ++i) {
    if (i % A != 0 && i % B != 0) {
      ans += i;
    }
  }
  return ans;
}
int main() {
  while (true) {
    cin >> N >> A >> B;
     cout << solve() << endl;
     return 0;
    //  341 6 63

    cerr << solve() << " " << solve1() << endl;
    if (solve() != solve1()) {
      cerr << N << " " << A << " " << B << endl;
    }
  }
}
