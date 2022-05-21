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
void dijkstra(const vector<vector<Edge>>& G, int s, vector<ll>& dis) {
  int N = G.size();
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
}
int main() {
  int N, u, v;
  cin >> N >> u >> v,u--,v--;
  vector<vector<Edge>> G(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(Edge{ b,1 });
    G[b].emplace_back(Edge{ a,1 });
  }
  vector<ll> dis_u, dis_v;
  dijkstra(G, u, dis_u);
  dijkstra(G, v, dis_v);
  ll ans = 0;
  REP(i, N) {
    if(dis_u[i] < dis_v[i]) {
      ans = max(ans, dis_v[i] - 1);
    }
  }
  cout << ans << endl;
}