#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

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
int D[201010];
int main() {
  int N;
  cin >> N;
  vector<vector<Edge>> G(N * 2);
  REP(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    G[a].emplace_back(Edge{ b,c });
    G[b].emplace_back(Edge{ a,c });
  }
  REP(i, N) {
    cin >> D[i];
    G[i].emplace_back(Edge{ N + i,D[i] });
    G[N + i].emplace_back(Edge{ i,D[i] });
  }
  int s = 0, t = 0;
  auto v = dijkstra(G, 0);
  REP(i, v.size()) {
    if(v[i] > v[s]) {
      s = i;
    }
  }
  auto l = dijkstra(G, s);
  REP(i, l.size()) {
    if(l[i] > l[t]) {
      t = i;
    }
  }
  v = dijkstra(G, t);
  REP(i, N) {
    if(i == s-N) {
      cout << l[t]-D[s-N] << "\n";
    } else if(i == t-N) {
      cout << v[ s] -D[t-N]<< "\n";
    } else {
      cout << max(v[i], l[ i]) << "\n";

    }
  }
}