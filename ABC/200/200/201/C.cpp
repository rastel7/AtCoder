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
    int ans = 0;
    for(int i = 0; i < 10000; ++i) {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        while(s.size() < 4)
            s.push_back('0');
        reverse(s.begin(), s.end());
        bool ok = true;
        set<char> sets;
        for(auto &c : s)
            sets.insert(c);
        REP(j, 10) {
            if(S[j] == 'o') {
                if(!sets.count(j + '0'))
                    ok = 0;
            } else if(S[j] == 'x') {
                if(sets.count(j + '0'))
                    ok = 0;
            }
        }
        if(ok)
            ans++;
    }
    cout << ans << endl;
}