#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K, A;
  cin >> N >> K >> A, A--;
  K--;
  while(K--) {
    A = (A + 1) % N;

  }
  cout << A + 1 << endl;
}