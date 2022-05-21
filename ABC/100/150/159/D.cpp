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
  vector<ll> A(N);
  map<ll, ll> mp;
  REP(i, N)cin >> A[i], mp[A[i]]++;
  ll ans = 0;
  for(auto& p : mp) {
    ans += (p.second) * (p.second - 1) / 2;
  }
  REP(i, N) {
    cout << ans - (mp[A[i]]) * (mp[A[i]] - 1) / 2 + (mp[A[i]] - 2) * (mp[A[i]] - 1) / 2 << endl;
  }
}