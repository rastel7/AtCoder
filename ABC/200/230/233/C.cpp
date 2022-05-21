#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, X;
  cin >> N >> X;
  vector<map<ll, ll>> A(N);
  REP(i, N) {
    int l;
    cin >> l;

    REP(j, l) {
      ll a;
      cin >> a;
      A[i][a]++;
    }
  }
  ll mx = 1;
  REP(i, N) {
    auto a = (*(A[i].begin())).first;
    if(mx > X / a) {
      cout << 0 << endl;
      return 0;
    }
    mx *= a;
  }
  if(mx > X) {
    cout << 0 << endl;
    return 0;
  }
  map<ll, ll> dp;
  dp[1] = 1;
  REP(i, N) {
    map<ll, ll> next;
    mx /= (*A[i].begin()).first;
    for(auto [l, r] : A[i]) {
      if(l > X / (*dp.begin()).first)continue;
      for(auto [a, b] : dp) {
        if(a > X / l)break;
        if(a * l > X / mx)break;
        next[a * l] += dp[a] * r;
      }
    }
    swap(dp, next);
  }
  cout << dp[X] << endl;
}