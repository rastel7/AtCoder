#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    ll ans = 0;
    vector<ll> cnt(26);
    for(ll i = 0;i < S.size();++i) {
        if(i < 2) {
            cnt[S[i] - 'a']++;
            continue;
        }
        if(S[i] == S[i - 1] && S[i - 1] != S[i - 2]) {
            ans += i - cnt[S[i] - 'a'];
            for(auto& x : cnt) {
                x = 0;
            }
            cnt[S[i] - 'a'] += i + 1;
        } else {
            cnt[S[i] - 'a']++;
        }
    }
    cout << ans << endl;
}