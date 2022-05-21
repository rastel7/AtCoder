#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int a[11];
int main() {
  REP(i, 10)cin >> a[i];
  int now = 0;
  REP(i, 3) {
    now = a[now];
  }
  cout << now << endl;
}