#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;

void chmin(ll& a, ll b) { a = min(a, b); }

const ll INFll = 1LL << 60;
typedef tuple<long, long, long> PL;

struct Edge {
  ll cost;
  ll from;
  ll to;
  ll id;
};
int need[310];
const ll INF = 1e18;
template <class T>
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
ll A[310 * 310];
ll B[310 * 310];
ll C[310 * 310];
int main() {
  int N, M;
  cin >> N >> M;
  vector<Edge> E(M);
  vector<vector<Edge>> G(N);
  vector<vector<ll>> dis(N, vector<ll>(N, INF));
  REP(i, N)dis[i][i] = 0;
  REP(i, M) {
    ll a, b, c;
    cin >> a >> b >> c, a--, b--;
    A[i] = a, B[i] = b, C[i] = c;
    chmin(dis[a][b], c);
    chmin(dis[b][a], c);
    E[i] = Edge{ a,b,c };
    G[a].emplace_back(Edge{ c,a,b,i });
    G[b].emplace_back(Edge{ c,b,a ,i });
  }
  warshall_floyd(dis);
  int ans = 0;
  REP(i, M) {
    ll prev = dis[A[i]][B[i]];
    dis[A[i]][B[i]] = INF;
    dis[B[i]][A[i]] = INF;
    int V = dis.size();
    REP(k, V) {
      dis[A[i]][B[i]] = min(dis[A[i]][B[i]], dis[A[i]][k] + dis[k][B[i]]);
      dis[B[i]][A[i]] = min(dis[B[i]][A[i]], dis[B[i]][k] + dis[k][A[i]]);
    }
    if(dis[A[i]][B[i]] == prev)ans++;
    dis[A[i]][B[i]]=dis[B[i]][A[i]]=prev;
  }
  cout << ans << endl;

}