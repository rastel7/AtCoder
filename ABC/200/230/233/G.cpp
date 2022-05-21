#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<string> S;
int dp[51][51][51][51];
int f(int y, int x, int h, int w) {
  if(h <= 0 || w <= 0)return 0;
  if(dp[y][x][h][w] != -1)return dp[y][x][h][w];
  int ret = max(h, w);
  REP(i, h) {
    bool t = 1;
    REP(j, w) {
      if(S[i + y][j + x] == '#')t = 0;
    }
    if(t) {
      ret = min(ret, f(y, x, i, w) + f(y + i + 1, x, h - i - 1, w));
    }
  }

  REP(i, w) {
    bool t = 1;
    REP(j, h) {
      if(S[j + y][i + x] == '#')t = 0;
    }
    if(t) {
      ret = min(ret, f(y, x, h, i) + f(y, x + i + 1, h, w - i - 1));
    }
  }
  return dp[y][x][h][w] = ret;
}
int main() {
  REP(i, 51)REP(j, 51)REP(k, 51)REP(l, 51)dp[i][j][k][l] = -1;
  int N;
  cin >> N;
  S.resize(N);
  REP(i, N)cin >> S[i];
  cout << f(0, 0, N, N) << endl;
}