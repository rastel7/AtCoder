#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M);
  map<int, int> mp;
  REP(i, N)cin >> A[i];
  REP(i, M)cin >> B[i];
  REP(i, N)mp[A[i]]++;
  REP(i, M) {
    if(mp[B[i]] <= 0) {
      cout << "No" << endl;
      return 0;
    }
    mp[B[i]]--;
  }
  cout << "Yes" << endl;
}