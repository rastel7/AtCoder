#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
char S[5], T[5];
int main() {
  REP(i, 3)cin >> S[i];
  REP(i, 3)cin >> T[i];
  ll cnt = 0;
  REP(i, 3)REP(j, 3) {
    if(i == j)continue;
    if(S[i] == T[j] && S[j] == T[i]) {
      cnt++;
      swap(S[i], S[j]);
    }
  }
  if(cnt % 2 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
