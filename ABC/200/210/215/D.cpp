#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
map<ll, ll> prime_factorization(long long n) {
  // map<ll,ll> first=素因数 second=first素因数の数
  map<ll, ll> res;
  for(int i = 2; i <= n / i; i++) {
    while(n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if(n != 1)
    res[n]++;
  return res;
}
int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  vector<ll> dp(M + 10, 1);
  dp[0] = 0, dp[1] = 1;
  set<ll> s;
  REP(i, N) {
    auto mp = prime_factorization(A[i]);
    for(auto& a : mp) {
      s.insert(a.first);
    }
  }
  for(auto& a : s) {
    if(a == 1)continue;
    for(ll i = 1;i <= M / a;++i) {
      dp[i * a] = 0;
    }
  }
  int ansnum = 0;
  for(int i = 1;i <= M;++i) {
    if(dp[i]) {
      //cout << i << endl;
      ansnum++;
    }
  }
  cout << ansnum << "\n";
  for(int i = 1;i <= M;++i) {
    if(dp[i]) {
      cout << i << "\n";
    }
  }
}