#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> S(N);
  REP(i, N)cin >> S[i];
  set<ll> s;
  for(ll a = 1;a <= 1000;++a) {
    for(ll b = 1;b <= 1000;++b) {
      if(a * b > 1000)continue;
      s.insert(4 * a * b + 3 * a + 3 * b);
    }
  }
  int ans = 0;
  REP(i, N) {
    if(!s.count(S[i]))ans++;
  }
  cout << ans << endl;
}