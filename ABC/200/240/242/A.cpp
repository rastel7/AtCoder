#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll A, B, C, X;
  cin >> A >> B >> C >> X;
  double ans;
  if(X <= A) {
    ans = 1;
  } else if(B >= X) {
    ans = C / double(B - A);
  } else {
    ans = 0;
  }
  cout << fixed << setprecision(10) << ans << endl;
}