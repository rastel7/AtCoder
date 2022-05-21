#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) {
    cin >> A[i];
  }
  ll ans = 0;
  int l = 0, r = 0;
  REP(i, N) {
    if(A[r] == 0) {
      ll sum = 0;
      for(int j = l;j <= r;++j) {
        sum += A[j];
      }
      ans += sum / 2;
      l = i, r = i;
    }
    r = i;
  }
  ll sum = 0;
  for(int j = l;j <= r;++j) {
    sum += A[j];
  }
  ans += sum / 2;
  cout << ans << endl;
}