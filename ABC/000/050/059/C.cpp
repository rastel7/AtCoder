#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int n;
vector<ll> A;
ll f(ll id, ll prev, ll sum) {
  if(id == n)return 0;
  sum += A[id];
  ll ret = 0;
  if(sum == 0) {
    ret++;
    if(prev == 1) {
      sum--;
    } else {
      sum++;
    }
  }
  if(prev * sum > 0) {
    ret += abs(sum) + 1;
    sum = prev * -1;
  }
  return ret + f(id + 1, prev * -1, sum);
}
int main() {
  cin >> n;
  A.resize(n);
  REP(i, n)cin >> A[i];
  cout << min(f(0, -1, 0), f(0, 1, 0)) << endl;
}