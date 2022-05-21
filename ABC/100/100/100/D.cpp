#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct C {
  ll a, b, c;

};
int main() {
  ll N, M;
  cin >> N >> M;
  vector<C> A(N);
  REP(i, N)cin >> A[i].a >> A[i].b >> A[i].c;
  ll ans = -1e18;
  REP(i, 1 << 3) {
    sort(A.begin(), A.end(), [&](C l, C r) {
      ll a = 0, b = 0;
      a = ((i & 1) ? 1 : -1) * l.a + (((i >> 1) & 1) ? 1 : -1) * l.b + (((i >> 2) & 1) ? 1 : -1) * l.c;
      b = ((i & 1) ? 1 : -1) * r.a + (((i >> 1) & 1) ? 1 : -1) * r.b + (((i >> 2) & 1) ? 1 : -1) * r.c;
      return a > b;
      });
    ll sum = 0;
    REP(j, M)sum += ((i & 1) ? 1 : -1) * A[j].a + (((i >> 1) & 1) ? 1 : -1) * A[j].b + (((i >> 2) & 1) ? 1 : -1) * A[j].c;
    ans = max(ans, sum);
  }
  cout << ans << endl;
}