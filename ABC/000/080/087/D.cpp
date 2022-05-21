#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct edge {
  ll  to, dist;
};
map<ll, bool> dp;
vector<ll> pos;
bool search(int id, int prev, int dist, vector<vector<edge>> const& G) {
  if(pos[id] != -1) {
    if(pos[id] - pos[prev] != dist)return false;
  }
  if(dp.count(id))return dp[id];
  pos[id] = pos[prev] + dist;
  bool ret = 1;
  for(auto& x : G[id]) {
    ret &= search(x.to, id, x.dist, G);
  }
  return dp[id] = ret;
}

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
int main() {
  int N, M;
  cin >> N >> M;
  pos.resize(N, -1);
  vector<vector<edge>> G(N);
  vector<vector<int>> tp(N);
  vector<int> to_edge(N);
  REP(i, M) {
    int l, r, d;
    cin >> l >> r >> d, l--, r--;
    tp[l].emplace_back(r);
    G[l].emplace_back(edge{ r,d });
    to_edge[r]++;
  }
  auto tps = topological(tp);
  if(tps.size() != tp.size()) {
    cout << "No" << endl;
    return 0;
  }
  REP(i, N) {
    if(to_edge[i] == 0) {
      pos[i] = 0;
      for(auto& x : G[i]) {
        if(!search(x.to, i, x.dist, G)) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}