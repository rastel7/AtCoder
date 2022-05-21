#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 510;
int dp[MAX_SIZE][MAX_SIZE];
int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  while(M--) {
    int L, R;
    cin >> L >> R;
    dp[L][R] += 1;
  }
  for(int i = 0;i < MAX_SIZE - 3;++i) {
    for(int j = 0;j < MAX_SIZE - 3;++j) {
      dp[i][j + 1] += dp[i][j];
    }
  }
  for(int i = 0;i < MAX_SIZE - 3;++i) {
    for(int j = 0;j < MAX_SIZE - 3;++j) {
      dp[j + 1][i] += dp[j][i];
    }
  }
  while(Q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[r][r] - dp[l - 1][r] - dp[r][l - 1] + dp[l - 1][l - 1] << endl;
  }
}