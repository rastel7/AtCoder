#include<bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
int checked[210101];
ll scores[210101];
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  {
    ll ans = 0, loopcnt = 0;
    bool looped = 0;
    REP(i, K) {
      auto next = A[ans % N];
      if(checked[ans % N] != 0 && looped == 0) {
        checked[ans % N]--;
        loopcnt = i - checked[ans % N];
        ll cnt = (K - checked[ans % N] - 1) / loopcnt;
        ll dif = ans - scores[ans % N];
        if(cnt > 0) {
          ans -= dif;
          ans += dif * cnt;
          i += loopcnt * (cnt-1);
        }
        looped = 1;
      }
      scores[ans % N] = ans;
      checked[ans % N] = i + 1;
      ans += next;

    }
    cout << ans << endl;
  } 
  /*{
    ll ans = 0, loopcnt = 0;
    bool looped = 0;
    REP(i, K) {
      auto next = A[ans % N];
      scores[ans % N] = ans;
      checked[ans % N] = i;
      ans += next;

    }
    cout << ans << endl;
  }*/
}