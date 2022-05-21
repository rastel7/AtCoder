#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pl;
const int INF = 1e9;
const long long INFll = 1e18;
const ll MOD = 1000000007;

struct UnionFind {  // The range of node number is u 0 v n-1
  vector<int> rank, parents;
  UnionFind() {}
  UnionFind(int n) {  // make n trees.
    rank.resize(n, 0);
    parents.resize(n, 0);
    for(int i = 0; i < n; i++) {
      makeTree(i);
    }
  }
  void makeTree(int x) {
    parents[x] = x;  // the parent of x is x
    rank[x] = 0;
  }
  bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
  void unite(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if(rank[x] > rank[y]) {
      parents[y] = x;
    } else {
      parents[x] = y;
      if(rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }
  int findRoot(int x) {
    if(x != parents[x]) parents[x] = findRoot(parents[x]);
    return parents[x];
  }
};
// 辺の定義
struct Edge {
  long long u;
  long long v;
  long long cost;
};
bool comp_e(const Edge& e1, const Edge& e2) { return e1.cost < e2.cost; } // 辺を直接比較するための関数
/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/
struct Kruskal {
  UnionFind uft;
  long long sum;  // 最小全域木の重みの総和
  vector<Edge> edges;
  ll V;
  Kruskal(const vector<Edge>& edges_, ll V_) : edges(edges_), V(V_) { init(); }
  void init() {
    sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
    dsu uf(V);
    sum = 0;
    for(auto e : edges) {
      if(!uf.same(e.u, e.v) || e.cost < 0) { // 閉路にならなければ加える
        uf.merge(e.u, e.v);
        sum += e.cost;
      }
    }
  }
};

int main() {
  ll N, M;
  cin >> N >> M;
  ll score = 0;
  vector<Edge> edges(M);
  REP(i, M) {
    ll s, t, w;
    cin >> s >> t >> w,s--,t--;
    score += w;
    Edge e = { s,t,w };
    edges[i] = e;
  }
  Kruskal krs(edges, N);
  cout << score - krs.sum << endl;
}