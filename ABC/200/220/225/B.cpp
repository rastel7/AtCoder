#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int main() {
  int N;
  cin >> N;
  dsu uf(N);
  vector<int> A(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    A[a]++, A[b]++;
  }
  REP(i, N) {
    if(A[i] == N - 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}