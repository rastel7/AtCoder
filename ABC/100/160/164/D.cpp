#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int dp[2030];
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while(n > 0) {
    if(n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  int prev = 0;  dp[0]++;
  for(int i = 0;i < S.size();++i) {
    int next = modpow(10, i, 2019) * (S[i] - ('0')) + prev;
    next %= 2019;
    dp[next]++;
    prev = next;
  }
  ll ans = 0;
  REP(i, 2019) {
    ans += dp[i] * (dp[i] - 1) / 2;
  }
  cout << ans << endl;
}