#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  string S;
  cin >> S;
  map<char, int> mp;
  REP(i, S.size())mp[S[i]]++;
  vector<int> A, B;
  for(auto& a : mp) {
    if(a.second % 2 == 1)A.emplace_back(a.second);
    else B.emplace_back(a.second);
  }
  if(A.empty()) {
    cout << S.size() << endl;

  } else {
    cout << (S.size() - A.size()) / (2 * A.size())*2 + 1 << endl;
  }

}