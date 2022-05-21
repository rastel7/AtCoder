#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
string S;
char f(ll t, ll k) {
  if(t == 0) {
    return S[k];
  }
  if(k == 0) {
    ll i = S[0] - 'A';
    i += t;
    return 'A' + (i) % 3;
  }
  ll c = f(t - 1, k / 2) - 'A';
  if(k % 2 == 0) {
    c += 1;
  } else {
    c += 2;
  }
  c = 'A' + (c) % 3;
  return c;
}
int main() {
  cin >> S;
  int Q;
  cin >> Q;
  while(Q--) {
    ll t, k;
    cin >> t >> k, k--;
    cout<<f(t,k)<<"\n";
  }

}