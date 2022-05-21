#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll H, W, C, Q;
  cin >> H >> W >> C >> Q;
  vector<tuple<int, int, int>> V(Q);
  REP(i, Q) {
    ll a, b, c;
    cin >> a >> b >> c, c--;
    V[i] = make_tuple(a, b, c);
  }
  reverse(V.begin(), V.end());
  set<ll> tate, yoko;
  vector<ll> ans(C + 1);
  for(auto [a, b, c] : V) {
    if(a == 1) {
      if(yoko.count(b))continue;
      ll tmp = W - tate.size();
      ans[c] += tmp;
      yoko.insert(b);
    } else {
      if(tate.count(b))continue;
      ll tmp = H - yoko.size();
      ans[c] += tmp;
      tate.insert(b);
    }
  }
  REP(i, ans.size() - 1) {
    cout << ans[i] << " ";
  }
  cout << endl;
}