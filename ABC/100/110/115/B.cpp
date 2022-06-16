#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  sort(A.begin(), A.end());
  A[A.size() - 1] /= 2;
  cout << accumulate(A.begin(), A.end(), 0ll) << endl;
}