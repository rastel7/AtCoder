#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, X;
  cin >> N >> X, X--;
  vector<int> A(N);
  REP(i, N)cin >> A[i], A[i]--;
  set<int> s;
  while(!s.count(X)) {
    s.insert(X);
    X = A[X];
  }
  cout << s.size() << endl;
}