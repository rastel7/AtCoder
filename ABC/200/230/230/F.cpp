#include<bits/stdc++.h>
#include<atcoder/all>
using mint = atcoder::modint998244353;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  int cnt = 0;
  for(int l = 0;l < N;++l) {
    for(int r = l + 1;r < N;++r) {
      ll tmp = 0;
      for(int i = l;i <= r;++i) {
        tmp += A[i];
      }
      if(tmp == 0)cnt++;
    }
  }
  cout << cnt << endl;
}