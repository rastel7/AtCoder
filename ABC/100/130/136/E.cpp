#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll N, K;
vector<ll> A;
bool f(ll x) {
  ll k = 0;
  sort(A.begin(), A.end(), [&](ll a, ll b) {
    return a % x < b% x;
    });
  ll mn = 0, pl = 0;
  for(auto a : A) {
    ll t1 = a - (a / x) * x;
    if(mn + t1 <= K) {
      mn += t1;
      continue;
    }
    ll t2 = ((a + x - 1) / x) * x - a;
    pl += t2;
  }
  return pl <= K;
}
int main() {
  cin >> N >> K;
  A.resize(N);
  REP(i, N)cin >> A[i];
  ll sum = 0;
  REP(i, N)sum += A[i];
  ll ans = 0;
  for(ll l = 1;l <= sum / l;++l) {
    if(sum % l != 0)continue;
    if(f(l)) {
      ans = max(l, ans);
    }
    if(f(sum / l)) {
      ans = max(sum / l, ans);
    }
  }
  cout << ans << endl;
}