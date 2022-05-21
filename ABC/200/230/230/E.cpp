#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll N;
bool f(ll x, ll obj) {
  if(N / x != obj)return false;
  return true;
}
int main() {

  cin >> N;
  ll ans = 0;
  ll l = 1, r;
  while(true) {
    ll def = l;
    r = 1e16;
    ll obj = N / l;
    while(r - l > 1) {
      ll mid = l + (r - l) / 2;
      if(f(mid, obj)) {
        l = mid;
      } else {
        r = mid;
      }
    }

    ans += (l - def + 1) * (N / def);
    //cerr << l << ":" << def << " " << ans << ":" << (l - def + 1) * (N / def) << "\n";
    l++;
    if(l == N + 1)break;
  }
  cout << ans << endl;
}