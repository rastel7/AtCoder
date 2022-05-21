#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N;
  cin >> N;
  string ans = "";
  while(N != 0) {
    if(N % 2 == 0) {
      ans += "0";
    } else {
      ans += "2";
    }
    N /= 2;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}