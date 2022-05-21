#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int y, m, d;
  scanf("%d/%d/%d", &y, &m, &d);
  tuple<int, int, int> n = make_tuple(y, m, d), t = make_tuple(2019, 4, 30);
  if(n<= t) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
}