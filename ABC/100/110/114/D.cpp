#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;

  map<int, int> primes;
  for(int i = 1;i <= N;++i) {
    ll cp = i;
    for(ll k = 2;k * k <= cp;k++) {
      while(cp % k == 0) {
        primes[k]++;
        cp /= k;
      }
    }
    if(cp != 1) {
      primes[cp]++;
    }
  }

  for(auto [l, r] : primes) {
    //cout << l << ":" << r << endl;
  }
  ll ans = 0;
  for(auto [l1, r1] : primes) {
    for(auto [l2, r2] : primes) {
      for(auto [l3, r3] : primes) {
        if(l1 == l2||l1==l3||l2==l3)continue;
        if(r1 >= 4 && r2 >= 4 && r3 >= 2) {
          ans++;
        }
      }
    }
  }
  ans /= 2;
  for(auto [l, r] : primes) {
    if(r >= 74) {
      ans++;
    }
  }
  for(auto [l1, r1] : primes) {
    for(auto [l2, r2] : primes) {
      if(l1 == l2)continue;
      if(r1 >= 24 && r2 >= 2) {
        ans++;
      }
       if(r1 >= 14 && r2 >= 4) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}