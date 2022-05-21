#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<int> ans;
vector<int> G[1100];
int checked[1100], passed[1100];
int N, M;
void dfs(int id) {
  vector<int> ret(N, -1);
  queue<int> que;
  REP(i, N)checked[i] = 0;
  que.push(id);
  while(!que.empty()) {
    auto i = que.front();que.pop();
    if(checked[i] == 1)continue;
    checked[i] = 1;
    for(auto a : G[i]) {
      if(a == id) {
        vector<int> v;
        int now = i;
        while(true) {
          v.emplace_back(now);
          if(now == id) {
            if(ans.empty() || ans.size() > v.size()) {
              ans = v;
            }
            return;
          }
          now = ret[now];
        }
      }
      if(checked[a] == 1)continue;
      ret[a] = i;
      que.push(a);
    }
  }
}
int main() {
  cin >> N >> M;
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(b);
  }
  REP(i, N) {
    //if(checked[i])continue;
    dfs(i);
  }
  if(ans.empty()) {
    cout << -1 << endl;
  } else {
    cout << ans.size() << "\n";
    for(auto i : ans) {
      cout << i + 1 << "\n";
    }
  }
}