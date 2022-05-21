#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  A.emplace_back(1e18);
  sort(A.begin(), A.end());
  while(Q--) {
    ll x;
    cin >> x;
    auto itr = lower_bound(A.begin(), A.end(), x) - A.begin();
    cout << N - itr << endl;
  }
}