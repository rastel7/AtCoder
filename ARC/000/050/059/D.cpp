#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string S;
  cin >> S;
  map<int, int> mp;
  auto f = [&](int n) {
    REP(i, S.size() + 1 - n) {
      map<char, int> mp;
      REP(j, n)mp[S[i + j]]++;
      for(auto [l, r] : mp) {
        if(r * 2 > n) {
          cout << i + 1 << " " << i + n << endl;
          return true;
        }
      }
    }
    return false;
  };
  if(f(2))return 0;
  if(f(3))return 0;
  if(f(5))return 0;
  if(f(7))return 0;
  cout << -1 << " " << -1 << endl;
}