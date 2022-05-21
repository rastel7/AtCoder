#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N)cin >> A[i];
  REP(i, N)cin >> B[i];
  int ans = 0;
  set<int> s;
  REP(i, N) {
    s.insert(A[i]);
  }
  REP(i, N) {
    if(A[i] == B[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  int ans2 = 0;
  REP(i, N) {
    if(s.count(B[i]))ans2++;
  }
  cout << ans2 - ans << endl;
}