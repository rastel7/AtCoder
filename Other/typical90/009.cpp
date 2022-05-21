#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<long double, long double> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const long double PI = acos(-1);
long double angle(long double x, long double y) {
  return atan2(y, x) * 180.0 / PI;
}
int main() {
  int N;
  cin >> N;
  vector<P> A(N);
  REP(i, N)cin >> A[i].first >> A[i].second;
  long double ans = 0;
  for(int i = 0;i < N;++i) {
    vector<long double> B;
    for(int j = 0;j < N;++j) {
      if(i == j)continue;
      B.emplace_back(angle(A[j].first - A[i].first, A[j].second - A[i].second));
      B.emplace_back(angle(A[j].first - A[i].first, A[j].second - A[i].second)+360);
    }
    sort(B.begin(), B.end());
    B.insert(B.begin(), B[B.size() - 1] - 720);
    for(auto& b : B) {
      auto itr = lower_bound(B.begin(), B.end(), fmod(b + 180, 360));
      auto f = [](long double t1, long double t2) {
        t1 = max(t1, fmod(t1 + 360, 360));
        t2 = max(t2, fmod(t2 + 360, 360));
        return min(abs(t1 - t2), 360.0 - abs(t1 - t2));
      };
      auto ang1 = *(itr--), ang2 = *itr;
      long double tmp = 0;
      if(b != ang1)tmp = max(tmp, f(b, ang1));
      if(b != ang2)tmp = max(tmp, f(b, ang2));
      ans = max(ans, tmp);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}