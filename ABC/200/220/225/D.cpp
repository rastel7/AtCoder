#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
void dfs(vector<pair<int, int>> const& A, vector<int>& ret, int id) {
  ret.emplace_back(id);
  if(A[id].first == -1)return;
  dfs(A, ret, A[id].first);
}
void dfs2(vector<pair<int, int>>  const& A, vector<int>& ret, int id) {
  if(A[id].second == -1) { dfs(A, ret, id);return; }
  dfs2(A, ret, A[id].second);
}
int main() {
  int N, Q;
  cin >> N >> Q;
  vector<pair<int, int>> A(N, make_pair(-1, -1));
  while(Q--) {
    int q;
    cin >> q;
    if(q == 1) {
      int l, r;
      cin >> l >> r, l--, r--;
      A[r].first = l;
      A[l].second = r;
    } else if(q == 2) {
      int l, r;
      cin >> l >> r, l--, r--;
      A[r].first = -1;
      A[l].second = -1;
    } else {
      int x;
      cin >> x, x--;

      vector<int> ans;
      dfs2(A, ans, x);
      reverse(ans.begin(), ans.end());
      cout << ans.size() << " ";
      REP(i, ans.size()) {
        cout << ans[i] + 1;
        if(i != ans.size() - 1)cout << " ";
      }
      cout << endl;
    }
  }
}