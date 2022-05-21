#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N)cin >> A[i];
    vector<ll> beki;
    for(ll i = 2;i < 2e9 + 100;i *= 2) {
        beki.push_back(i);
    }
    map<int, int> mp;
    REP(i, N)mp[A[i]]++;
    sort(A.begin(), A.end(), greater<>());
    int ans = 0;
    for(int i = 0;i < N;++i) {
        if(mp.find(A[i]) == mp.end())continue;
        ll dix = *upper_bound(beki.begin(), beki.end(), A[i]) - A[i];
       // cout << dix << endl;
        if(dix == A[i]) {
            if(mp[dix] >= 2) {
                mp[dix]--;
                ans++;
            }
            mp[dix]--;
            if(mp[dix] == 0)mp.erase(dix);
            continue;
        }
        if(mp.find(dix) != mp.end()) {
            mp[dix]--;
            if(mp[dix] == 0)mp.erase(dix);
            ans++;
        }
        mp[A[i]]--;
        if(mp[A[i]] == 0)mp.erase(A[i]);
    }
    cout << ans << endl;
}