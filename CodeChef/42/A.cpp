#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  ll X, Y, A;
  cin >> X >> Y >> A;
  if (X <= A && A < Y) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  int T;
  cin >> T;
  REP(i,T)solve();
}