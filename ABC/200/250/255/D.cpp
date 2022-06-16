#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> X(Q);
  REP(i, Q) cin >> X[i];
  sort(A.begin(), A.end());
  vector<ll> Wa(N + 1);
  REP(i, N) Wa[i + 1] += Wa[i] + A[i];
  REP(i, Q) {
    ll x = X[i];
    auto l = lower_bound(A.begin(), A.end(), x);
    auto r = upper_bound(A.begin(), A.end(), x);
    ll sum = 0;
    if (l != A.begin()) {
      ll j = distance(A.begin(), l) - 1;
      auto tmp = Wa[j + 1];
      auto tmp2 = (j + 1) * x;
      sum += tmp2 - tmp;
    }
    if (r != A.end()) {
      ll j = distance(A.begin(), r);
      auto tmp = Wa[N] - Wa[j];
      auto tmp2 = (N - j) * x;
      sum += tmp - tmp2;
    }
    cout << sum << "\n";
  }
}