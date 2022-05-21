#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int S, T, X;
  cin >> S >> T >> X;
  if(T <= S) {
    T += 24;
  }
  for(int i = S;i < T;i++) {
    if(i % 24 == X) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}