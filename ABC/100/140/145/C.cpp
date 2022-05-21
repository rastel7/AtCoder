#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;cin >> N;
  vector<double> X(N), Y(N);
  REP(i, N)cin >> X[i] >> Y[i];
  vector<int> p(N);
  REP(i, N)p[i] = i;
  double ans = 0;
  double N_p = 1;
  for(int i = 1;i <= N;++i)N_p *= i;
  do {
    double tmp = 0;
    REP(i, N - 1) {
      int a = p[i], b = p[i + 1];
      tmp += sqrt((X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]));
    }
    ans += tmp;
  } while(next_permutation(p.begin(), p.end()));
  cout << fixed << setprecision(10) << ans / N_p << endl;
}