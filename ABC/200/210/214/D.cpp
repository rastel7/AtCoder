#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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
  ll ans = 0;
  vector<tuple<ll, ll, ll>> A(N - 1);
  REP(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    A[i] = make_tuple(c, a, b);
  }
  sort(A.begin(), A.end());
  dsu uf(N);
  vector<ll> G(N, 1);
  REP(i, N - 1) {
    ll a = get<1>(A[i]), b = get<2>(A[i]), c = get<0>(A[i]);
    ll sm = G[uf.leader(a)] * G[uf.leader(b)];
    ans += sm * c;
    sm = G[uf.leader(a)] + G[uf.leader(b)];
    G[uf.leader(a)] = sm;
    G[uf.leader(b)] = sm;
    uf.merge(a, b);
  }
  cout << ans << endl;
}