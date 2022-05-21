#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define OUT(V) for(ll i=0;i<(ll)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e9;
const ll MOD = 1000000007;
const ll INFll = 1LL << 60;
typedef pair<long, long> PL;
struct Edge {
  ll to;
  ll c;
  ll d;
};
void dijkstra(const vector<vector<Edge>>& G, ll s, vector<ll>& dis);
int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<Edge>> G(N);
  REP(i, M) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d, a--, b--;
    G[a].emplace_back(Edge{ b,c,d });
    G[b].emplace_back(Edge{ a,c,d });
  }
  vector<ll> dis;
  dijkstra(G, 0, dis);
  if(dis[N - 1] == INFll)dis[N - 1] = -1;
  cout << dis[N - 1] << endl;
}

/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる,負のコストの際利用できない
*/
ll ret_time(ll now, ll c, ll d) {
  auto f = [&](ll t) {
    return now + c + (d / (t + 1));
  };
  ll l = now, r = 10;
  while(r - l > 1) {
    ll mid1 = l + (r - l) / 3, mid2 = l + (r - l) * 2 / 3;
    if(f(mid1) > f(mid2)) {
      l = mid1;
    } else {
      r = mid2;
    }
  }
  return l;
}
void dijkstra(const vector<vector<Edge>>& G, ll s, vector<ll>& dis) {
  ll N = G.size();
  dis.resize(N, INFll);
  priority_queue<PL, vector<PL>, greater<PL>>
    pq;  //「仮の最短距離、頂点」が小さい順にならぶ
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while(!pq.empty()) {
    PL p = pq.top();
    pq.pop();
    ll v = p.second;
    if(dis[v] < p.first) continue;  //最短経路でなければ無視
    auto f = [&](ll _t, ll c, ll d) {
      return _t + c + (d / (_t + 1));
    };
    for(auto& e : G[v]) {
      ll t;
      if(dis[v] > floor(sqrt(e.d))) {
        t = f(dis[v], e.c, e.d);
      } else {
        t = min(f(floor(sqrt(e.d)), e.c, e.d), f(ceil(sqrt(e.d)), e.c, e.d));
      }
      if(dis[e.to] > t) {
        dis[e.to] = t;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
}