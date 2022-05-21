#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  set<ll> s;
  REP(i, N) {
    cin >> A[i];
    s.insert(A[i]);
  }
  REP(i, 10000) {
    if(!s.count(i)) {
      cout << i << endl;
      return 0;
    }
  }
}