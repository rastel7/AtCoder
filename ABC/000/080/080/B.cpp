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
  int x = 0, cp = N;
  while(cp != 0) {
    x += cp % 10;
    cp /= 10;
  }
  if(N % x == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}