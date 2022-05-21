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
    map<char, int> mp;
    REP(i, s.size())mp[s[i]]++;
    bool b = 0;
    b |= mp['W'] != 0 && mp['E'] == 0;
    b |= mp['E'] != 0 && mp['W'] == 0;
    b |= mp['S'] != 0 && mp['N'] == 0;
    b |= mp['N'] != 0 && mp['S'] == 0;
    if(b) {
        cout << "No" << endl;
    }     else {
        cout << "Yes" << endl;
    }
}