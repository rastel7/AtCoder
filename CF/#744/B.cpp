#include<bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<tuple<int, int, int>> Ans(0);
  for(int i = 0;i < n;++i)cin >> A[i];
  for(int i = 0;i < n - 1;++i) {
    int mn = 1e9 + 100, id = -1;
    for(int j = i;j < n;++j) {
      if(A[j] < mn) {
        mn = A[j], id = j;
      }
    }
    if(i == id)continue;
    Ans.emplace_back(make_tuple(i + 1, id + 1, id-i));
    for(int j = id;j >= i + 1;--j)A[j] = A[j - 1];
    A[i] = mn;
  }
  cout << Ans.size() << endl;
  for(auto& x : Ans) {
    cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}