#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
  string S;
  cin >> S;
  ll ans = S.size();
  REP(i, S.size() - 1) {
    if(S[i] == S[i + 1])continue;
    ans = min({ ans,max(i + 1ll,(ll)S.size() - i - 1) });
  }
  cout << ans << endl;
}