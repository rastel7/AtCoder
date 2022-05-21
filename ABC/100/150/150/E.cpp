#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
int main() {
  int N;
  cin >> N;
  vector<ll> C(N);
  REP(i, N) {
    cin >> C[i];
  }
  sort(C.begin(), C.end(), greater<>());
  mint ans = 0;
  if(N != 1) {
    REP(i, N) {
      ans += C[i] * (mint(2).pow(N - 1) + i * mint(2).pow(N - 2));
    }
    ans *= mint(2).pow(N);
  } else {
    ans = mint(C[0]) * 2;
  }
  cout << ans.val() << endl;
}