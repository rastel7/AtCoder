#include<bits/stdc++.h>
#define REP(i, XX) for (int i = 0; i < (int)(XX); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
struct frac {
  ll a, b;
  frac(ll _a = 0, ll _b = 1) :a(_a), b(_b) {
    if(b == 0) { a = 1; return; }
    if(b < 0)a = -a, b = -b;
    ll g = gcd(a, b);
    a /= g, b /= g;
  }

  bool operator<(const frac& x)const {
    return a * x.b < x.a* b;
  }
  bool operator==(const frac& x)const {
    return a == x.a && b == x.b;
  }
};
int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  REP(i, n) cin >> x[i] >> y[i];
  vector<frac> lf(n), rf(n);
  REP(i, n) lf[i] = frac(x[i] - 1, y[i]);
  REP(i, n) rf[i] = frac(x[i], y[i] - 1);
  map<frac, int> mp;
  REP(i, n) { mp[lf[i]] = 0; mp[rf[i]] = 0; }
  int m = 0;
  for(auto&& p : mp)p.second = m++;
  vector<P> d;
  REP(i, n) d.emplace_back(mp[rf[i]], mp[lf[i]]);
  sort(d.begin(), d.end());

  int mx = -1, ans = 0;
  for(auto [r, l] : d) {
    if(l >= mx)mx = r, ++ans;
  }
  cout << ans << endl;
  return 0;
}