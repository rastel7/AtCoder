#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int _data[2500];
int main() {
  REP(i, 2500)_data[i] = 0;
  int n, s, e;
  cin >> n;
  REP(i, n) {

    scanf("%d-%d", &s, &e);
    for(s = s / 5 * 5;s < e;s += 5)_data[s] = 1;
  }
  int o = 0;
  for(int i = 0;i <= 2400;i += 5) {
    if(i % 100 == 60)i += 40;
    if(!o && _data[i]) {
      o = 1;
      printf("%04d-", i);
    } else if(o && !_data[i]) {
      o = 0;
      printf("%04d\n", i);
    }
  }
}