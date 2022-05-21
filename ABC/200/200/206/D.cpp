#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll mem[2101010];
int main() {
  ll L, R;
  cin >> L >> R;
  for(ll i = 2;i <= R;++i) {
    if(mem[i] != 0)continue;
    for(ll j = i;j <= R;j += i) { mem[j]++; }
    for(ll j = i * i;j <= R;j += i * i) { mem[j] = -1e9; }
  }
  ll ans = 0;
  for(ll i = 2;i <= R;++i) {
    if(mem[i] < 0)continue;
    ll cc = R / i - ((L - 1) / i);
    if(mem[i] % 2) {
      ans += cc * (cc - 1) / 2;
    } else {
      ans -= cc * (cc - 1) / 2;
    }
  }
  for(ll i = max(2ll, L);i <= R;++i) {
    ans -= R / i - 1;
  }
  cout << ans*2 << endl;
}