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
void chmin(ll& a, ll b) {
  a = min(a, b);
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<Edge>> G(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(Edge{ b,1 });
    G[b].emplace_back(Edge{ a,1 });
  }
  int c;
  cin >> c;
  vector<int> C(c);
  vector<vector<ll>> dist(c, vector<ll>(c, 1e16));
  REP(i, c) cin >> C[i], C[i]--;
  REP(i, c) {
    vector<ll> dis;
    dijkstra(G, C[i], dis);
    REP(j, c) {
      dist[i][j] = dis[C[j]];
    }
  }
  vector<vector<ll>> dp(1 << c, vector<ll>(c, 1e18));
  REP(i, c) {
    dp[1 << i][i] = 1;
    //dp[0][i] = 0;
  }
  for(ll i = 0;i < (1 << c);++i) {
    for(ll k = 0;k < c;++k) {
      for(ll j = 0;j < c;++j) {
        if(i & (1 << j))continue;
        chmin(dp[i | (1 << j)][j], dp[i][k] + dist[k][j]);
      }
    }
  }
  ll ans = 1e18;
  REP(i, c)chmin(ans, dp[(1 << c) - 1][i]);
  if(ans == 1e18)ans = -1;
  cout << ans << endl;
}