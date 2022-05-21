#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    map<int, int> x, y;
    REP(i, 3) {
        int a, b;
        cin >> a >> b;
        x[a]++, y[b]++;
    }
    int ax, ay;
    for(auto i : x) {
        if(i.second == 1) {
            ax = i.first;
        }
    }
    for(auto i : y) {
        if(i.second == 1) {
            ay = i.first;
        }
    }
    cout << ax << " " << ay << endl;
}