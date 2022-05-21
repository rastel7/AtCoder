#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N, K;
int A[1000][1000];
ll f(ll x) {
  vector<vector<int>> Wa(N + 1, vector<int>(N + 1));
  REP(i, N)REP(j, N) {
    if(A[i][j] > x) {
      Wa[i + 1][j + 1]++;
    }
  }
  if(x == 5) {
    int rete = 0;
  }
  REP(i, N + 1)REP(j, N) {
    Wa[i][j + 1] += Wa[i][j];
  }
  REP(i, N + 1)REP(j, N) {
    Wa[j + 1][i] += Wa[j][i];
  }
  if(x == 6) {
    int rete = 0;
  }
  REP(i, N+1)REP(j, N+1) {
    if(i - K < 0 || j - K < 0)continue;
    ll sum = Wa[i][j] + Wa[i - K][j - K] - Wa[i - K][j] - Wa[i][j - K];
    if(sum <= (K * K) / 2) {

      cerr << sum << " " << x << " " << i << "," << j << endl;
      return true;
    }
  }
  return false;
}
int main() {
  cin >> N >> K;
  REP(i, N)REP(j, N)cin >> A[i][j];
  ll l = -1, r = 1e18;
  while(r - l > 1) {
    ll mid = l + (r - l) / 2;
    if(f(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
}