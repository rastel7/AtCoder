#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<vector<ll>> B(K);
  REP(i, N) { B[i % K].emplace_back(A[i]); }
  REP(i, K) { sort(B[i].begin(), B[i].end()); }
  REP(i, N) { A[i] = B[i % K][i / K]; }
  bool asc = true;
  REP(i, N - 1) {
    if (A[i] > A[i + 1]) {
      asc = false;
    }
  }
  if (asc) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}