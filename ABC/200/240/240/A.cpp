#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if(a > b) {
    swap(a, b);
  }
  if(abs(a - b) == 1 || abs(a - b) == 9) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}