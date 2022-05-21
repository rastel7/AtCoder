#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll MOD = 998244353;
using mint = atcoder::modint998244353;
map<ll, ll> prime_factorization(long long n) {
  // map<ll,ll> first=素因数 second=first素因数の数
  map<ll, ll> res;
  for(int i = 2; i <= n / i; i++) {
    while(n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if(n != 1)
    res[n]++;
  return res;
}
template <class T>
T modpow(T base, T exp, T MOD) {
  assert(MOD < 998244353 || typeid(T) == typeid(long long));
  T ret = 1;
  while(exp > 0) {
    if(exp & 1) ret = ret * base % MOD;
    base = base * base % MOD;
    exp >>= 1;
  }
  return ret;
}
int main() {
  ll N, K, M;
  cin >> N >> K >> M;
  if(M % MOD == 0) {
    cout << 0 << endl;
    return 0;
  }
  K %= MOD - 1;
  M %= MOD;
  ll r = modpow(K, N, MOD - 1);
  mint ans = mint(M).pow(r);
  cout << ans.val() << endl;
}