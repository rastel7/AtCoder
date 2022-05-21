#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll N;
  cin >> N;
  mint ans = 0;
  for(ll q = 1;q <= N / q;q++) {
    ans += (N / q - q) / 2 + 1;
  }
  cout << ans.val() << endl;
}