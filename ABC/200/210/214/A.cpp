#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int i;
  cin >> i;
  if(1 <= i && i <= 125) {
    cout << 4 << endl;
  } else if(i <= 211) {
    cout << 6 << endl;
  } else {
    cout << 8 << endl;
  }
}