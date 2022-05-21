#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll f(ll x) {
  return x * x + 2 * x + 3;
}
int main() {
  ll t;
  cin >> t;
  cout << f(f(f(t) + t) + f(f(t))) << endl;
}