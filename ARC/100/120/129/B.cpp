#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void f(ll L, ll R) {
  if(R >= L) {
    cout << 0 << endl;
    return;
  }
  cout << max(L - (L + R) / 2, (L + R) / 2 - R) << endl;
}
int main() {
  int N;
  cin >> N;
  ll L, R;
  cin >> L >> R;
  f(L, R);
  REP(i, N - 1) {
    ll l, r;
    cin >> l >> r;
    L = max(L, l);
    R = min(R, r);
    f(L, R);
  }
}