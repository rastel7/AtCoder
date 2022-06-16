#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  if (N % 2 == 1) {
    cout << "-1" << endl;
    return ;
  }
  ll sum = accumulate(A.begin(), A.end(), 0ll);
  cout << abs(sum) / 2 << endl;
}
int main() {
  ll T;
  cin >> T;
  REP(i, T) solve();
}