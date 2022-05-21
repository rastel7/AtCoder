#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N;
pair<int, int> ans[210101];
vector<int> G[210101];

const ll INFll = 1LL << 60;
typedef pair<long, long> PL;
struct Edge {
  ll to;
  ll cost;
};
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる,負のコストの際利用できない
*/
vector<ll> dijkstra(const vector<vector<Edge>>& G, int s) {
  int N = G.size();
  vector<ll> dis;
  dis.resize(N, INFll);
  priority_queue<PL, vector<PL>, greater<PL>>
    pq;  //「仮の最短距離、頂点」が小さい順にならぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while(!pq.empty()) {
    PL p = pq.top();
    pq.pop();
    int v = p.second;
    if(dis[v] < p.first) continue;  //最短経路でなければ無視
    for(auto& e : G[v]) {
      if(dis[e.to] > dis[v] + e.cost) {  //最短距離候補ならpriority_queueに追加
        dis[e.to] = dis[v] + e.cost;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
  return dis;
}
int memo[210101];
int dfs_cnt(int i, int prev) {

  int ret = 0;
  ret += max<int>(G[i].size() - 1, 0);

  for(auto a : G[i]) {
    if(a == prev)continue;
    ret += dfs_cnt(a, i);
  }
  return memo[i] = ret;
}
void dfs(int id, int l, int r) {
  ans[id] = { l,r };

  for(auto a : G[id]) {
    //cerr<<a<<" "<<ne
    dfs(a, l, l + memo[a] );
    l += memo[a] +1;
  }
}
int main() {
  cin >> N;
  vector<int> u(N - 1), v(N - 1);
  REP(i, N - 1) {
    cin >> u[i] >> v[i];
  }
  vector<vector<Edge>> D(N + 1);
  REP(i, N - 1) {
    D[u[i]].emplace_back(Edge{ v[i],1 });
    D[v[i]].emplace_back(Edge{ u[i],1 });
  }
  auto dist = dijkstra(D, 1);
  REP(i, N - 1) {
    if(dist[u[i]] > dist[v[i]]) {
      swap(u[i], v[i]);
    }
    G[u[i]].emplace_back(v[i]);

  }
  cerr << dfs_cnt(1, -1) << endl;
  dfs(1, 1, 1 + memo[1]);
  REP(i, N) {
    cout << ans[i + 1].first << " " << ans[i + 1].second << endl;
  }
}