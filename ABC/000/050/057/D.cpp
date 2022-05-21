#include<bits/stdc++.h>
#include<atcoder/all>
using mint = atcoder::modint1000000007;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

long long i_pow(long long x, long long n) {
  long long ret = 1;
  while(n > 0) {
    if(n & 1) ret = ret * x;  // n の最下位bitが 1 ならば x^(2^i) をかける
    x = x * x;
    n >>= 1;  // n を1bit 左にずらす
  }
  return ret;
}
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
ll comb(int n, int r) {
  map<ll, ll> bunbo, bunsi;
  REP(i, r) {
    auto p = prime_factorization(i + 1);
    for(auto [l, r] : p)bunbo[l] += r;
    p = prime_factorization(n - i);
    for(auto [l, r] : p)bunsi[l] += r;
  }
  for(auto [l, r] : bunbo) {
    bunsi[l] -= r;
  }
  ll ret = 1;
  for(auto [l, r] : bunsi) {
    ret *= i_pow(l, r);
  }
  return ret;
}
int main() {
  int  N, A, B;
  cin >> N >> A >> B;
  vector<ll> v(N);
  REP(i, N)cin >> v[i];
  sort(v.rbegin(), v.rend());
  double sm = 0;
  REP(i, A) {
    sm += v[i];
  }
  ll cnt = 0;
  ll id = 1e9;
  REP(i, N) {
    if(v[A - 1] == v[i]) {
      id = min<ll>(id, i);
      cnt++;
    }
  }
  ll need = A - id;
  ll m_need = A - id;
  if(id == 0)m_need = B - id;
  ll ans = 0;
  for(int i = need;i <= m_need;++i) {
    ans += comb(cnt, i);
  }
  cout << fixed << setprecision(8) << sm / A << endl;
  cout << ans << endl;
}