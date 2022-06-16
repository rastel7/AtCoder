#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
void solve() {
  int N, X;
  cin >> N >> X;
  int a = (N + 5) / 6;
  cout << a * X << endl;
}
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
}