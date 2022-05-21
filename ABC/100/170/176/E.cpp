#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll H, W, M;
  cin >> H >> W >> M;
  vector<ll> A(H), B(W);
  set<pair<int, int>> s;
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    s.insert({ a,b });
    A[a]++, B[b]++;
  }
  set<int> tate, yoko;
  int h = 0, w = 0;
  REP(i, H) { if(A[h] < A[i])h = i; }
  REP(i, W) { if(B[w] < B[i])w = i; }
  REP(i, H) {
    if(A[i] == A[h])tate.insert(i);
  }
  REP(i, W) {
    if(B[i] == B[w])yoko.insert(i);
  }
  ll ans = A[h] + B[w];
  for(auto a : tate) {
    for(auto b : yoko) {
      if(!s.count({ a,b })) {
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << ans - 1 << endl;
}