#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll suuretu(ll a, ll n, ll l) {
  return n * (a + l) / 2;
}
int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for(int i = 1;i <= N;++i) {
    int n = N / i, a = i, l = (n)*i;
    ans += suuretu(a, n, l);  //cout << ans << endl;
  }
  //ans += suuretu(1, N, N);
  cout << ans << endl;
}