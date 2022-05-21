#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll modPow(long long a, long long n) {
  if(n == 0) return 1; // 0乗にも対応する場合
  if(n == 1) return a;
  if(n % 2 == 1) return (a * modPow(a, n - 1));
  long long t = modPow(a, n / 2);
  return (t * t);
}
int main() {
  ll N;
  cin >> N;
  ll ans = 62;
  for(;;ans--) {
    ll a = modPow(2, ans);
    if(modPow(2, ans) <= N) {
      cout << ans << endl;
      return 0;
    }
  }
}