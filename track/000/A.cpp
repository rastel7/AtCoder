#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N, W;
    cin >> N >> W;
    queue<pair<int, int>> que;
    REP(i, N) {
        int a;
        cin >> a;
        que.push({a, i + 1});
    }
    while(!que.empty()) {
        auto [f, id] = que.front();
        que.pop();
        f -= W;
        if(f <= 0) {
            cout << id << "\n";
            continue;
        }
        que.push({f, id});
    }
}