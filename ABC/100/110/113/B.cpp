#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, T, A;
  cin >> N >> T >> A;
  double ans = 1e18;
  int id = 0;
  REP(i, N) {
    int h;
    cin >> h;
    double x = T - h * 0.006;
    if (ans > abs(A - x)) {
      ans = abs(A - x);
      id = i;
    }
  }
  cout << id+1 << endl;
}