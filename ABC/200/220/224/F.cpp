#include<bits/stdc++.h>
#include<atcoder/all>
using mint = atcoder::modint998244353;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N;
mint f(ll x) {
  mint ret = mint(2).inv() * (mint(5).pow(x - 1) - 1) / (mint(5) - mint(1));
  ret += mint(10).pow(x - 1) * mint(2).pow(x - 1).inv();
  return ret;
}
int main() {
  string S;
  cin >> S;
  N = S.size();
  reverse(S.begin(), S.end());
  mint ans = 0;
  for(int i = 0;i < N;++i) {
    auto tmp = f(i + 1);
    ans += (S[i] - '0') * tmp;
    cerr << tmp.val() << endl;
  }
  ans *= mint(2).pow(S.size() - 1);
  cout << ans.val() << endl;
}