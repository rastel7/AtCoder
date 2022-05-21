#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    string S;
    cin >> S;
    set<char> s;
    for(auto c : S)
        s.insert(c);
    REP(i, 10) {
        if(!s.count('0' + i)) {
            cout << i << endl;
        }
    }
}