#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  REP(i, 27) {
    string tmp = t;
    for(auto& x : tmp) {
      x = (x - 'a' + i) % 26 + 'a';
    }
    if(tmp == s) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}