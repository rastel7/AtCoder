#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<vector<int>> ans;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  if (n == 1) {
    ans.emplace_back(vector<int>{-1});
    return;
  }
  set<int> s;
  REP(i, n) s.insert(i + 1);
  vector<int> add(n);
  REP(i, n) {
    int id = a[i];
    auto itr = s.begin();
    if (*itr == id) {
      itr++;
    }
    if (itr == s.end()) itr--;
    add[i] = *itr;
    s.erase(itr);
  }
  if (add.back() == a.back()) {
    swap(add[add.size() - 1], add[add.size() - 2]);
  }
  ans.emplace_back(move(add));
}
int main() {
  int t;
  cin >> t;
  REP(i, t) solve();
  for (auto const& v : ans) {
    REP(i, v.size()) {
      cout << v[i];
      if (i + 1 != v.size()) {
        cout << " ";
      }
    }
    cout << "\n";
  }
}