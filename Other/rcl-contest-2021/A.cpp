#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int N, M, K;
P to_x(vector<int> const& A, int x) {
  REP(i, N)REP(j, N) {
    if((A[i] + A[j]) % K <= x) {
      return P(max(i, j), max(i, j));
    }
  }
  return P(-1, -1);
}
int main() {
  cin >> N >> M >> K;
  vector<int> A(N);
  REP(i, N) {
    cin >> A[i];
  }
  vector<P> ans(M, P(-1, -1));
  REP(j, M) {
    bool ok = false;
    REP(x, 4) {
      auto p = to_x(A, x);
      if(p.first == -1)continue;
      ans[j] = p;
      A[p.first] = (A[p.first] + A[p.second]) % K;
      ok = 1;
      break;
    }
    if(ok) {
      continue;
    }
    bool end = 0;
    REP(i, N) {
      if(A[i] > 1)end = 1;
    }
    if(!end)break;
    int id = 0, mx = -1;
    REP(i, N) {
      if(mx < A[i]) {
        id = i, mx = A[i];
      }
    }
    ans[j] = P(id, id);
    A[id] = (A[id] + A[id]) % K;
  }
  for(auto& a : ans) {
    if(a.first == -1)break;
    cout << a.first << " " << a.second << endl;
  }
}