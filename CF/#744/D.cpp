#include<bits/stdc++.h>
using namespace std;
void solve() {
  int n;cin >> n;
  vector<int> A(n);
  vector<pair<int, int>> ans(0);
  vector<pair<int, int>> T(0);
  priority_queue<pair<int, int>>que1;
  for(int i = 0;i < n;++i) {
    cin >> A[i];
    if(A[i] != 0) {
      T.emplace_back(make_pair(A[i], i));
      que1.push(make_pair(A[i], i));
    }
  }
  while(que1.size() >= 2) {
    auto l = que1.top();
    que1.pop();
    auto r = que1.top();
    que1.pop();
    ans.emplace_back(make_pair(l.second + 1, r.second + 1));
    if(l.first != 1)que1.push(make_pair(l.first-1, l.second));
    if(r.first != 1)que1.push(make_pair(r.first-1, r.second));
  }
  cout << ans.size() << endl;
  for(auto& x : ans) {
    cout << x.first << " " << x.second << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}