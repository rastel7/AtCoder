#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
struct point {
  int x, y;
};
struct edge {
  int from, to, dist;
};
struct input {
  static const int N = 400, M = 1995;
  vector<point> pos;
  vector<edge> edges;
  input() {
    pos.resize(N), edges.resize(M);
    for(auto& p : pos) {
      cin >> p.x >> p.y;
    }
    for(auto& p : edges) {
      cin >> p.from >> p.to;
      //暫定の長さ
      p.dist = 1.2 * round(
        sqrt(
          (pos[p.from].x - pos[p.to].x) * (pos[p.from].x - pos[p.to].x)
          + (pos[p.from].y - pos[p.to].y) * (pos[p.from].y - pos[p.to].y)
        ));
    }
  }
};
bool can_connect_later(int id, dsu const& now_merge, input const& in) {
  auto cp = now_merge;
  int a = in.edges[id].from, b = in.edges[id].to;
  for(int i = id + 1;i < in.M;++i) {
    auto e = in.edges[i];
    bool l = cp.same(a, e.from) || cp.same(a, e.to);
    bool r = cp.same(b, e.from) || cp.same(b, e.to);
    if(l && r) {
      return 1;
    }
  }
  return 0;
}
ll calc_score(input const& in, vector<int> const& out) {//簡易的
  dsu uf(in.N);
  ll ret = 0;
  REP(i, in.M) {
    if(out[i]) { ret += in.edges[i].dist; uf.merge(in.edges[i].from, in.edges[i].to); }
  }
  for(int i = 1;i < in.N;++i) {
    if(!uf.same(0, i)) {
      return 1e16;
    }
  }
  return ret;
}
vector<int> zeniki(input const& in) {
  vector<int> ret(in.M, 0);
  vector<pair<edge, int>> G(in.M);
  REP(i, in.M) {
    G[i].first = in.edges[i];
    G[i].second = i;
  }
  sort(G.begin(), G.end(), [](pair<edge, int> l, pair<edge, int> r) {
    return l.first.dist < r.first.dist;
    });
  dsu uf(in.N);
  for(auto [e, id] : G) {
    if(uf.same(e.from, e.to))continue;
    ret[id] = 1;
    uf.merge(e.from, e.to);
  }
  REP(i, in.N - 1) {
    if(!uf.same(0, i + 1)) {
      assert(0);
    }
  }
  return ret;
}
vector<int> zeniki(int id, vector<int> out, input const& in) {
  vector<int> ret(in.M, 0);
  vector<pair<edge, int>> G(in.M);
  REP(i, in.M) {
    G[i].first = in.edges[i];
    G[i].second = i;
  }
  dsu uf(in.N);
  REP(i, id) {
    if(out[i] == 1) {
      ret[i] = 1;
      uf.merge(G[i].first.from, G[i].first.to);
    }
  }
  sort(G.begin(), G.end(), [](pair<edge, int> l, pair<edge, int> r) {
    return l.first.dist < r.first.dist;
    });
  for(auto [e, id2] : G) {
    if(id2 < id) {
      if(out[id2] == 1) {
        ret[id2] = 1;
        uf.merge(e.from, e.to);
      } else {
        continue;
      }
    }
    if(uf.same(e.from, e.to))continue;
    ret[id2] = 1;
    uf.merge(e.from, e.to);
  }
  REP(i, in.N - 1) {
    if(!uf.same(0, i + 1)) {
      assert(0);
    }
  }
  return ret;
}
int main() {
  clock_t start = clock();
  input in;
  dsu uf(in.N);
  auto v = zeniki(in);
  REP(i, in.M) {
    int l;
    cin >> l;
    in.edges[i].dist = l;
    auto new_v = zeniki(i, v, in);
    if(calc_score(in, v) > calc_score(in, new_v)) {
      cerr << "yay" << endl;
      v = new_v;
    }
    if(v[i] == 1) {
      uf.merge(in.edges[i].from, in.edges[i].to);
    }
    cout << v[i] << endl;
  }
  REP(i, in.N - 1) {
    if(!uf.same(0, i + 1)) {
      assert(0);
    }
  }
  {
    int cnt = 0;
    for(auto i : v) {
      cnt += i;
    }
    cerr << cnt << endl;
    cerr << calc_score(in, v) << endl;
  }
  clock_t end = clock();
  const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
  cerr << fixed << setprecision(4) << "time:" << time << endl;
}