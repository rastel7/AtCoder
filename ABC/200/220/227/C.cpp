#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for(ll a = 1;a <= N / a;++a) {
    for(ll b = a;b <= N / a;++b) {
      ll c = N / (a * b);
      c -= (b - 1);
      if(c <= 0)break;
      ans += c;
    }
  }
  cout << ans << endl;
}