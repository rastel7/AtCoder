#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  int ans = 0, cnt = 1;
  while(cnt < B) {
    ans++;
    cnt += A - 1;
  }
  cout << ans << endl;
}