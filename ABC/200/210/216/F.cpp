#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
mint dp[5010][5010];
int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N)cin >> A[i];
  REP(i, N)cin >> B[i];
  vector<pair<ll, ll>> P(N);
  REP(i, N)P[i] = { A[i],B[i] };
  sort(P.begin(), P.end());
  REP(i, N) {
    A[i] = P[i].first, B[i] = P[i].second;
  }
  dp[0][0] = 1;
  mint ans = 0;
  REP(i, N) {
    REP(j, 5009) {
      dp[i + 1][j] += dp[i][j];
    }
    for(int j = 0;j + B[i] < 5005;++j) {
      dp[i + 1][j + B[i]] += dp[i][j];
    }
    for(int j = 0;j+B[i] <= A[i];++j) {
      ans += dp[i][j];
    }
  }
  cout << ans.val() << endl;
}