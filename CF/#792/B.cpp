#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve(vector<tuple<ll, ll, ll>> &ans) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y, z;
    x = 1e9;
    z = c;
    y = z + b;
    ll tmp = x % y;
    x -= tmp;
    x += a;
    ans.emplace_back(make_tuple(x, y, z));
    bool ok = true;
    ok &= x % y == a;
    ok &= y % z == b;
    ok &= z % x == c;
    //cerr << ok << endl;
}
int main() {
    int N;
    cin >> N;
    vector<tuple<ll, ll, ll>> ans;
    while(N--) {
        solve(ans);
    }
    for(auto [x, y, z] : ans) {
        cout << x << " " << y << " " << z << endl;
    }
}