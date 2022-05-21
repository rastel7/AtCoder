#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<int> topological(const vector<vector<int>>& G) {
  vector<int> ans;
  int n = (int)G.size();
  vector<int> ind(n);//各頂点から出ている有向辺の次数
  for(int i = 0;i < n;++i) {
    for(auto& e : G[i]) {
      ind[e]++;
    }
  }
  queue<int> que;
  for(int i = 0;i < n;++i) {
    if(ind[i] == 0)que.push(i);
  }
  while(!que.empty()) {
    int now = que.front();
    ans.push_back(now);
    que.pop();
    for(auto& e : G[now]) {
      ind[e]--;
      if(ind[e] == 0) que.push(e);
    }
  }
  return ans;
}
const ll INF = 1e18;
vector<ll> dp;
vector<ll> ch;
ll dfs(int id, vector<ll> const& T, vector<vector<ll>> const& A) {
  if(dp[id] != -1)return dp[id];
  ch.emplace_back(id);
  ll ret = 0;
  for(auto const& x : A[id]) {
    ret = max(ret, dfs(x, T, A));
  }
  return dp[id] = ret + T[id];
}

int main() {
  int N;
  cin >> N;
  vector<ll> T(N), cnt(N);
  dp.resize(N, -1);
  vector<vector<ll>> A(N);
  REP(i, N) {
    cin >> T[i];
    ll k;
    cin >> k;
    A[i].resize(k);
    cnt[i] = k;
    REP(j, k) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  dfs(N - 1, T, A);
  ll ans = 0;
  REP(i, ch.size())ans += T[ch[i]];
  cout << ans << endl;
}