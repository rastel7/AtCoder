#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

struct Edge {
  long long from;
  long long to;
  long long cost;
};
using Edges = vector<Edge>;
const long long INF = 1LL << 60;

/* bellman_ford(Es,s,t,dis)
    入力: 全ての辺Es, 頂点数V, 開始点 s, 最短経路を記録するdis
    出力: 負の閉路が存在するなら ture
    計算量：O(|E||V|)
    副作用：dis が書き換えられる
*/
vector<int> upds;
bool bellman_ford(const Edges& Es, int V, int s, vector<long long>& dis) {
  dis.resize(V, INF);
  upds.resize(V, -1);
  dis[s] = 0;
  int cnt = 0;
  while(cnt <= 3 * V) {
    bool end = true;
    for(auto e : Es) {
      if(dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to]) {
        dis[e.to] = dis[e.from] + e.cost;
        if(cnt > V) {
          upds[e.to] = 1;
          dis[e.to] = -1e18;
        }
        end = false;
      }
    }
    if(end) break;
    cnt++;
  }
  return (cnt >= V);
}

int main() {
  int N, M, P;
  cin >> N >> M >> P;
  vector<Edge> e;
  REP(i, M) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    c = -c + P;
    e.emplace_back(Edge{ a,b,c });
  }
  vector<ll> dis;
  if(bellman_ford(e, N, 0, dis) && upds[N - 1] == 1) {
    cout << -1 << endl;
    return 0;
  }
  cout << max<ll>(0, (ll)-1 * dis[N - 1]) << endl;
}