#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll s, t;
  cin >> s >> t;
  ll ans = 0;
  for(ll a = 0;a <= s;++a) {
    for(ll b = 0;a + b <= s;++b) {
      for(ll c = 0;a + b + c <= s && a * b * c <= t;++c)ans++;
    }
  }
  cout << ans << endl;
}