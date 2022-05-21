#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  vector<int> A(10);
  REP(i, 10)cin >> A[i];
  int n;
  cin >> n;
  vector<string> S(n);
  REP(i, n)cin >> S[i];
  sort(S.begin(), S.end(), [&](string l, string r) {
    if(l.size() != r.size())return l.size() < r.size();
    REP(i, l.size()) {
      if(l[i] == r[i])continue;
      REP(j, 10) {
        if(l[i] - '0' == (A[j]))return true;
        if(r[i] - '0' == (A[j]))return false;
      }
    }
    return true;
    });
  for(auto& x : S) {
    cout << x << endl;
  }
}