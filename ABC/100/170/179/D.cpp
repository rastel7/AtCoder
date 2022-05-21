#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
int main() {
  int N, K;
  cin >> N >> K;
  vector<mint> dp(N + 10);
  vector<pair<int, int>> A(K);
  REP(i, K) {
    cin >> A[i].first >> A[i].second;
  }
  dp[1] = 1;
  mint tmp = 0;
  for(int i = 1;i < N;++i) {
    tmp += dp[i];
    for(auto [l, r] : A) {
      if(i + l < N + 3)
        dp[i + l] += tmp;
      if(i + r + 1 < N + 3)
        dp[i + r + 1] -= tmp;
    }
  }
  cout << dp[N].val() << endl;
}