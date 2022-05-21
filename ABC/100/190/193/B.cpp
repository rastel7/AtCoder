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
  int ans = 1e9 + 100;
  REP(i, N) {
    int a, b, c;
    cin >> a >> b >> c;
    if(c - a > 0) {
      ans = min(ans, b);    
}
  }
  if(ans == 1e9 + 100)ans = -1;
  cout << ans << endl;
}