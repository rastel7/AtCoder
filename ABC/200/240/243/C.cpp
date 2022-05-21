#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<ll> Y(N), X(N);
  REP(i, N)cin >> X[i] >> Y[i];
  vector<tuple<ll, ll, char>> V(N);

  string S;
  cin >> S;
  REP(i, N) {
    V[i] = { Y[i],X[i] ,S[i] };
  }
  sort(V.begin(), V.end());
  set<int> l;
  REP(i, N) {
    auto [y, x, c] = V[i];
    //cerr << y << "," << x << "," << c << endl;
    if(c == 'L') {
      if(l.count(y)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    if(c == 'R') {
      l.insert(y);
    }
  }
  cout << "No" << endl;
}