#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll N, X, Y;
ll A[20], B[20];
ll dp[(1 << 20)];
const ll INF = 1e18;
void chmin(ll& a, ll b) {
  a = min(a, b);
}
ll inv(ll S, ll x) {
  ll ret = 0;
  for(int j = 0;j < N;++j) {
    if(((S >> j) & 1)||j>=x)continue;
    ret++;
  }
  return ret;
}
int main() {
  cin >> N >> X >> Y;
  vector<ll> A(N);
  REP(i, 1 << 20)dp[i] = INF;
  REP(i, N)cin >> A[i];
  REP(i, N)cin >> B[i];
  dp[0] = 0;
  for(int i = 0;i < (1 << N);++i) {
    int siz=__builtin_popcount(i);
    REP(j, N) {
      if((i >> j) & 1)continue;
      chmin(dp[i | (1 << j)], dp[i]+abs(B[j] - A[siz]) * X + inv(i, j) * Y);
    }
  }
  cout << dp[(1 << N) - 1] << endl;
}