#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  vector<int> beki(64);
  for(auto const& a : A) {
    REP(i, 64) {
      if((a >> i) & 1) {
        beki[i]++;
      }
    }
  }
  mint ans = 0;
  REP(i, 64) {
    ans += mint(2).pow(i) * mint(beki[i]) * mint(N - beki[i]);
  }
  cout << ans.val() << endl;
}