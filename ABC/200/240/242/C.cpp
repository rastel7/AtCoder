#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
mint dp[12][2020200];
int main() {
  ll N;
  cin >> N;
  for(int i = 1;i <= 9;++i) {
    dp[i][1] = 1;
  }
  for(int i = 1;i < N;++i) {
    for(int k = 1;k <= 9;++k) {
      for(int j = k - 1;j <= k + 1;j++) {
        if(j <= 0 || j > 9)continue;
        dp[j][i+1] += dp[k][i];
      }
    }
  }
  mint ans = 0;
  for(int i = 1;i <= 9;++i)ans += dp[i][N];
  cout << ans.val() << endl;
}