#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  map<string, int> mp;
  REP(i, N) {
    string a;
    cin >> a;
    mp[a]++;
  }
  int ans = -1;
  string s = "";
  for(auto [l, r] : mp) {
    if(r > ans) {
      ans = r;
      s = l;
    }
  }
  cout << s << endl;
}