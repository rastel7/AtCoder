#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct work {
  int A, B;
  bool operator<(const work& right) const {
    if(A == right.A) {
      return B > right.B;

    }
    return A < right.A;
  }
};
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A((int)1e5 + 100);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    A[a].emplace_back(b);
  }
  priority_queue<int> que;
  int ans = 0;
  for(int day = 1;day <= M;++day) {
    for(auto x : A[day]) {
      que.push(x);
    }
    if(!que.empty()) {
      ans += que.top();que.pop();
    }
  }
  cout << ans << endl;
}