#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
  ll A, B;
  cin >> A >> B;
  printf("%s\n", (A + B) % 2 == 0 ? "YES" : "NO");
}
int main() {
  ll T;
  cin >> T;
  REP(i,T)solve();
}