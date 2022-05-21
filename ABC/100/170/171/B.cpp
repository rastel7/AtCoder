#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N)cin >> A[i];
  sort(A.begin(), A.end());
  ll ans = 0;
  REP(i, K)ans += A[i];
  cout << ans << endl;
}