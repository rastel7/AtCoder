#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll n, _n;
    cin >> n;
    _n = n;
    ll depth = 0;
    while(n > 0)depth++, n /= 2;
    n = _n;
    ll x = 1;
    bool t = 0;
    while(x <= n) {
        if(t) {
            if(depth % 2 == 1) {
                x = x * 2;
            } else {
                x = x * 2 + 1;
            }
        } else {
            if(depth % 2 == 0) {
                x = x * 2;
            } else {
                x = x * 2 + 1;
            }
        }
        //cout << x << endl;
        t = !t;
    }
    if(!t) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}