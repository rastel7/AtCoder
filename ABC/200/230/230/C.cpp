#include<bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll P, Q, R, S;
  cin >> P >> Q >> R >> S;
  vector<vector<char>> ans(Q - P + 1, vector<char>(S - R + 1));
  REP(i, Q - P + 1) {
    REP(j, S - R + 1) {
      ll y = i + P, x = j + R;
      //cerr << y << " " << x << endl;
      if(A - B == y - x || y + x == A + B) {
        ans[i][j] = '#';
      } else {
        ans[i][j] = '.';
      }
    }
  }
  REP(i, ans.size()) {
    REP(j, ans[i].size())cout << ans[i][j];
    cout << "\n";
  }
}