#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll H, W, N;
  cin >> H >> W >> N;
  vector<P> A(N);
  set<ll> _X, _Y;
  REP(i, N) {
    int x, y;
    cin >> y >> x;
    A[i] = P(y, x);
    _X.insert(x), _Y.insert(y);
  }
  vector<ll> X, Y;
  for(auto& x : _X)X.emplace_back(x);
  for(auto& y : _Y)Y.emplace_back(y);
  map<ll, ll> retuX, retuY;
  REP(i, X.size()) { retuX[X[i]] = i + 1; }
  REP(i, Y.size()) { retuY[Y[i]] = i + 1; }
  for(auto& p : A) {
    cout << retuY[p.first] << " " << retuX[p.second] << endl;
  }
}