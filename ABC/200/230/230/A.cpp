#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  if(N >= 42)N++;
  string ans = "AGC";
  if(N < 10) {
    ans += "00";
  } else {
    ans += "0";
  }
  ans += to_string(N);
  cout << ans << endl;
}