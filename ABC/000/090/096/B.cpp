#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
  if(a == 0) return 1;
  if(a == 1) return n % mod;
  if(a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  vector<ll> A(3);
  REP(i, 3)cin >> A[i];
  int K;
  cin >> K;
  sort(A.begin(), A.end(), greater<>());
  cout << longpow(2, K, (int)1e18)*A[0] + A[1] + A[2] << endl;
}