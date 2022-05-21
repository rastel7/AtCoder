#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e10;
const ll MOD = 1000000007;
ll a, N;
set<int> checked;

int main() {
    cin >> a >> N;
    queue<pair<ll, ll>> que;
    que.push(make_pair(1, 0));

    while(!que.empty()) {
        auto [num, cnt] = que.front();

        que.pop();
        if(N == num) {
            cout << cnt << endl;
            return 0;
        }
        if(N * 10 <= num)
            continue;
        que.push(make_pair(num * a, cnt + 1));
        if(num >= 10 && num % 10 != 0) {
            auto s = to_string(num);
            s.insert(s.begin(), s.back());
            s.pop_back();
            ll xl = stol(s);
            if(!checked.count(xl)) {
                checked.insert(xl);
                que.push(make_pair(xl, cnt + 1));
            }
        }
    }
    cout << -1 << endl;
}