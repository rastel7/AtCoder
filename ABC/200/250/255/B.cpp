#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(K);
  REP(i, K) cin >> A[i], A[i]--;
  vector<ll> X(N), Y(N);
  REP(i, N) { cin >> X[i] >> Y[i]; }
  long double ans = 0;
  for (int i = 0; i < N; ++i) {
    long double mx = 1e18;
    for (int j = 0; j < K; ++j) {
      long double dist = sqrt((X[i] - X[A[j]]) * (X[i] - X[A[j]]) +
                         (Y[i] - Y[A[j]]) * (Y[i] - Y[A[j]]));
      mx = min(mx, dist);
    }
    ans = max(mx, ans);
  }
  cout << fixed << setprecision(10) << ans << endl;
}