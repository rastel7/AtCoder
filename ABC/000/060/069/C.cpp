#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll N, M;
  cin >> N >> M;
  ll ans = 0;
  if(N > M / 2) {
    cout << M / 2 << endl;
    return 0;
  } else {
    ans += N + (M - 2 * N) / 4;
  }
  cout << ans << endl;
}