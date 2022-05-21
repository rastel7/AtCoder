#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
int n, m;
ll X[101010], Y[101010];
mint f(ll* A, int a) {
  sort(A, A + a, greater<>());
  mint ret = 0, sum = 0;
  REP(i, a) {
    sum += A[i];
  }
  REP(i, a) {
    ret += (a - i) * A[i] - sum;
    sum -= A[i];
  }
  return ret;
}
int main() {
  cin >> n >> m;
  REP(i, n)cin >> X[i];
  REP(i, m)cin >> Y[i];
  cout << (f(X, n) * f(Y, m)).val() << endl;
}