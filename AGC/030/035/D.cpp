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
void dijkstra(const vector<vector<Edge>> &G, int s, vector<ll> &dis) {
  int N = G.size();
  dis.resize(N, INFll);
  priority_queue<PL, vector<PL>, greater<PL>>
      pq;  //「仮の最短距離、頂点」が小さい順にならぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    PL p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) continue;  //最短経路でなければ無視
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {  //最短距離候補ならpriority_queueに追加
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
void dijkstraRestore(const vector<vector<Edge>> &G, int s, vector<ll> &dis,
                     vector<int> &prev) {
  int N = G.size();
  dis.resize(N, INFll);
  prev.resize(N, -1);  // 初期化
  priority_queue<PL, vector<PL>, greater<PL>>
      pq;  //「仮の最短距離、頂点」が小さい順にならぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    PL p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) continue;  //最短経路でなければ無視
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {  //最短距離候補ならpriority_queueに追加
        dis[e.to] = dis[v] + e.cost;
        prev[e.to] = v;  // 頂点 v を通って e.to にたどり着いた
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}


int main() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<ll> A(N);
    REP(i, N)cin >> A[i];
    vector<vector<Edge>> G(N),Rev(N);
    while(M--){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        G[a].push_back((Edge){b,c});
        Rev[b].push_back((Edge){a,c});
    }
    vector<ll> dis,dis_r;
    dijkstra(G,0,dis);
    dijkstra(Rev,0,dis_r);
    ll ans=T*A[0];
    for(int i=1;i<N;++i){
        ll tmp=max<ll>(0,T-dis[i]-dis_r[i]);
        ans=max(ans,tmp*A[i]);
    }
    cout<<ans<<endl;
}