#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
struct Edge {
  int from, to;
};
struct vert {
  int id;
  int y, x;
};
int main() {
  int N;cin >> N;
  vector<int> y(N), x(N);
  REP(i, N)cin >> y[i] >> x[i];
  vector<vert> tops(N);
  REP(i, N)tops[i] = { i,y[i],x[i] };
  sort(tops.begin(), tops.end(), [](vert l, vert r) {
    return l.x < r.x;
    });
  vector<Edge> es;
  REP(i, N - 1) {
    es.emplace_back(Edge{ tops[i].id,tops[i + 1].id });
    es.emplace_back(Edge{ tops[i + 1].id,tops[i].id });
  }
  sort(tops.begin(), tops.end(), [](vert l, vert r) {
    return l.y < r.y;
    });
  REP(i, N - 1) {
    es.emplace_back(Edge{ tops[i].id,tops[i + 1].id });
    es.emplace_back(Edge{ tops[i + 1].id,tops[i].id });
  }
  dsu uf(N);
  sort(es.begin(), es.end(), [&](Edge l, Edge r) {
    auto a = min(abs(y[l.from] - y[l.to]), abs(x[l.from] - x[l.to]));
    auto b = min(abs(y[r.from] - y[r.to]), abs(x[r.from] - x[r.to]));
    return a < b;
    });
  ll ans = 0;
  for(auto e : es) {
    if(uf.same(e.from, e.to))continue;
    auto l = e;
    auto a = min(abs(y[l.from] - y[l.to]), abs(x[l.from] - x[l.to]));
    ans += a;
    uf.merge(e.from, e.to);
  }
  cout << ans << endl;
}