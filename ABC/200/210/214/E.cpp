#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 10000;
const ll MOD = 1000000007;
int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector<P> A(N);
    priority_queue<ll, vector<ll>, greater<ll>> queue;
    REP(i, N)cin >> A[i].first >> A[i].second;
    sort(A.begin(), A.end());
    bool ok = true;
    ll x = 1;
    A.emplace_back(P(INF, INF));
    for(auto [l, r] : A) {
      while(x < l && queue.size()) {
        if(queue.top() < x) {
          ok = false;
          break;
        }
        queue.pop();
        ++x;
      }
      x = l;
      queue.push(r);
    }
    if(ok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}