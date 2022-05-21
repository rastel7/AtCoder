#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N);
  REP(i, N) {
    int l;
    cin >> l;
    A[i].resize(l);
    REP(j, l) {
      cin >> A[i][j];
    }
  }
  sort(A.begin(), A.end());
  A.erase(std::unique(A.begin(), A.end()), A.end());
  cout << A.size() << endl;
}