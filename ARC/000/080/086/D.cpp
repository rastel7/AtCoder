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
  vector<int> A(N);
  REP(i, N)cin >> A[i];
  int mx = -1e9, mn = 1e9;
  REP(i, N) {
    mx = max(mx, A[i]);
    mn = min(mn, A[i]);
  }
  int id;
  if(abs(mx) > abs(mn)) {
    REP(i, N) {
      if(mx == A[i])id = i;
    }
  } else {
    REP(i, N) {
      if(mn == A[i])id = i;
    }
  }
  vector<P> ans;
  REP(i, N) {
    if(i == id)continue;
    ans.emplace_back(P(id, i));
  }
  ans.emplace_back(P(id, id));
  if(abs(mx) > abs(mn))
    REP(i, N - 1) { ans.emplace_back(P(i, i + 1)); } else REP(i, N - 1)ans.emplace_back(N - i - 1, N - 1 - i - 1);
  cout << ans.size() << endl;
  REP(i, ans.size()) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
}