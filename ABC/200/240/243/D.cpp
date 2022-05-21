#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, X;
  cin >> N >> X;
  string S;
  cin >> S;
  ll b = 0;
  REP(i, N) {
    if(S[i] == 'U') {
      if(b != 0) {
        b--;
        continue;
      }
      X /= 2;
      continue;
    }
    if((X * 2 >= 1e18 )|| (b != 0)) {
      b++;
      continue;
    }
    if(S[i] == 'L') {
      X *= 2;
    } else {
      X = X * 2 + 1;
    }
  }
  cout << X << endl;
}