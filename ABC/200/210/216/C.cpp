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
  ll now = 0;
  string ans = "";
  while(N > 0) {
    if(N & 1) {
      ans += 'A';
      N--;
    }
    if(N == 0)break;
    ans += 'B';
    N = N >> 1;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  for(auto a : ans) {
    if(a == 'A') now++;
    else now *= 2;
  }
  //cerr << now << endl;
}