#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void DebugOut(vector<ll> const& A) {
  for (auto const& a : A) {
    cerr << a << " ";
  }
  cerr << "\n";
}
int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> S(N - 1);
  REP(i, N - 1) cin >> S[i];
  vector<ll> X(M);
  REP(i, M) cin >> X[i];
  map<ll, ll> mp;
  vector<ll> B(N);
  ll ans = 0;
  B[0] = S[0];
  for (int i = 1; i < N; ++i) {
    B[i] = S[i-1] - B[i - 1];
  }
  REP(i, M) {
    REP(j, N) {
      ll tmp = X[i] - B[j];
      if (j % 2 == 1) tmp *= -1;
      mp[tmp]++;
    }
  }
  for (auto [l, r] : mp) {
    ans = max(ans, r);
  }
  cout << ans << endl;
}