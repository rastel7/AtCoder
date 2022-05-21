#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll y1, x1, y2, x2;
  cin >> y1 >> x1 >> y2 >> x2;
  REP(i, 2)REP(k, 2)REP(l, 2) {
    ll a, b;
    if(i == 0)a = 1ll, b = 2ll;
    else b = 1ll, a = 2ll;
    if(k == 1)a *= -1ll;
    if(l == 1)b *= -1ll;
    auto f = [](ll y, ll x, ll a, ll b) {
      return (y - a) * (y - a) + (x - b) * (x - b) == 5;
    };
    a += y1;
    b += x1;
    if(f(y1, x1, a, b) && f(y2, x2, a, b)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}