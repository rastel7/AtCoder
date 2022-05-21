#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll X;
  cin >> X;
  if(X > 0) {
    X /= 10;
  } else {
    X = (X - 9) / 10;
  }
  cout << X << endl;
}