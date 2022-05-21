#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll V, A, B, C;
  cin >> V >> A >> B >> C;
  while(true) {
    if(V < A) {
      cout << "F" << endl;
      return 0;
    }
    V -= A;
    if(V < B) {
      cout << "M" << endl;
      return 0;
    }
    V -= B;
    if(V < C) {
      cout << "T" << endl;
      return 0;
    }
    V -= C;
  }
}