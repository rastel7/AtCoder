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
  vector<int> P(N);
  REP(i, N)cin >> P[i], P[i]--;
  vector<int> ans(N);
  REP(i, N) {
    ans[P[i]] = i + 1;
  }
  REP(i, N) {
    cout << ans[i];
    if(i != N - 1)cout << " ";
  }
  cout << endl;
}