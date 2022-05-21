#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
long double f(double x_1, double y_1, double x_2, double y_2) {
  long double ret = 0;
  ret += abs(x_1 - x_2) * abs(x_1 - x_2);
  ret += abs(y_1 - y_2) * abs(y_1 - y_2);
  return sqrt(ret);
}
int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  REP(i, N)cin >> x[i] >> y[i];
  long double ans = 0;
  REP(i, N)REP(j, N) {
    ans = max(ans, f(x[i], y[i], x[j], y[j]));
  }
  cout << fixed << setprecision(10) << ans << endl;
}