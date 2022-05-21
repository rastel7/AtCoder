#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct obj {
  int type;
  int t, x;
};
int main() {
  int N, Q;
  cin >> N >> Q;
  vector<obj> O;
  REP(i, N) {
    int s, t, x;
    cin >> s >> t >> x;
    auto o1 = obj{ 1,s - x,x };
    auto o2 = obj{ 0,t - x,x };
    O.emplace_back(o1);
    O.emplace_back(o2);
  }
  REP(i, Q) {
    int d;
    cin >> d;
    auto o = obj{ 2,d,i };
    O.emplace_back(o);
  }
  vector<int> ans(Q);
  sort(O.begin(), O.end(), [](obj l, obj r) {
    return l.t == r.t ? l.type < r.type : l.t < r.t;
    });
  set<int> t;
  for(auto e : O) {
    switch(e.type) {
    case 1:
      t.insert(e.x);
      break;
    case 0:
      t.erase(e.x);
      break;
    case 2:
      int x;
      if(t.empty()) {
        x = -1;
      } else {
        x = *t.begin();
      }
      ans[e.x] = x;
      break;
    default:
      break;
    }
  }
  for(auto a : ans) {
    cout << a << "\n";
  }
}
