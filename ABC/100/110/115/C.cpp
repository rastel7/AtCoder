#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  sort(A.begin(), A.end());
  ll ans = 1e9;
  REP(i, N - K+1) {
    ans = min(ans, A[i + K-1] - A[i]);
  }
  cout << ans << endl;
}