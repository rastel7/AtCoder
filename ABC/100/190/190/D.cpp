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
  int ans = 0;
  for(ll i = 1;i < (2 * N) / i;++i) {
    if((2 * N) % i == 0) {
      if(i % 2 != ((2 * N) / i) % 2)
        ans++;
    }
  }

  cout << ans*2 << endl;
}