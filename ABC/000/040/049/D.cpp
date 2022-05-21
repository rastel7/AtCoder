#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int main() {
  int N, K, L;
  cin >> N >> K >> L;
  dsu road(N), train(N);
  REP(i, K) {
    int a, b;
    cin >> a >> b, a--, b--;
    road.merge(a, b);
  }
  REP(i, L) {
    int a, b;
    cin >> a >> b, a--, b--;
    train.merge(a, b);
  }
  vector<int> ans(N, -1);
  vector<set<int>> bs(N), ss(N);
  REP(i, N) {
    bs[road.leader(i)].insert(i);
    ss[train.leader(i)].insert(i);
  }
  REP(i, N) {
    if(!bs[road.leader(i)].count(i))continue;
    set<int> tmp = { i };
    if(bs[road.leader(i)].size() < ss[train.leader(i)].size()) {
      for(auto a : bs[road.leader(i)]) {
        if(train.same(i, a)) {
          tmp.insert(a);
        }
      }
      for(auto t : tmp) {
        ans[t] = tmp.size();
      }
      for(auto t : tmp) {
        bs[road.leader(i)].erase(t);
        ss[road.leader(i)].erase(t);
      }
    } else {
      for(auto a : ss[train.leader(i)]) {
        if(road.same(i, a)) {
          tmp.insert(a);
        }
      }
      for(auto t : tmp) {
        ans[t] = tmp.size();
      }
      for(auto t : tmp) {
        bs[road.leader(i)].erase(t);
        ss[road.leader(i)].erase(t);
      }
    }
  }
  REP(i, N) {
    cout << ans[i] << " ";
  }
  cout << endl;
}