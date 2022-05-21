#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<ll> X(N), Y(N), H(N);
  for(int i = 0;i < N;++i)cin >> X[i] >> Y[i] >> H[i];
  int x, y, h;
  REP(i, N) {
    if(H[i] != 0) {
      x = X[i], y = Y[i], h = H[i];
      break;
    }
  }
  for(int y1 = 0;y1 <= 100;++y1) {
    for(int x1 = 0;x1 <= 100;++x1) {
      int h1 = h + abs(x1 - x) + abs(y1 - y);
      bool ok = true;
      REP(i, N) {
        int h2 = max<int>(h1 - (abs(y1 - Y[i]) + abs(x1 - X[i])), 0);
        if(h2 != H[i])ok = false;
      }
      if(ok) {
        cout << x1 << " " << y1 << " " << h1 << endl;
        return 0;
      }
    }
  }
}