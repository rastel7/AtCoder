#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
  ll X;
  cin >> X;
  if(X < 10) {
    cout << X << endl;
    return 0;
  }
  ll N = to_string(X).size();
  string S = to_string(X);
  vector<ll> V(N);
  REP(i, N)V[i] = S[i] - '0';
  while(true) {
    ll d = V[1] - V[0];
    bool t = 1;
    for(ll nex = 2;nex < V.size();++nex) {
      ll tmp = V[nex - 1] + d;
      if(tmp < 0 || tmp>9) {
        t = 0;
        break;
      }
      if(tmp - V[nex - 1] != V[nex - 1] - V[nex - 2]) {
        t = 0;
        break;
      }
      V[nex] = tmp;
    }
    ll num = 0;
    for(auto x : V) {
      num = num * (ll)10 + x;
    }
    if(num < X) {
      t = 0;
    }
    if(t == 1) {

      for(auto x : V)cout << x;
      cout << endl;
      return 0;
    }
    if(V[1] == 9) {
      if(V[0] == 9) {
        V[0] = 0;
        V.insert(V.begin(), 0);
      } else {
        V[0]++;
      }
      V[1] = 0;
    } else {
      V[1]++;
    }
  }
}