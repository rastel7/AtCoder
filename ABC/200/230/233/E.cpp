#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string X;
  cin >> X;
  reverse(X.begin(), X.end());
  vector<char> ans(X.size());

  ll sum = 0;
  REP(i, X.size())sum += X[i] - '0';
  ll prev = 0;
  REP(i, X.size()) {

    if(i != 0) {
      sum -= X[i - 1] - '0';
    }
    ll tmp = sum + prev;
    prev = tmp / 10;
    ans[i] = (tmp % 10) + '0';
  }
  while(prev != 0) {
    ans.emplace_back(prev % 10+'0');
    prev /= 10;
  }
  reverse(ans.begin(), ans.end());
  for(auto x : ans)cout << x;
  cout << endl;
}