#include<bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> B(N, vector<ll>(M));
  REP(i, N)REP(j, M)cin >> B[i][j];
  ll l = (B[0][0] - 1) / 7, r = (B[0][0] - 1) % 7;
  REP(i, N)REP(j, M) {
    if(B[i][j] != B[0][0] + i * 7 + j) {
      cout << "No" << endl;
      return 0;
    }
  }
  REP(i, N)REP(j, M - 1) {
    if((B[i][j] - 1) / 7 != (B[i][j + 1] - 1) / 7) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}