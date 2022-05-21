#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int N;
vector<vector<int>> A;
const int MAX_N = 2 * 1e5 + 1000;
int passed[MAX_N];
vector<int> ans;
void dfs(int id) {
  ans.emplace_back(id);
  passed[id] = 1;
  for(auto& i : A[id]) {
    if(passed[i] == 1)continue;
    dfs(i);
    ans.emplace_back(id);
  }
  return;
}
int main() {
  cin >> N;
  A.resize(N);
  REP(i, N - 1) {
    int x, y;
    cin >> x >> y, x--, y--;
    A[x].emplace_back(y);
    A[y].emplace_back(x);
  }
  REP(i, N) {
    sort(A[i].begin(), A[i].end());
  }
  dfs(0);
  REP(i, ans.size() - 1)cout << ans[i]+1 << " ";
  cout << ans.back()+1 << endl;
}