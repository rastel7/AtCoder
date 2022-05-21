#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string s;cin >> s;
  int siz = s.size();
  int obj = *s.begin() == s.back() ? 1 : 0;

  if(siz % 2 != obj) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}