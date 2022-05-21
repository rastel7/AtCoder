#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
//牛ゲー
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
int L[210101], R[210101], X[210101];
int main() {
  int N, M;
  cin >> N >> M;
  REP(i, M) {
    cin >> L[i] >> R[i] >> X[i];
  }
  vector<vector<Edge>> G(N + 1);
  REP(i, N) {
    G[i + 1].emplace_back(Edge{ i,0 });
    G[i].emplace_back(Edge{ i + 1,1 });
  }
  REP(i, M) {
    G[L[i]-1].emplace_back(Edge{ R[i] ,R[i] - L[i] + 1 - X[i] });
  }
  vector<ll> v;
  dijkstra(G, 0, v);
  REP(i, N) {
    if(v[i] == v[i + 1]) {
      cout << "1 ";
    } else {
      cout << "0 ";
    }
  }
  cout << endl;
}