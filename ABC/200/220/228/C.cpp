#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> A(N, vector<int>(3));
  vector<int> sm;
  REP(i, N) {
    cin >> A[i][0] >> A[i][1] >> A[i][2];
    sm.emplace_back(A[i][0] + A[i][1] + A[i][2]);
  }
  sort(sm.begin(), sm.end());
  sm.emplace_back(100000);
  REP(i, N) {
    int tmp = A[i][0] + A[i][1] + A[i][2] + 300;
    auto itr = upper_bound(sm.begin(), sm.end(), tmp);
    auto dist = sm.end() - (--itr) - 1;
    //cerr << dist << "\n";
    if(dist <= K) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}