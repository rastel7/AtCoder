#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int H, W, K;
int search(vector<string> const& S, vector<int> const& tate) {
  vector<int> cnt(tate.size()+1);
  int ans = 0;
  REP(i, S[0].size()) {
    int id = 0;
    vector<int> cp = cnt, now(tate.size()+1);
    REP(j, S.size()) {
      if(tate.size() > id) {
        if(tate[id] == j) id++;
      }
      if(S[j][i] == '1') {
        cnt[id]++;
        now[id]++;
      }
      if(cnt[id] > K) {
        ans++;
        cnt = now;
      }
    }
    for(auto x : cnt) {
      if(x > K) {
        return 1e9;
      }
    }
  }
  return tate.size() + ans;
}
int main() {
  cin >> H >> W >> K;
  vector<string> S(H);
  REP(i, H)cin >> S[i];
  int ans = 1e9;
  for(int i = 0;i < (1 << (H - 1));++i) {
    vector<int> Tate;
    REP(j, H) {
      if((i >> j) & 1)Tate.emplace_back(j + 1);
    }
    ans = min(ans, search(S, Tate));
  }
  cout << ans << endl;
}