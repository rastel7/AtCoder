#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  set<int> s;
  for(ll i = 1;i <= 2 * N + 1;i++) {
    s.insert(i);
  }
  REP(i, N+1) {
    cout << *s.begin() << endl;
    s.erase(*s.begin());

    int x;
    cin >> x;
    s.erase(x);
  }
  return 0;
}