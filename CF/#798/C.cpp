#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<int> ans;
struct Vert {
  int id, child;
  bool operator<(const Vert rhs) const {
    return child == rhs.child ? id > rhs.id : child > rhs.child;
  }
  bool operator<(Vert rhs) {
    return child == rhs.child ? id > rhs.id : child > rhs.child;
  }
};
int dfs(int id, int prev, vector<int>& num, vector<vector<int>> const& G,
        vector<int>& ancester, vector<int>& dist) {
  if (prev == -1) {
    dist[id] = 0;
  } else {
    dist[id] = dist[prev] + 1;
  }
  int ret = 1;
  ancester[id] = prev;
  for (auto a : G[id]) {
    if (a != prev) {
      ret += dfs(a, id, num, G, ancester, dist);
    }
  }
  return num[id] = ret;
}
void erase(int id, int prev, set<Vert>& s, vector<vector<int>> const& G,
           vector<int> const& child_num) {
  for (auto const& a : G[id]) {
    if (a != prev) {
      erase(a, id, s, G, child_num);
    }
  }
  s.erase(Vert{id, child_num[id]});
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 1);
  vector<vector<int>> G(n);
  vector<int> child_num(n), ancester(n), dist(n);
  REP(i, n - 1) {
    cin >> a[i] >> b[i], a[i]--, b[i]--;
    G[a[i]].emplace_back(b[i]);
    G[b[i]].emplace_back(a[i]);
  }
  dfs(0, -1, child_num, G, ancester,dist);
  vector<pair<int, int>> infected;
  set<Vert> s;
  for (int i = 1; i < n; ++i) {
    s.insert(Vert{i, child_num[i]});
  }
  int ret = 0;
  infected.emplace_back(pair<int, int>{0, -1});
  while (!s.empty()) {
    int target = (*s.begin()).id;
    ret += (*s.begin()).child - 1;
    erase(target, ancester[target], s, G, child_num);
    vector<pair<int, int>> next;
    for (auto [l, r] : infected) {
      for (auto a : G[l]) {
        if (a != r && s.count(Vert{a, child_num[a]})) {
          next.emplace_back(pair<int, int>{a, l});
          s.erase(Vert{a, child_num[a]});
        }
      }
    }
    infected = next;
  }
  ans.emplace_back(ret);
}
int main() {
  int t;
  cin >> t;
  REP(i, t) solve();
  for (auto a : ans) {
    cout << a << "\n";
  }
}