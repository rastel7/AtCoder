#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<ll> eratho(ll n) {
  vector<ll> ret;
  vector<int> G(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    if (G[i] == 0) continue;
    ret.emplace_back(i);
    for (ll j = 2; j * i <= n; ++j) {
      G[i * j] = 0;
    }
  }
  return ret;
}
int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll i=1;i<=N;++i){
    ll k = i;
    for(ll d=2;d*d<=k;++d){
      while(k%(d*d)==0) k/=d*d;
    }
    for(ll d=1;k*d*d<=N;++d)ans++;
  }
  cout << ans << endl;
}