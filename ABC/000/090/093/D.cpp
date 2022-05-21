#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  ll N, A, B;
  cin >> A >> B;
  if(A > B)swap(A, B);
  N = A * B;
  ll K = sqrt(N - 1)-1;
  while((K+1)*(K+1)<N)K++;
  ll ans = K * 2;
  if(K * (K + 1) >= N )ans--;
  if(K >= A) {
    ans--;
  }
  cout <<ans << endl;
}
int main() {
  ll Q;
  cin >> Q;
  while(Q--) {
    solve();
  }
}