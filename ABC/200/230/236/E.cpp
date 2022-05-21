#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N;
ll A[101010];
void chmax(long double & a, long double  b) {
  a = max(a, b);
}
bool f(long double  x) {
  vector<long double > B(N);
  REP(i, N) {
    B[i] = A[i] * 1e3 - x;
  }
  long double  s0, t0, s1, t1;
  s0 = 0, t0 = 0;
  REP(i, N) {
    s1 = t0;
    t1 = max(s0, t0) + B[i];
    s0 = s1, t0 = t1;
  }
  return max(s0, t0) >= 0;
}
void solve1() {
  long double l = 0, r = 1e13;
  while((r - l) > 1e-4) {
    long double mid = l + (r - l) / 2;
    if(f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << (l + r) / 2 * 1e-3 << endl;
}
bool f2(ll x) {
  vector<ll> B(N);
  REP(i, N) {
    if(A[i] >= x)
      B[i] = 1;
    else
      B[i] = -1;
  }
  ll s0, t0, s1, t1;
  s0 = 0, t0 = 0;
  REP(i, N) {
    s1 = t0;
    t1 = max(s0, t0) + B[i];
    s0 = s1, t0 = t1;
  }
  return max(s0, t0) > 0;
}
void solve2() {
  ll l = 0, r = 1e9 + 100;
  while(r - l > 1) {
    double mid = l + (r - l) / 2;
    if(f2(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
}
int main() {
  cin >> N;
  REP(i, N)cin >> A[i];
  cout << fixed << setprecision(8);
  solve1();
  solve2();
}