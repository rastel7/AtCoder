#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string S;
  ll K;
  cin >> S >> K;
  ll ans = 0;
  ll S_length = S.size();
  ll l = 0, r = S_length - 1;
  if(S[0] == S.back()) {
    while(l < S_length && S[0] == S[l])l++;
    if(l >= S_length) {
      cout << ((ll)S_length * K) / 2 << endl;
      return 0;
    }
    while(r >= 0 && S.back() == S[r])r--;
    ans += (S_length - r + l - 1) / 2 * (K - 1);
    ans += (l / 2) + (S_length - r - 1) / 2;
  }
  ll id = l;
  while(id <= r) {
    ll left = id;
    while(id < S_length && S[left] == S[id])id++;
    ans += ((id - left) / 2) * K;
  }
  cout << ans << endl;
}