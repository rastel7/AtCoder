#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll f(vector<ll> X) {
  sort(X.begin(), X.end());
  if(X.size() % 2 == 1) {
    return X[X.size() / 2];
  } else {
    return (X[X.size() / 2] + X[X.size() / 2 -1]) ;
  }
}
int main() {
  int N;cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N)cin >> A[i] >> B[i];
  ll ans = f(B) - f(A)+1;
  if(N % 2 == 0) {
    //ans += ans - 1;
  }
  cout << ans << endl;  
}