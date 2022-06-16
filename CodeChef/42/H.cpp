#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve();
int main() {
  int T;
  cin >> T;
  REP(i, T) solve();
}

void solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> B(N);
  REP(i, N) { B[i] = 1e5 + 100 + i; }
  vector<ll> diff(N);
  REP(i, N) diff[i] = B[i] - A[i];
  vector<vector<ll>> Q;
  REP(i, 20) {
    ll add = 1 << i, count = 0;
    vector<ll> adds;
    REP(j, N) {
      if ((diff[j] & add) != 0) {
        count++;
        adds.emplace_back(j + 1);
        A[j] += add;
      }
    }
    if (count == 0) continue;
    Q.emplace_back(vector<ll>{count, add});
    Q.emplace_back(adds);
  }
  cout << Q.size()/2 << endl;
  for (auto a : Q) {
    REP(i,a.size()){
      cout<<a[i];
      if(i!=a.size()-1)cout<<" ";
    }
    cout << "\n";
  }
  for(auto a:A){
    //cerr<<a<<" ";
  }
}