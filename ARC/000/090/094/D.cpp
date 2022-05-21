#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;

int main() {
    int Q;
    cin >> Q;
    while(Q--) {
        ll a, b;
        cin >> a >> b;
        if(a > b)swap(a, b);
        ll K = max<ll>(0,(ll)sqrt(a*b)-100);
        while(K * K <= a * b - 1)K++;
        K--;
        ll ans = 2 * K;
        if(K * (K + 1) >= a * b) {
            ans--;
        }
        if(a <= K) {
            ans--;
        }
        cout << ans << endl;
    }
}