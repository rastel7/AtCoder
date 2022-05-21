#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
long double x;
long double f(long double t) {
  return t + x / (powl(2, t / 1.5));
}
int main() {
  cin >> x;
  double l = 0, r = 1e18;
  while(r - l >= 1e-10) {
    double mid_1 = l + (r - l) / 3, mid_2 = l + (r - l) * 2 / 3;
    if(f(mid_1) < f(mid_2)) {
      r = mid_2;
    }
    else {
      l = mid_1;
    }
  }
  cout << fixed << setprecision(10) << f((l + r) / 2) << endl;
}