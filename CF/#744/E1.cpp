#include<bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0;i < n;++i)cin >> A[i];
  int mx = 1e9 + 100;
  deque<int> que;
  for(int i = 0;i < n;++i) {
    if(A[i] < mx) {
      que.push_front(A[i]);
      mx = A[i];
    } else {
      que.emplace_back(A[i]);
    }
  }
  bool b = 1;
  for(auto& x : que) {
    if(!b)cout << " ";
    cout << x;
    b = 0;
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}