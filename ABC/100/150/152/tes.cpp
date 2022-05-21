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
long long longpow(long long n, long long a, long long mod) {
  if(a == 0)
    return 1;
  if(a == 1)
    return n % mod;
  if(a % 2 == 1)
    return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
template<class Tree, class Iterator>
inline void InsertSortedSequence(Tree& dst, Iterator begin, Iterator end) {
  auto pos = dst.begin();
  for(auto it = begin; it != end; ++it) {
    pos = dst.emplace_hint(pos, *it);
    ++pos;
  }
}
int main() {
  int N;
  cin >> N;
  vector<vector<Edge>> G(N);
  map<pair<int, int>, int> mp;
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(Edge{ b,1 });
    G[b].emplace_back(Edge{ a,1 });
    mp[make_pair(a, b)] = i;
    mp[make_pair(b, a)] = i;
  }
  int M;
  cin >> M;
  vector<ll> A(M);
  REP(j, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    vector<ll> dis;
    vector<int> prev;
    dijkstraRestore(G, a, dis, prev);
    auto path = get_path(prev, b);
    REP(i, path.size() - 1) {
      ll id = mp[make_pair(path[i], path[i + 1])];
      A[j] |= (1ll << id);
    }
  }
  ll ans = 0;
  for(int i = 0;i < (1 << M);++i) {
    int cnt = 0, id = 0, cp = i;
    ll s = 0;
    while(cp > 0) {
      if((cp & 1) == 1) {
        s |= A[id];
        cnt++;
      }
      id++;
      cp /= 2;
    }
    ll tmp = longpow(2, N - 1 - __builtin_popcountll(s), LONG_LONG_MAX);
    cerr << tmp << endl;
    if(cnt % 2 == 0) {
      ans += tmp;
    } else {
      ans -= tmp;
    }
  }
  cout << ans << endl;
}