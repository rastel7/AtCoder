#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll N;
  cin >> N;
  vector<ll> S(N), T(N);
  REP(i, N)cin >> S[i];
  REP(i, N)cin >> T[i];
  for(int i = 0;i < N;++i) {
    ll id = i, time = T[i];
    while(true) {
      if(time + S[id] < T[(id + 1) % N]) {
        T[(id + 1) % N] = time + S[id];
        time += S[id];
        id = (id + 1) % N;
      } else {
        break;
      }
    }
  }
  REP(i, N) {
    cout << T[i] << endl;
  }
}