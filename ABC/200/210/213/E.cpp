#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const int MAX_N = 510;
const int d[] = { -2,-1,0,1,2 };
const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };
int ret_id(int y, int x) {
  return y * MAX_N + x;
}
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
//参考:https://algo-logic.info/dijkstra/
int H, W;
bool OoR(int y, int x) {
  return x < 0 || y < 0 || x >= W || y >= H;
}
int main() {

  cin >> H >> W;
  vector<string> S(H);
  REP(i, H) {
    cin >> S[i];
  }
  vector<vector<Edge>> G(MAX_N * MAX_N);
  REP(y, H) {
    REP(x, W) {
      REP(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if(OoR(ny, nx)) {
          continue;
        }
        if(S[ny][nx] == '#')continue;
        G[ret_id(y, x)].emplace_back(Edge{ ret_id(ny,nx),0 });
      }
      REP(i, 5)REP(j, 5) {
        if(abs(d[i]) + abs(d[j]) == 0 || abs(d[i]) + abs(d[j]) == 4)continue;
        int nx = x + d[i], ny = y + d[j];
        if(OoR(ny, nx))continue;
        G[ret_id(y, x)].emplace_back(Edge{ ret_id(ny,nx),1 });
      }
    }
  }
  vector<ll> dis;
  dijkstra(G, 0, dis);
  cout << dis[ret_id(H - 1, W - 1)] << endl;
}