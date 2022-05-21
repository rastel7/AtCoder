#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct Qu
{
  ll t1, t2, r;
};

int main() {
  int N;
  cin >> N;
  vector<ll>  t(N), v(N);
  REP(i, N) cin >> t[i];
  REP(i, N) cin >> v[i];
  vector<Qu> Q(N + 2);
  Q[0].t1 = 0, Q[0].t2 = 0, Q[0].r = 0;
  REP(i, N) {
    Q[i + 1].t1 = Q[i].t2;
    Q[i + 1].t2 = Q[i].t2 + t[i] * 2;
    Q[i + 1].r = v[i];
  }
  Q[N + 1].r = 0, Q[N + 1].t1 = Q[N + 1].t2 = Q[N].t2;
  vector<long double> verb(Q[N + 1].t2 + 1);
  for(int i = 0;i < verb.size();++i) {
    double a = 1e18;
    for(auto [t1, t2, r] : Q) {
      if(i < t1) {
        a = min(a, r + abs((t1 - i)) * 0.5);
      } else if(i > t2) {
        a = min(a, r + abs((t2 - i)) * 0.5);
      } else {
        a = min(a, (double)r);
      }
    }
    verb[i]=a;
  }
  long double ans = 0;
  REP(i, verb.size() - 1) {
    long double add = 0.5 * (verb[i] + verb[i + 1]) / 2;
    ans += add;
  }
  cout << fixed<<setprecision(8)<<ans << endl;
}