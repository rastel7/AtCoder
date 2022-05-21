#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
bool isprime(ll x) {
  for(int i = 2;i < x;++i) {
    if(x % i == 0)return false;
  }
  return true;
}
int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  for(ll t = A;t <= B;++t) {
    bool b = 0;
    for(ll a = C;a <= D;++a) {
      ll tmp = a + t;
      if(isprime(tmp)) {
        b = 1;
      }
    }
    if(!b) {
      //cerr << t << endl;
      cout << "Takahashi" << endl;
      return 0;
    }
  }
  cout << "Aoki" << endl;
  return 0;
}