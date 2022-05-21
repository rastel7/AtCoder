#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
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
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
  }
  map<ll, ll> mp;
  for(auto x : A) {
    map<ll, ll> primes = prime_factorization(x);
    for(auto [a, b] : primes) {
      mp[a] = max(mp[a], b);
    }
  }
  mint g = 1;
  for(auto [a, b] : mp) {
    g *= mint(a).pow(b);
  }
  cerr << g.val() << endl;
  mint ans = 0;
  for(auto a : A) {
    ans += g / a;
  }
  cout << ans.val() << endl;
}