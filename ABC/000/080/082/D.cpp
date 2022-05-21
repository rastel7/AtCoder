#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  vector<vector<int>> D(2);
  int sum = 0, now = 0;
  REP(i, s.size()) {
    if(s[i] == 'T') {
      if(now != 0) {
        D[sum % 2].emplace_back(now);
        now = 0;
      }
      sum++;
    } else {
      now++;
    }
    if(now != 0 && i == (int)s.size() - 1) {
      D[sum % 2].emplace_back(now);
      now = 0;
    }
  }
  auto f = [](int obj, vector<int> X) {
    map<int, bool> dp;
    dp[0] = 1;
    REP(i, X.size()) {
      map<int, bool> next;
      for(auto [l, b] : dp) {
        next[l + X[i]] = 1;
        next[l - X[i]] = 1;
      }
      dp = next;
    }
    return dp.count(obj);
  };
  if(D[0].size() != 0 && s[0] != 'T') {
    x -= D[0][0];
    D[0].erase(D[0].begin());
  }
  if(f(x, D[0]) && f(y, D[1])) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}