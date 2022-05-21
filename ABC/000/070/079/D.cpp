#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;

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
/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstraRestore(const vector<vector<Edge>>& G, int s, vector<ll>& dis,
  vector<int>& prev) {
  int N = G.size();
  dis.resize(N, INFll);
  prev.resize(N, -1);  // 初期化
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
        prev[e.to] = v;  // 頂点 v を通って e.to にたどり着いた
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}

/* get_path(prev, t)
    dijkstraRestore で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<int> get_path(const vector<int>& prev, int t) {
  vector<int> path;
  for(int cur = t; cur != -1; cur = prev[cur]) {
    path.push_back(cur);
  }
  reverse(path.begin(), path.end());//逆順なのでひっくり返す
  return path;
}
int c[10][10];
int main() {
  int H, W;
  cin >> H >> W;
  REP(i, 10)REP(j, 10)cin >> c[i][j];
  vector<vector<Edge>> G(10);
  REP(i, 10)REP(j, 10) {
    G[j].emplace_back(Edge{ i,c[i][j] });
  }
  vector<ll> dis;
  dijkstra(G, 1, dis);
  ll ans = 0;
  REP(i, H)REP(j, W) {
    int a;
    cin >> a;
    if(a == -1 )continue;
    ans += dis[a];
  }
  cout << ans << endl;
}