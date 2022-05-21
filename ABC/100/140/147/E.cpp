#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int dp[100][100][200 * 100];
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H + 1, vector<ll>(W + 1));
  vector<vector<ll>> B(H + 1, vector<ll>(W + 1));
  REP(i, H)REP(j, W)cin >> A[i + 1][j + 1];
  REP(i, H)REP(j, W)cin >> B[i + 1][j + 1];
  dp[1][1][abs(A[1][1] - B[1][1])] = 1;
  for(int i = 1;i <= H;++i) {
    for(int j = 1;j <= W;++j) {
      REP(k, 100 * 90) {
        if(i != 1) {
          dp[i][j][abs(k + (A[i][j] - B[i][j]))] |= dp[i - 1][j][k];
          dp[i][j][abs(k - (A[i][j] - B[i][j]))] |= dp[i - 1][j][k];
          dp[i][j][abs(k + (B[i][j] - A[i][j]))] |= dp[i - 1][j][k];
          dp[i][j][abs(k - (B[i][j] - A[i][j]))] |= dp[i - 1][j][k];
        }
        if(j != 1) {
          dp[i][j][abs(k + (A[i][j] - B[i][j]))] |= dp[i][j - 1][k];
          dp[i][j][abs(k - (A[i][j] - B[i][j]))] |= dp[i][j - 1][k];
          dp[i][j][abs(k + (B[i][j] - A[i][j]))] |= dp[i][j - 1][k];
          dp[i][j][abs(k - (B[i][j] - A[i][j]))] |= dp[i][j - 1][k];
        }
      }
    }
  }
  REP(i, 90 * 100) {
    if(dp[H][W][i] != 0) {
      cout << i << endl;
      return 0;
    }
  }
}