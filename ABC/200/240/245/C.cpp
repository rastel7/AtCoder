#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), B(N);
  REP(i, N) {
    cin >> A[i];
  }
  REP(i, N) {
    cin >> B[i];
  }
  set<int> s;
  s.insert(A[0]);
  s.insert(B[0]);
  for(int i = 1;i <= N;++i) {
    if(s.empty()) {
      cout << "No" << endl;
      return 0;
    }
    if(i == N)break;;
    set<int> next;
    for(auto c : s) {
      if(abs(c - A[i]) <= K)next.insert(A[i]);
      if(abs(c - B[i]) <= K)next.insert(B[i]);
    }
    s = next;
  }
  cout << "Yes" << endl;
}