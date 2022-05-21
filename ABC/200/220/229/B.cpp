#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll A, B;
  cin >> A >> B;
  while(A != 0 && B != 0) {
    ll a = A % 10, b = B % 10;
    if(a + b > 9) {
      cout << "Hard" << endl;
      return 0;
    }
    A /= 10, B /= 10;
  }
  cout << "Easy" << endl;
}