#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  set<int> sx, sy;
  REP(i, N) {
    cin >> x[i] >> y[i];
  }
  const int MAX_N = 110000;
  dsu uf(MAX_N * 2);
  map<ll, ll> mx, my;

  REP(i, N) {
    uf.merge(x[i], y[i] + MAX_N);
  }
  REP(i, MAX_N) {
    mx[uf.leader(i)]++;
    my[uf.leader(i + MAX_N)]++;
  }
  ll ans = 0;
  REP(i, MAX_N * 2) {
    ans += mx[i] * my[i];
  }
  cout << ans -N<< endl;
}