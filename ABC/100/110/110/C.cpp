#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string S, T;
    cin >> S >> T;
    map<char, char> mp, mp2;
    REP(i, S.size()) {
        char s = S[i], t = T[i];
        if(mp.count(s)) if(mp[s] != t) {
            cout << "No" << endl;
            return 0;
        }
        if(mp2.count(t))if(mp2[t] != s) {
            cout << "No" << endl;
            return 0;
        }
        mp[s] = t, mp2[t] = s;
    }
    cout << "Yes" << endl;
}