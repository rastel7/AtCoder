#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  ll A, B;
  cin >> A >> B;
  if ((B - A) % 3 == 2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
}