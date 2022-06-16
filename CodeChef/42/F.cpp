#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  int N;
  cin >> N;
  vector<ll> B(N);
  REP(i, N) cin >> B[i];
  vector<vector<ll>> dp(2, vector<ll>(N + 1));
  dp[0][0] = 1e9;   // min
  dp[1][0] = -1e9;  // max
  bool ok = true;
  vector<ll> A(N, -1);
  A[0] = B[0];

  {
    ll mn, mx;
    mn = mx = A[0];
    for (int i = 1; i < N; ++i) {
      if (B[i] > mx) {
        A[i] = B[i];
      }
      if (B[i] < mn) {
        A[i] = B[i];
      }
      mn = min(B[i], mn);
      mx = max(B[i], mx);
    }
  }
  {
    ll mn, mx;
    mn = mx = A[0];
    REP(i, N) {
      if (A[i] == -1) {
        if (mn < B[i] && B[i] < mx) {
          cout << "NO" << endl;
          return;
        }
      }
      mn = min(B[i], mn);
      mx = max(B[i], mx);
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
}