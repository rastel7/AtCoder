#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string T = "";
  REP(i, 20) {
    T += "oxx";
  }
  string S;
  cin >> S;
  REP(i, T.size() - S.size()) {
    string tmp = T.substr(i, S.size());
    if(tmp == S) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}