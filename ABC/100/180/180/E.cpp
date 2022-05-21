#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
template <typename T>
bool chmin(T& a, const T& b) {
  if(a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const int MAX_N = 1 << 20;
vector<int> X, Y, Z;
int dp[MAX_N][20];
int C[20][20];
int N;
int calc(int i, int j) {
  return abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + max(0, Z[i] - Z[j]);
}
int rec(int S, int v) {
  if(S == 0) {
    if(v == 0) {
      return 0;
    }
    else {
      return INF;
    }
  }
  if((S & (1 << v)) == 0) {  // Sに{v}が含まれていない
    return INF;
  }
  int& ret = dp[S][v];
  if(ret != 0) return ret;
  ret = INF;
  REP(u, N) { chmin(ret, rec(S ^ (1 << v), u) + C[u][v]); }
  return ret;
}
int main() {

  cin >> N;
  X.resize(N), Y.resize(N), Z.resize(N);
  REP(i, N)cin >> X[i] >> Y[i] >> Z[i];
  //REP(i, MAX_N)REP(j, 20)dp[i][j] = INF;
  REP(i, N)REP(j, N) {
    C[i][j] = calc(i, j);
  }
  cout << rec((1 << N) - 1, 0) << endl;
}