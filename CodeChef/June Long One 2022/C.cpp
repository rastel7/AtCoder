#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  set<char> s;
  REP(i, n) {
    if (a[i] != b[i]) {
      s.insert(b[i]);
    }
  }
  cout << s.size() << endl;
}
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
}