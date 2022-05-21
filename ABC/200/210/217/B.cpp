#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const string T[] = { "ABC" , "ARC" , "AGC" , "AHC" };
int main() {
  vector<string> S(3);
  REP(i, 3)cin >> S[i];
  REP(i, 4) {
    bool ok = false;
    REP(j, 3) {
      if(S[j] == T[i])ok = true;
    }
    if(!ok) {
      cout << T[i] << endl;
      return 0;
    }
  }
}