#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const ll INFll = 1LL << 60;
typedef pair<long, long> PL;
struct Edge {
  ll to;
  ll cost;
  ll freq;
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
        ll time;
        if(dis[v]%e.freq==0){
            time=dis[v] + e.cost;
        }else{
            time=(e.freq-dis[v]%e.freq) + dis[v] + e.cost;
        }
      if (dis[e.to] >  time) {  //最短距離候補ならpriority_queueに追加
        dis[e.to] =  time;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}
//参考:https://algo-logic.info/dijkstra/
int main() {
    int n,m,x,y;
    cin>>n>>m>>x>>y,x--,y--;
    vector<vector<Edge>> G(n);
    REP(i,m){
        ll a,b,t,k;
        cin>>a>>b>>t>>k,a--,b--;
        G[a].push_back((Edge){b,t,k});
        G[b].push_back((Edge){a,t,k});
    }
    vector<ll> dis;
    dijkstra(G,x,dis);
    if(dis[y]==INFll){
        dis[y]=-1;
    }
    cout<<dis[y]<<endl;
}