#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  string S;
  ll K;
  cin >> S >> K;
  sort(S.begin(), S.end());
  do {
    K--;
    if(K == 0) {
      cout << S << endl;
      return 0;
    }
    
  } while(next_permutation(S.begin(), S.end()));

}