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
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M), C(M);
  REP(i, M) {
    cin >> A[i] >> B[i] >> C[i], A[i]--, B[i]--;
  }
  int ans = 0;
  REP(i, M) {
    vector<vector<Edge>> G(N);
    REP(j, M) {
      if(i != j) {
        G[A[j]].emplace_back(Edge{ B[j],C[j] });
        G[B[j]].emplace_back(Edge{ A[j],C[j] });
      }
    }
    vector<ll> dis;
    dijkstra(G, A[i], dis);
    if(dis[B[i]] < C[i])ans++;
  }
  cout << ans << endl;
}
