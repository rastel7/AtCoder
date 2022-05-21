#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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
struct edge {
  int from, to, cost;
};
int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  REP(i, N)REP(j, N)cin >> A[i][j];
  REP(i, N)REP(j, N) {
    REP(k, N) {
      if(A[i][j] + A[j][k] < A[i][k]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  vector<edge> edges;
  REP(i, N)REP(j, N) {
    if(i < j) {
      edges.emplace_back(edge{ i,j,A[i][j] });
    }
  }
  sort(edges.begin(), edges.end(), [](edge l, edge r) {
    return l.cost < r.cost;
    });
  ll ans = 0;
  vector<vector<Edge>> G(N);
  for(auto e : edges) {
    vector<ll> dis;
    dijkstra(G, e.from, dis);
    if(dis[e.to] == e.cost)continue;
    ans += e.cost;
    G[e.from].emplace_back(Edge{ e.to,e.cost });
    G[e.to].emplace_back(Edge{ e.from,e.cost });
  }
  cout << ans << endl;
}