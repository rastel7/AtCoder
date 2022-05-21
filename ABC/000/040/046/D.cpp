#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string S;
  cin >> S;
  int ans = 0;
  int g = 0, p = 0;
  REP(i, S.size()) {
    if(i % 2 == 0) {
      if(S[i] == 'g') {

      } else {
        ans--;
      }
    } else {
      if(S[i] == 'g') {
        ans++;
      } else {

      }
    }
  }
  cout << ans << endl;
}