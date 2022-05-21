#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
/*[0,n]までの素数を配列にして返す
*/
vector<int> eratosthenes(int n) {
  vector<int> ret;
  vector<bool> isPrime(n + 1, 1);
  for(int i = 2;i <= n;++i) {
    if(!isPrime[i])continue;
    ret.emplace_back(i);
    for(int j = 2;i <= n / j;++j) {
      isPrime[j * i] = 0;
    }
  }
  return ret;
}
int main() {
  vector<int> tmp = { 2,3,5 };
  assert(eratosthenes(5) == tmp);
}