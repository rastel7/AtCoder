#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
int main() {
  string S;
  cin >> S;
  mint ans = 0;
  int la = 0, lp = 0;
  int rc = 0, rp = 0;
  for(auto c : S) {
    if(c == 'C')rc++;
    if(c == '?')rp++;
  }
  int N = S.size();
  REP(i, N) {
    if(S[i] == 'C')rc--;
    if(S[i] == '?')rp--;

    if(S[i] == 'B' || S[i] == '?') {
      mint l=0, r=0;
      l = mint(la) * mint(3).pow(lp);
      if(lp != 0)
        l += mint(lp) * mint(3).pow(lp - 1);
      r = mint(rc) * mint(3).pow(rp);
      if(rp != 0)
        r += mint(rp) * mint(3).pow(rp - 1);
      ans += l * r;
    }

    if(S[i] == 'A')la++;
    if(S[i] == '?')lp++;
  }
  cout << ans.val() << endl;
}