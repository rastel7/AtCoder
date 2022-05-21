#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string S;
  cin >> S;
  int ans = S.size(); 
  REP(i, S.size() - 1) {
    if(S[i] == S[i + 1])continue;
    ans = min<ll>(ans, max<ll>(i + 1, S.size() - 1 - i));
  }
 
  cout << ans << endl;
}