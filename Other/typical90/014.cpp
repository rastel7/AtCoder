#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N)cin >> A[i];
  REP(i, N)cin >> B[i];
  ll ans = 0;
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  REP(i, N)ans += abs(A[i] - B[i]);
  cout << ans << endl;
}