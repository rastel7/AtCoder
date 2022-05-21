#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for(int i = 0;i < M;++i) {
    cin >> A[i] >> B[i], A[i]--, B[i]--;
  }
  vector<long long> Ans(M + 1);
  Ans[M] = (N * (N - 1)) / 2;
  dsu uf(N);
  for(int i = M - 1;i >= 0;i--) {
    if(uf.same(A[i], B[i])) {
      Ans[i] = Ans[i + 1];
      continue;
    }
    long long a = uf.size(A[i]), b = uf.size(B[i]);
    Ans[i] = Ans[i + 1] - a * b;
    uf.merge(A[i], B[i]);
  }
  for(int i = 1;i <= M;++i) {
    cout << Ans[i] << endl;
  }
}