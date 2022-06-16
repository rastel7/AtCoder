#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  if (N == 2) {
    cout << 1 << endl;
    return;
  }
  int ans = 1;
  REP(i, N - 2) {
    if (S[i] == '1' && S[i + 1] == '0') ans++;
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
}