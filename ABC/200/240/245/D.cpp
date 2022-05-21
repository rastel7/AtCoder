#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N + 1);
  vector<ll> C(N + M + 1);
  REP(i, N + 1)cin >> A[i];
  REP(i, N + M + 1)cin >> C[i];
  vector<ll> B(M + 1);
  B[M] = C[N + M] / A[N];
  int K = N + M - 1;
  for(int i = M - 1;i >= 0;i--) {
    ll sum = 0;
    for(int j = M;j > i;j--) {
      if(N >= K - j && K - j >= 0)
        sum += B[j] * A[K - j];
    }
    B[i] = (C[K] - sum) / A[N];
    K--;
  }
  REP(i, M + 1) {
    cout << B[i];
    if(i != M) {
      cout << " ";
    }
  }
  cout << endl;
}

/*B[M - 1] = C[N + M - 1] / A[N - 1];
int cnt =1;
for(int i = M - 2;i >= 0;i--) {
  ll sum = 0;
  for(int j=1;j<cnt;++j){
    sum+=B[i+j]*
  }
  cnt++;
}
}*/