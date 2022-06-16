#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;

mt19937_64 mt;
random_device rnd;
template <class T>
T myPow(T base, T exp, T MOD) {
  T ret = 1;
  while (exp > 0) {
    if (exp & 1) ret = ret * base % MOD;
    base = base * base % MOD;
    exp >>= 1;
  }
  return ret;
}
#define K 500
//ミラーラビン素数判定法(Wilipediaより)
bool Miller(unsigned long long num) {
  if (num == 2) {
    //自明に素数
    return true;
  }
  if (num > 2 && num % 2 == 0) {
    // 2より大きい偶数なので自明に合成数
    return false;
  }
  unsigned long long d = (num - 1) >> 1;
  while ((d & 1) == 0ll) {
    d = (d >> 1);
  }
  // uniform_int_distribution<> rand(1, num - 1);
  for (int _ = 0; _ < K; ++_) {
    unsigned long long x = mt() % (num - 1) + 1;
    unsigned long long t = d;
    unsigned long long y = myPow(x, t, num);
    while ((t != num - 1) && (y != 1) && (y != num - 1)) {
      //桁あふれの可能性あり
      y = (y * y) % num;
      t = t << 1;
    }
    if (y != num - 1 && (t & 1) == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  const ll n = 123123137;
  int ans = 0;
  for (int i = 10001; i <= 11096; ++i) {
    if (Miller(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}