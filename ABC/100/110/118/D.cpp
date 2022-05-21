#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
bool hikaku(string const& s, string  const& r) {
  if(s == "-" || s == "")return true;
  if(r == "-")return false;
  if(s.size() != r.size())return r.size() > s.size();
  REP(i, s.size()) {
    if(s[i] == r[i])continue;
    return r[i] > s[i];
  }
  return false;
};
int sy[] = { 2,5,5,4,5,6,3,7,6 };
string dp[10100];
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  REP(i, M) {
    cin >> A[i], A[i]--;
  }
  dp[0] = "-";
  REP(i, N) {
    REP(j, A.size()) {
      auto s = dp[i + sy[A[j]]];
      auto r = dp[i];
      if(r == "")continue;
      if(r == "-")r = A[j] + '1';
      else r += (A[j] + '1');
      if(hikaku(s, r))dp[i + sy[A[j]]] = r;
    }
  }
  cout << dp[N] << endl;
}