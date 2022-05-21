#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  if(A == C) {
    if(B <= D) {
      cout << "Takahashi" << endl;
    } else {
      cout << "Aoki" << endl;
    }
  } else {
    if(A < C) {
      cout << "Takahashi" << endl;
    } else {
      cout << "Aoki" << endl;
    }
  }
}