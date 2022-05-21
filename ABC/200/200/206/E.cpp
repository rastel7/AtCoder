#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll l, r;
  cin >> l >> r;
  vector<ll>div(r + 1), x(r + 1);
  ll sum = 0;
  for(ll i = r;i > 1;i--) {
    ll x_k = r / i - (l - 1) / i;
    x[i] = x_k;
    x_k *= x_k;
    for(ll j = 2;j * i <= r;++j)x_k -= div[i * j];
    sum += x_k;
    div[i]=x_k;
  }
  for(ll i = max(2ll, l);i <= r;++i) {
    sum -= x[i] * 2 - 1;
  }
  cout << sum << endl;
}