#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  set<ll> A;
  REP(i, N) {
    ll a;
    cin >> a;
    A.insert(a);
  }
  cout << A.size() << endl;
}