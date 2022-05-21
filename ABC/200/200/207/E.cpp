#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const int MAX_N = 3030;
mint dp[MAX_N][MAX_N];
int main() {
  int N;
  cin >> N;
  vector<mint> A(N);
  vector<ll> sum(N + 1);

  REP(i, N) {
    ll a;
    cin >> a;
    A[i] = a;
    sum[i + 1] = sum[i] + a;
  }
  dp[1][0] = 1;
  mint ans = 0;
  REP(i, N) {
   for(int j=N; 1<=j; j--){
            dp[j+1][sum[i+1]%(j+1)] += dp[j][sum[i+1]%j];
            if(i == N-1){
                ans += dp[j][sum[i+1]%j];
            }
        }   
    }
    cout << ans.val() << endl;
}