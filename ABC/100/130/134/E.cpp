#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const ll INF = 1e18;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N)cin >> A[i];
  reverse(A.begin(), A.end());
  vector<ll> dp(N + 1, INF);
  for(auto a : A) {
    auto itr = upper_bound(dp.begin(), dp.end(), a) - dp.begin();//広義
    dp[itr] = a;
  }
  cout << (lower_bound(dp.begin(), dp.end(), INF) - dp.begin()) << endl;
}