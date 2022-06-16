#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(M);
  REP(i, M) cin >> A[i];
  auto sum = accumulate(A.begin(), A.end(), 0ll);
  if (sum > N) {
    cout << -1 << endl;
  } else {
    cout << N - sum << endl;
  }
}