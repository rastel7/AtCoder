#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = std::pair<ll, ll>;
using namespace std;
pair<ll, ll> f(ll x, ll y) {

  ll pr_x = 1, pr_y = 1;
  if(x < 0) {
    pr_x = -1;
  }
  if(y < 0) {
    pr_y = -1;
  }
  if(x == 0) {
    return P(0, pr_y);
  }
  if(y == 0) {
    return P(pr_x, 0);
  }
  x = abs(x), y = abs(y);
  ll g = gcd(x, y);
  x /= g, y /= g;
  return P(x * pr_x, y * pr_y);
}
int main() {
  int N;
  cin >> N;
  vector<ll> X(N), Y(N);
  REP(i, N)cin >> X[i] >> Y[i];
  set<pair<ll, ll>> s;
  REP(i, N)REP(j, N) {
    if(i == j)continue;
    auto x = X[j] - X[i], y = Y[j] - Y[i];
    s.insert(f(x, y));
  }
  cout << s.size() << endl;
}