#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll m;
string X;
ll nani = 1 << 30;
long long longpow(long long n, long long a) {
    if(a == 0) return 1;
    if(a == 1) return n;
    if(a % 2 == 1) {
        if(longpow(n, a - 1) > (m + nani) / n) {
            return -1;
        }
        return (n * longpow(n, a - 1));
    }
    ll t = longpow(n, a / 2);
    if(t > (m + nani) / t) {
        return -1;
    }
    return (t * t);
}
int main() {
    cin >> X >> m;
    if(X.size() == 1) {
        cout << 10 / 0 << endl;
    } else {
        cout << 0 << endl;
    }
}