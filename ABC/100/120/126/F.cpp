#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll M;
  ll K;
  cin >> M >> K;
 
  if(M == 1) {
    if(K == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  if(K >= (1ll << M)) {
    cout << -1 << endl;
    return 0;
  }
   if(M == 0) {
    cout << "0 0" << endl;
    return 0;
  }
  vector<int> ans;
  REP(i, (1 << M)) { if(i == K)continue; ans.emplace_back(i); }
  auto cp = ans;
  reverse(cp.begin(), cp.end());
  ans.emplace_back(K);
  for(auto x : cp)ans.emplace_back(x);
  ans.emplace_back(K);
  REP(i,ans.size()){
    cout<<ans[i];
    if(i!=ans.size()-1)cout<<" ";
  }
  cout << endl;
}