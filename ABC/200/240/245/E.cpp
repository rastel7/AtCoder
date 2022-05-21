#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct choco {
  ll H, W;
};
int main() {
  int N, M;
  cin >> N >> M;
  vector<choco> A(N), Hako(M);
  REP(i, N) {
    cin >> A[i].H;
  }
  REP(i, N)cin >> A[i].W;
  REP(i, M) {
    cin >> Hako[i].H;
  }
  REP(i, M)cin >> Hako[i].W;
  sort(A.begin(), A.end(), [](choco l, choco r) {
    return l.H < r.H;
    });
  sort(Hako.begin(), Hako.end(), [](choco l, choco r) {
    return l.H < r.H;
    });
  priority_queue<ll, vector<ll>, greater<ll>> que;
  int l = 0;
  map<int, int> mp;
  set<int> s;
  REP(i, M) {
    auto c = Hako[i];
    if(l < N) {
      while(A[l].H <= c.H) {
        if(l >= N) {
          break;
        }
        s.insert(A[l].W);
        mp[A[l].W]++;
        que.push(A[l].W);
        l++;
      }
    }
    auto x = s.upper_bound(c.W);
    if(x == s.begin())continue;
    x--;
    if(x == s.end())continue;
    mp[*x]--;
    if(mp[*x] == 0) {
      s.erase(*x);
    }
  }
  if(s.empty() && l == N) {
    cout << "Yes" << endl;
  } else {

    cout << "No" << endl;
  }
}
