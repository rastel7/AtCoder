#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
string S[4] = {"H", "2B", "3B", "HR"};
int main() {
    map<string, int> mp;
    REP(i, 4) {
        string s;
        cin >> s;
        mp[s]++;
    }
    REP(i, 4) {
        if(mp[S[i]] != 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}