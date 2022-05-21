#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
mint dp[3100][3100];
int main() {
  int N, S;
  cin >> N >> S;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  dp[0][0] = 1;
  REP(i, N)REP(j, S+1) {
    if(j + A[i] <= S)dp[i + 1][j + A[i]] += dp[i][j];
    dp[i + 1][j] += 2 * dp[i][j];//Tに入れるのと，Tにいれないの
  }
  cout << dp[N][S].val() << endl;
}