#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
using mint = modint998244353;
vector<ll> eratosthenes(ll n) {
  vector<ll> ret;
  vector<bool> isPrime(n + 1, 1);
  for(ll i = 2;i <= n;++i) {
    if(!isPrime[i])continue;
    ret.emplace_back(i);
    for(ll j = 2;i <= n / j;++j) {
      isPrime[j * i] = 0;
    }
  }
  return ret;
}
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
mint test(ll N, ll K) {
  Combination<mint> comb(10);
  auto mp = prime_factorization(comb.C(N, K).val());
  mint ret = 1;
  for(auto [l, e] : mp) {
    ret *= mint(2).pow(e);
  }
  return ret;
}
int main() {
  ll N, K;
  cin >> N >> K;
  auto primes = eratosthenes(1e6 + 1000);
  vector<ll> A(K + 1), B(K + 1);
  REP(i, K + 1)A[i] = i, B[i] = N - K + i;
  map<ll, ll> divisors;
  for(auto const& p : primes) {
    for(ll i = p;i <= K;i += p) {
      while(A[i] % p == 0) {
        divisors[p]--;
        A[i] /= p;
      }
    }
  }
  for(auto const& p : primes) {
    for(ll i = ((N - K + (ll)1 + p - 1ll) / p) * p;i <= N;i += p) {
      ll id = i - (N - K);
      if(id == 0)continue;
      while(B[id] % p == 0) {
        divisors[p]++;
        B[id] /= p;
      }
    }
  }
  mint ans = 1;
  REP(i, K + 1) {
    if(i == 0)continue;
    if(A[i] != 1)divisors[A[i]]--;
    if(B[i] != 1)divisors[B[i]]++;
  }
  for(auto [num, e] : divisors) {
    ans *= e + 1;
  }
  cout << ans.val() << endl;
}