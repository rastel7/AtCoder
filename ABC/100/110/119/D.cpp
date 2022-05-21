#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const ll INF = 1e18;
template <typename T>
bool chmin(T& a, const T& b) {
  if(a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
int main() {
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<ll> S(A), T(B);
  REP(i, A)cin >> S[i];
  REP(i, B)cin >> T[i];
  S.emplace_back(-INF), S.emplace_back(INF);
  T.emplace_back(-INF), T.emplace_back(INF);
  sort(S.begin(), S.end());
  sort(T.begin(), T.end());
  vector<ll> ANS;
  while(Q--) {
    ll x;
    cin >> x;
    ll ans = INF;
    int id_s = lower_bound(S.begin(), S.end(), x) - S.begin();
    int id_t = lower_bound(T.begin(), T.end(), x) - T.begin();
    chmin(ans, max(S[id_s], T[id_t]) - x);
    chmin(ans, x - min(S[id_s - 1], T[id_t - 1]));
    chmin(ans, 2 * (x - S[id_s - 1]) + (T[id_t] - x));
    chmin(ans, (x - S[id_s - 1]) + 2 * (T[id_t] - x));
    chmin(ans, 2 * (S[id_s] - x) + (x - T[id_t - 1]));
    chmin(ans, (S[id_s] - x) + 2 * (x - T[id_t - 1]));
    ANS.emplace_back(ans);
  }
  for(auto ans : ANS) {
    cout << ans << endl;
  }

}