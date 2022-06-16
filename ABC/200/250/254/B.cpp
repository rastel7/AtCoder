#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N);
  int n = 0;
  REP(i, N) {
    A[i].resize(n + 1);
    for (int j = 0; j <= n; ++j) {
      if (j == 0 || j == n) {
        A[i][j] = 1;
        continue;
      }
      A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
    }
    n = A[i].size();
  }
  REP(i, N) {
    REP(j, A[i].size()) {
      cout << A[i][j];
      if (A[i].size() != j + 1) {
        cout << " ";
      }
    }
    cout << "\n";
  }
}