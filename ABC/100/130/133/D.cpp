#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> ans(N);
  ll sum = 0;
  REP(i, N) {
    if (i % 2 == 0)
      sum += A[i];
    else
      sum -= A[i];
  }
  ans[0] = sum;
  for (int i = 1; i < N; ++i) {
    ans[i] = 2*(A[i - 1] - ans[i - 1] / 2);
  }
  auto itr = ans.begin();
  while (itr != ans.end()) {
    cout << *itr;
    if (++itr != ans.end()) cout << " ";
  }
  cout << endl;
}