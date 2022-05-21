#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int X, Y;
  cin >> X >> Y;
  ll ans = max(0, (Y - X + 9) / 10);
  cout << ans << endl;
  
}