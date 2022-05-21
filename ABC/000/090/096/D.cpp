#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define rep(i,x, n) for (int i = x; i < (int)(n); i++)
using ll = long long;
using namespace std;
bool is_prime(ll x) {
  for(ll i = 2;i * i <= x;++i) {
    if(x % i == 0)return false;
  }
  return true;
}
int main() {
  ll N;
  cin >> N;
  vector<ll> A = { 2 };
  REP(i, N) {
    for(int i = A.back() + 1;;++i) {

      if(!is_prime(i))continue;
      if(i % 5 == 1) {
        A.emplace_back(i);
        break;
      }
    }
  }
  for(auto a : A) {
    if(a != 2)
      cout << a << " ";
  }
  cout << endl;
}