#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  int A[2][2];
  REP(i, 2) REP(j, 2) cin >> A[i][j];
  cout << A[r - 1][c - 1] << endl;
}