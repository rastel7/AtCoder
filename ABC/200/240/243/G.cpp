#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll my_sqrt(ll x) {
  ll sqrtN = sqrt(x) - 1;
  while(sqrtN + 1 <= x / (sqrtN + 1))sqrtN++;
  return sqrtN;
}
int main() {

  ll T;
  cin >> T;
  vector<ll> ansV(T);
  REP(t, T) {
    ll X;
    cin >> X;
    ll sX = my_sqrt(X);
    ll sX4 = my_sqrt(sX);
    vector<ll> dp(sX4 + 3), wa(sX4 + 3);
    dp[1] = 1, wa[1] = 1;
    for(int i = 2;i <= sX4 + 1;++i) {
      ll l = 1, r = my_sqrt(i);
      dp[i] = wa[r];
      wa[i] = wa[i - 1] + dp[i];
    }
    ll ans = 0;
    for(ll i = 1;i <= sX4;++i) {
      ans += dp[i] * (sX - i * i + 1);
    }
    ansV[t] = ans;
  }

  for(auto a : ansV) {
    cout << a << "\n";
  }
}