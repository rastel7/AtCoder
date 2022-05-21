#include<bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, t;
  cin >> n >> m >> t;
  int MAX = max(n, m);
  vector<string> A(n);
  for(int i = 0;i < n;++i)cin >> A[i];
  vector<vector<int>> T(n, vector<int>(m, 0));
  auto f = [&](int y, int x, int k) {
    if(A[y][x] == '.')return false;
    for(int i = 1;i <= k;++i) {
      if(y - i < 0)return false;
      if(x - i < 0)return false;
      if(x + i >= m)return false;
      if(A[y - i][x - i] == '.')return false;
      if(A[y - i][x + i] == '.')return false;
    }
    return true;
  };
  for(int i = 0;i < n;++i) {
    for(int j = 0;j < m;++j) {
      for(int k = MAX;k >= t;--k) {
        if(f(i, j, k)) {
          for(int l = 0;l <= k;++l) {
            T[i - l][j - l] = 1;
            T[i - l][j + l] = 1;
          }
          break;
        }
      }
    }
  }
  for(int i = 0;i < n;++i) {
    for(int j = 0;j < m;++j) {
      if(A[i][j] == '*') {
        if(T[i][j] == 0) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}