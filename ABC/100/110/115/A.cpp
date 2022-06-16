#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int D;
  cin >> D;
  D -= 25;
  cout << "Christmas";
  while(D < 0) {
    D++;
    cout << " Eve";
  }
  cout << endl;
}