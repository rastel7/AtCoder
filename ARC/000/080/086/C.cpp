#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  map<int, int> mp;
  REP(i, N)mp[A[i]]++;
  vector<int> B;
  for(auto& b : mp)B.emplace_back(b.second);
  sort(B.begin(), B.end());
  ll ans = 0;
  for(int i = 0;B.size() - i > K;++i) {
    ans += B[i];
  }
  cout << ans << endl;
}