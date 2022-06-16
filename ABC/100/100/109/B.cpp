#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  REP(i, N) cin >> S[i];
  REP(i, N) for (int j = i + 1; j < N; ++j) {
    if (S[i] == S[j]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 1; i < N; ++i) {
    if (S[i - 1].back() != S[i][0]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}