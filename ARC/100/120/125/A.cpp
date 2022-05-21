#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int N, M;
ll dis(ll x, ll now) {
  return min(abs(now - x), N - abs(now - x));
}
int main() {

  cin >> N >> M;
  vector<ll> S(N), T(M);
  REP(i, N)cin >> S[i];
  REP(i, M)cin >> T[i];
  ll ans = 0;
  vector<vector<ll>> A(27);
  REP(i, N) {
    A[S[i]].emplace_back(i);
  }
  ll now = 0;
  REP(i, M) {
    char c = T[i];
    int id = c;
    if(A[id].empty()) {
      cout << -1 << endl;
      return 0;
    }
    auto itr = lower_bound(A[id].begin(), A[id].end(), now);
    if(itr == A[id].end()) {
      itr = A[id].begin();
    }
    ll t1, t2;
    if(itr == A[id].begin()) {
      t1 = *itr;
      t2 = A[id].back();
      if(dis(t1, now) > dis(t2, now)) {
        ans += dis(t2, now) + 1;
        now = t2;
      }
      else {
        ans += dis(t1, now) + 1;
        now = t1;
      }
    }
    else {
      t1 = *(itr--);
      t2 = *(itr);
      if(dis(t1, now) > dis(t2, now)) {
        ans += dis(t2, now) + 1;
        now = t2;
      }
      else {
        ans += dis(t1, now) + 1;
        now = t1;
      }
    }
    //cout << ans << endl;
  }
  cout << ans << endl;
}