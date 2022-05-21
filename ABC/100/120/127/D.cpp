#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M), C(M);
  REP(i, N)cin >> A[i];
  REP(i, M)cin >> B[i] >> C[i];
  map<int, int> mp;
  REP(i, N)mp[A[i]]++;
  REP(i, M)mp[C[i]] += B[i];
  vector<P> T;
  for(auto& t : mp)T.emplace_back(P(t.first, t.second));
  sort(T.begin(),T.end(),greater<>());
  ll ans = 0, now = 0;
  for(int i = 0;now < N;++i) {
    ll dif = min<ll>(T[i].second, N - now);
    ans += dif * T[i].first;
    now += dif;
  }
  cout << ans << endl;
}