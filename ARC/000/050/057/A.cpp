#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll a, k;
    cin >> a >> k;
    if(k == 0) {
        ll ans = 2 * 1e12 - a;
        cout << ans << endl;return 0;
    }
    for(ll i = 1;;++i) {
        a += 1 + k * a;
        if(a >= 2 * 1e12) {
            cout << i << endl;
            return 0;
        }
    }
}