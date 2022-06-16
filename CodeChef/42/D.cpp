#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  ll A, B;
  cin >> A >> B;
  if (A % 3 == 0 || B % 3 == 0) {
    cout << 0 << endl;
    return;
  }
  if (A % 3 == B % 3) {
    cout << 1 << endl;
    return;
  }
  cout << 2 << endl;
}
int main() {
  ll T;
  cin >> T;
  REP(i, T) solve();
}