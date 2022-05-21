#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
template<class T>
void chmax(T& a, T b) {
  if(a < b)a = b;
}
ll solve(ll const& N, ll  const& C, vector<pair<ll, ll>> const& S) {
  ll ret = -1e18;
  vector<ll> Wa_fte(N + 1), Wa_etf(N + 1);
  REP(i, N) {
    Wa_fte[i + 1] = Wa_fte[i] + S[i].second;
    Wa_etf[N - i - 1] = Wa_etf[N - i] + S[N - i - 1].second;
  }
  REP(i, N) {
    Wa_etf[i] -= C - S[i].first;
  }
  REP(i, N) {
    chmax(Wa_etf[N - i - 1], Wa_etf[N - i]);
  }
  ret = Wa_etf[0];
  REP(i, N) {
    chmax(ret, Wa_fte[i + 1] - 2 * S[i].first + Wa_etf[i + 1]);
  }
  return ret;
}
int main() {
  ll N, C;
  cin >> N >> C;
  vector<pair<ll, ll>> S(N);
  REP(i, N)cin >> S[i].first >> S[i].second;
  ll ans = solve(N, C, S);
  REP(i, N) {
    S[i].first = C - S[i].first;
  }
  sort(S.begin(), S.end());
  chmax(ans, solve(N, C, S));
  cout << ans << endl;
}