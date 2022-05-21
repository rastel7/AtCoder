#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
void solve() {
  ll N, S, K;
  cin >> N >> S >> K;
  auto [i, x] = crt({ N - S,0 }, { N,K });
  if(x == 0) {
    cout << -1 << endl;
    return;
  }
  cout << i / K << endl;
}
int main() {
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
}