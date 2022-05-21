#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll A, B, W;
    cin >> A >> B >> W;
    W *= 1000;
    ll mn = INF, mx = 0;
    for(ll i = 1;i < 1e6 + 100;++i) {
        if(i * A > W)break;
        ll tmp = W / i;
        if(tmp == B && W % i != 0) {
            continue;
        }
        if(A <= tmp && tmp <= B) {
            mn = min(i, mn);
            mx = max(i, mx);
        }
    }
    /*for(ll i = 1;;i++) {
        if(i * A > W) {
            break;
        }
        ll tmp = W - i * A;
        if(A <= tmp && tmp <= B) {
            mn = min(tmp, mn);
            mx = max(tmp, mn);
        }
    }
    for(ll i = 1;;i++) {
        if(i * B > W) {
            break;
        }
        ll tmp = W - i * B;
        if(A <= tmp && tmp <= B) {
            mn = min(i, mn);
            mx = max(i, mn);
        }
    }*/
    if(mn == INF) {
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }
    cout << mn << " " << mx << endl;
}