#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> D(N);
  REP(i, N)cin >> D[i];
  vector<int> A(M), B(M);
  vector<ll> jisuu(N);
  REP(i, M) {
    cin >> A[i] >> B[i], A[i]--, B[i]--;
    jisuu[A[i]]++;
    jisuu[B[i]]++;
  }
  {
    ll sm = 0;
    REP(i, N) {
      sm += D[i];
      if(D[i] < jisuu[i]) {
        cout << -1 << endl;
        return 0;
      }
    }
    if(sm != (N - 1) * 2) {
      cout << -1 << endl;
      return 0;
    }
  }
  dsu uf(N);
  REP(i, M) {
    if(uf.same(A[i], B[i])) {
      cout << -1 << endl;
      return 0;
    }
    uf.merge(A[i], B[i]);
  }
  set<int> parents___;
  REP(i, N) {
    parents___.insert(uf.leader(i));
  }
  map<int, int> parent;
  {
    int i = 0;
    for(auto id : parents___) {
      parent[id] = i;
      i++;
    }
  }
  vector<vector<int>> can_adds(parent.size());
  REP(i, N) {
    if(D[i] == jisuu[i])continue;
    int p = parent[uf.leader(i)];
    can_adds[p].emplace_back(i);
  }
  vector<int> neo_D(parent.size());
  {int i = 0;
  for(auto const& v : can_adds) {
    for(auto p : v) {
      neo_D[i] += D[p] - jisuu[p];
    }
    i++;
  }
  for(auto x : neo_D) {
    if(x == 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  }
  vector<pair<int, int>> ne_D_l(neo_D.size());
  REP(i, ne_D_l.size()) {
    ne_D_l[i] = { neo_D[i],i };
  }
  sort(ne_D_l.begin(), ne_D_l.end()
    , [](pair<int, int> l, pair<int, int> r) {
      return l.first > r.first;
    }
  );
  vector<pair<int, int>> tmp_g;
  {
    int l = 0, r = 0;
    dsu uf2(N);
    while(true) {
      if(tmp_g.size() + M + 1 == N)break;
      while(uf2.same(l, r)) {
        r++;
        if(r >= ne_D_l.size() - 1)break;

      }
      while(l == r || ne_D_l[l].first == 0) {
        l++;
      }
      while(l == r || ne_D_l[r].first == 0) {
        r++;
      }
      if(r <= l) break;
      ne_D_l[l].first--;
      ne_D_l[r].first--;
      tmp_g.emplace_back(ne_D_l[l].second, ne_D_l[r].second);
      uf2.merge(l, r);
    }
  }
  vector<pair<int, int>> ans;
  for(auto [l, r] : tmp_g) {
    int a, b;
    a = can_adds[l].back();
    b = can_adds[r].back();
    ans.emplace_back(make_pair(a, b));
    jisuu[a]++, jisuu[b]++;
    if(jisuu[a] >= D[a])can_adds[l].pop_back();
    if(jisuu[b] >= D[b])can_adds[r].pop_back();
  }
  for(auto [l, r] : ans) {
    cout << l + 1 << " " << r + 1 << "\n";
  }
}