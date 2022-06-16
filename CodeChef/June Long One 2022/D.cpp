#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll a = 1, b = N;
  for (int i = N - 1; i >= 0; i--) {
    if (i % 2 == 0) {
      A[i] = b--;
    } else {
      A[i] = a++;
    }
  }
  //reverse(A.begin(), A.end());
  REP(i, N) {
    cout << A[i];
    if (i + 1 != N) {
      cout << " ";
    }
  }
  cout << "\n";
}
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
}