#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

int main() {
  string S;
  cin >> S;
  ll K;
  cin >> K;
  if(K > (ll)1e4) {
    ll dp[35][35][35][35];
    {int k = 0, e = 0, y = 0;
    for(auto& c : S) {
      if(c == 'K')k++;
      if(c == 'E')e++;
      if(c == 'Y')y++;
    }
    dp[0][k][e][y] = 1;}
    for(int i = 0;i < S.size();++i) {
      REP(k, 31)REP(e, 31)REP(y, 31) {
        if(k != 0)dp[i + 1][k - 1][e][y] += dp[i][k][e][y];
        if(e != 0)dp[i + 1][k][e - 1][y] += dp[i][k][e][y];
        if(y != 0)dp[i + 1][k][e][y - 1] += dp[i][k][e][y];
      }
    }
    cout << dp[S.size()][0][0][0] << endl;
  } else {
    ll dp[32][1000][32][4];
    int N = S.size();
    dp[0][K][0][0] = 1;
    REP(i, N) {
      REP(k, K) {
        REP(j, 30) {
          REP(c_num, 4) {
            char c = S[i];
            int id = 0, pos = -1;
            REP(lm, N) {
              if(S[pos] == c) {
                id++;
                if(id > j) {
                  pos = lm;
                  break;
                }
              }
            }
            if(pos == -1)continue;
          }
        }
      }
    }
  }
}