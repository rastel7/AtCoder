#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
map<pair<ll, ll>, ll> mem;
ll f(ll X, ll Y) {
    if(mem.count({ X,Y }))return mem[{X, Y}];
    if(abs(X - Y) <= 1)return mem[{X, Y}] = abs(X - Y);
    if(X > Y)return mem[{X, Y}] = abs(X - Y);
    if(Y % 2 == 0) {
        return mem[{X, Y}] = min(abs(X - Y), f(X, Y / 2) + 1);
    }
    return  mem[{X, Y}] = min({ abs(X - Y), f(X, (Y - 1) / 2) + 2, f(X, (Y + 1) / 2) + 2 });
}
int main() {
    ll X, Y;
    cin >> X >> Y;
    cout << f(X, Y) << endl;
}