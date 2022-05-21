#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int Q;
    cin >> Q;
    deque<pair<ll, ll>> que;
    vector<ll> anss;
    while(Q--) {
        ll id;
        cin >> id;
        if(id == 1) {
            ll x, c;
            cin >> x >> c;
            que.push_back({x, c});
        } else {
            ll c;
            cin >> c;
            ll ans = 0;
            while(c != 0) {
                auto [num, x] = que.front();
                que.pop_front();
                if(x <= c) {
                    ans += x * num;
                    c -= x;
                } else {
                    ans += c * num;
                    x -= c;
                    c = 0;
                    if(x != 0) {
                        que.push_front({num, x});
                    }
                }
            }
            anss.emplace_back(ans);
        }
    }
    for(auto a : anss) {
        cout << a << endl;
    }
}