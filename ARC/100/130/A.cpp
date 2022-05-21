#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll ans = 0;
  ll l = 0;
  for(ll r = 0;r < N;) {
    while(r < N && S[r] == S[l]) {
      r++;
    }
    ans += (r - l - 1) * (r - l ) / 2;;
    l = r;
  }
  cout << ans << endl;
}