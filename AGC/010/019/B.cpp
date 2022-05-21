#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string A;
    cin >> A;
    map<char, ll> mp;
    for(auto c : A) {
        mp[c]++;
    }
    ll ans = 0;
    for(auto val : mp) {
        ans += val.second * (val.second - 1) / 2;
    }

    ll x = A.size();
    cout << x* (x - 1) / 2 - ans + 1 << endl;
}