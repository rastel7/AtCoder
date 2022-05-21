#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  vector<ll> Wa(N + 1);
  REP(i, N) {
    Wa[i + 1] = Wa[i] + A[i];
  }
  map<ll, ll> mod;
  REP(i, N + 1) {
    mod[Wa[i] % M]++;
  }
  ll ans = 0;
  for(auto [l, r] : mod) {
    ans += r * (r - 1) / 2;
  }
  cout << ans << endl;
}