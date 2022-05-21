#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  REP(i, N)cin >> A[i];
  REP(i, N)cin >> B[i];
  REP(i, N)cin >> C[i];
  map<int, int> mp;
  REP(i, N) {
    mp[B[C[i] - 1]]++;
  }
  ll ans = 0;
  REP(i, N)ans += mp[A[i]];
  cout << ans << endl;
}