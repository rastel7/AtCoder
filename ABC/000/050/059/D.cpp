#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll X, Y;
  cin >> X >> Y;
  if(abs(X - Y) <= 1) {
    cout << "Brown" << endl;
  } else {
    cout << "Alice" << endl;
  }
}