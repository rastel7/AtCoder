#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
using mint = atcoder::modint1000000007;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
  ll N, K;
  cin >> N >> K;
  mint ans = 0;
  for (ll k = K; k <= N + 1; ++k) {
    ll l = k * (k - 1) / 2;
    ll r = (N ) * (N + 1) / 2;
    r -= (N  - k) * (N - k + 1) / 2;
    ans += r - l + 1;
  }
  cout << ans.val() << endl;
}