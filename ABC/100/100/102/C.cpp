#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    cout << (-1 << 1) << endl;
  ll N;
  cin >> N;
  string S = "";
  ll id = 0;
  while(N != 0) {
    if(((N >> id) & 1) == 1) {
      S.push_back('1');
      if(id % 2) {
        N += (1ll << id);
      } else {
        N -= (1ll << id);
      }
    } else {
      S.push_back('0');
    }
    id++;
  }
  if(S.empty())S = "0";
  reverse(S.begin(), S.end());
  cout << S << endl;

}