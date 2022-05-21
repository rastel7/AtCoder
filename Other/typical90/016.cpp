#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A, B, C;
  cin >> A >> B >> C;
  ll ans = 1e18;
  REP(i, 10000) {
    REP(j, 10000) {
      if(i * A + B * j > N)continue;
      if((N - i * A - B * j) % C != 0)continue;
      ans = min(ans, i + j + (N - i * A - B * j) / C);
    }
  }
  cout << ans << endl;
}