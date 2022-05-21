#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
bool f(vector<P> const& A, ll k) {
  int N = A.size();
  //尺取
  int mi = 1000000001, ma = 0;
  queue<P> que;
  for(auto p : A) {
    while(!que.empty()) {
      if(que.front().first > p.first - k) {
        break;
      }
      mi = min(mi, que.front().second);ma = max(ma, que.front().second);
      que.pop();
    }
    if(mi <= p.second - k || ma >= p.second + k)return true;
    que.push(p);
  }
  return false;
}
int main() {
  int N;
  cin >> N;
  vector<P> A(N);
  REP(i, N)cin >> A[i].first >> A[i].second;
  sort(A.begin(), A.end());
  ll l = -1, r = 1e10;
  while(r - l > 1) {
    ll mid = l + (r - l) / 2;
    if(f(A, mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
}