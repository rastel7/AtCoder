#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  REP(i, N)cin >> P[i];
  int prev_ans = 0;
  set<int> s;
  REP(i, K)s.insert(P[i]);
  prev_ans = *(s.begin());
  cout << prev_ans << endl;
  for(int i = K ;i < N;++i) {
    s.insert(P[i]);
    if(P[i] > prev_ans) {
      auto itr = s.lower_bound(prev_ans);
      prev_ans = *(next(itr));
    }
    cout << prev_ans << "\n";
  }
}