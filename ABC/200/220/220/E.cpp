#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
mint beki[2001010];
int main() {
  beki[0] = 1;
  REP(i, 2001010-10) {
    beki[i + 1] = beki[i] * 2;
  }
  ll N, D;
  cin >> N >> D;
  mint ans = 0;
  REP(i, N) {
    if(i + D < N) {
      ans += beki[D + 1]*beki[i];
    }
    if(2 * (N - 1 - i) < D || D == 1)continue;
    if(i + D < N) {
      ans += beki[D - 1] * (D - 1)*beki[i];
    } else {
      ans += beki[D - 1] * (2 * N - 2 * i - D - 1)*beki[i];
    }
  }
  cout << ans.val() << endl;
}