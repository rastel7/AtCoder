#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  string s;
  cin >> s;
  int y = s.back() - '0';
  int x = stoi(s.substr(0, s.size() - 2));
  if(0 <= y && y <= 2) {
    cout << x << "-" << endl;
  }
  else if(3 <= y && y <= 6) {
    cout << x << endl;
  }
  else {
    cout << x << "+" << endl;
  }
}