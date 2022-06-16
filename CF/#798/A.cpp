#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<string> ans;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  string a, b;
  cin >> a >> b;
  sort(a.begin(), a.end(), greater<>());
  sort(b.begin(), b.end(), greater<>());
  string c;
  int a_cnt = 0, b_cnt = 0;
  while (not(a.size() == 0 || b.size() == 0)) {
    if (a.empty() || b.empty()) break;
    if (a_cnt == k) {
      c += b.back();
      b.pop_back();
      a_cnt = 0;
      b_cnt = 1;
      continue;
    }
    if (b_cnt == k) {
      c += a.back();
      a.pop_back();
      b_cnt = 0;
      a_cnt = 1;
      continue;
    }
    int t = 0;
    if (!a.empty() && !b.empty()) {
      if (a.back() < b.back())
        t = 0;
      else
        t = 1;
    } else if (a.empty()) {
      t = 1;
    } else {
      t = 0;
    }
    if (t == 0) {
      a_cnt++;
      b_cnt = 0;
      c += a.back();
      a.pop_back();
    } else {
      b_cnt++;
      a_cnt = 0;
      c += b.back();
      b.pop_back();
    }
  }
  ans.emplace_back(c);
  // cout << c << endl;
}
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
  for (auto a : ans) cout << a << "\n";
}