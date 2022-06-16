#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N - 1), B(N + 1);
  REP(i, N - 1) cin >> A[i];
  REP(i,N-1){
    B[A[i]]++;
  }
  for(int i=1;i<=N;++i){
    cout<<B[i]<<"\n";
  }
}