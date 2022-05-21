#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll X, Y;
  cin >> X >> Y;
  int ans = 0;
  ll  x = X;
  while(x <= Y) {
    ans++;
    x = x * 2;
  }
  cout << ans << endl;
}