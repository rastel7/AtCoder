#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const ll INF = 1e18;
template <class T>
/*  ワーシャルフロイド
    O(V)，全店最短路
    dis[i][i]=0を入力しておく
    dis[i][j]に，辺i-jのコストを入力しておく
    辺がなかったらINF
    負の閉路があったらdis[i][i]が負になるものが存在する*/
void warshall_floyd(T& dis) {
  int V = dis.size();
  REP(k, V)
    REP(i, V) {
    if(dis[i][k] == INF) continue;
    REP(j, V) {
      if(dis[k][j] == INF) continue;
      dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
  }
}

int main() {
  ll N, M, L;
  cin >> N >> M >> L;
  vector<vector<ll>> dis(N, vector<ll>(N));

  REP(i, N)REP(j, N)dis[i][j] = INF;
  REP(i, N)dis[i][i] = 0;
  REP(i, M) {
    ll a, b, c;
    cin >> a >> b >> c, a--, b--;
    dis[a][b] = c;
    dis[b][a] = c;
  }
  warshall_floyd(dis);
  vector<vector<ll>> dis2(N, vector<ll>(N));
  REP(i, N)REP(j, N)dis2[i][j] = INF;
  REP(i, N)dis2[i][i] = 0;
  REP(i, N)REP(j, N) {
    if(i == j)continue;
    if(dis[i][j] <= L) {
      dis2[i][j] = 1;
    }
  }
  warshall_floyd(dis2);
  for(auto& d : dis2) {
    for(auto& y : d) {
      if(y >= INF)y = 0;
    }
  }
  int Q;
  cin >> Q;
  while(Q--) {
    int u, t;
    cin >> u >> t, u--, t--;
    cout << dis2[u][t] -1<< endl;
  }

}
