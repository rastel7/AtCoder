#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<tuple<ll, ll, ll>> A(N);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    A[i] = make_tuple(a + b, a, b);
  }
  sort(A.begin(), A.end());
  ll now = -INF;
  int ans = 0;
  for(auto& i : A) {
    ll X = get<1>(i), L = get<2>(i);
    if(X - L < now)continue;
    ans++;
    now = X + L;
  }
  cout << ans << endl;
}