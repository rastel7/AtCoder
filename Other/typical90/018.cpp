#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const double PI = acos(-1);
int main() {
  double T;
  cin >> T;
  double L, X, Y;
  cin >> L >> X >> Y;
  int Q;
  cin >> Q;
  vector<double> ans;
  while(Q--) {
    double E;
    cin >> E;
    double sy = -L / 2.0 * sin((double(E) / T) * 2 * PI);
    double sz = L / 2.0 - L / 2.0 * cos((double(E) / T) * 2 * PI);
    double dist_x = sqrt(X * X + (Y - sy) * (Y - sy));
    double dist_z = sz;
    ans.emplace_back(180 * atan2(dist_z, dist_x) / PI);
  }
  cout << fixed << setprecision(15);
  for(auto& a : ans) {
    cout << a << endl;
  }
}