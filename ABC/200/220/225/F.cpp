#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<string> s(n);
  REP(i, n)cin >> s[i];
  sort(s.rbegin(), s.rend(), [](string l, string r) {
    return l + r < r + l;
    });
  vector<string> dp(k + 1);
  auto chmin = [](string& a, string const& b) {
    if(b == "")return;
    if(a == "") { a = b;return; }
    a = min(a, b);
  };
  for(string a : s) {
    for(int j = k - 1;j >= 0;j--) {
      if(dp[j] == "" && j)continue;
      chmin(dp[j + 1], a + dp[j]);
    }
  }
  cout << dp[k] << endl;
}