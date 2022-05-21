#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  vector<int> char_cnt(26, 0);
  for(auto c : s)char_cnt[c - 'a']++;
  for(auto c : t) {
    if(char_cnt[c - 'a'] == 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  ll ans = 0;
  int N = s.size();
  vector<vector<int>> c_pos(N + 1, vector<int>(26, -1));
  for(int i = N - 1;i >= 0;i--) {
    REP(j, 26) {
      c_pos[i][j] = c_pos[i + 1][j];
    }
    c_pos[i][s[i] - 'a'] = i;
  }
  REP(i, t.size()) {
    int c = t[i] - 'a';
    if(c_pos[ans % N][c] == -1) {
      ans = ((ans + N - 1) / N) * N;
    }
    ans += c_pos[ans % N][c] - (ans % N) + 1;
  }
  cout << ans << endl;
}