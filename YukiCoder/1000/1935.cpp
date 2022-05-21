#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long;
using namespace std;
struct S {
    int id = 0;
    ll v1, v2, v3, v4;
    S(ll mv1, ll mv2, ll mv3, ll mv4) : v1(mv1), v2(mv2), v3(mv3), v4(mv4) {}
};
bool operator<(const S &l, const S &r) noexcept {
    if(l.v1 != r.v1)
        return l.v1 < r.v1;
    if(l.v2 != r.v2)
        return l.v2 < r.v2;
    if(l.v3 != r.v3)
        return l.v3 < r.v3;
    if(l.v4 != r.v4)
        return l.v4 < r.v4;
    return l.id < r.id;
}

int main() {
    ll v1, v2, v3, v4, N;
    cin >> v1 >> v2 >> v3 >> v4 >> N;
    map<S, ll> mp;
    set<S> s;
    S now(v1, 0, 0, 0);
    bool skip = false;
    REP(i, N) {
        now.id = i % 4;

        if(i % 4 == 0) {
            { // 1
                ll add = v2 - now.v2;
                add = min(add, now.v1);
                now.v1 -= add, now.v2 += add;
            }
        }
        if(i % 4 == 1) {
            { // 2
                ll add = v3 - now.v3;
                add = min(add, now.v2);
                now.v2 -= add, now.v3 += add;
            }
        }
        if(i % 4 == 2) {
            { // 3
                ll add = v4 - now.v4;
                add = min(add, now.v3);
                now.v3 -= add, now.v4 += add;
            }
        }
        if(i % 4 == 3) {
            { // 1
                ll add = v1 - now.v1;
                add = min(add, now.v4);
                now.v4 -= add, now.v1 += add;
            }
        }
        if(!skip && mp.count(now)) {
            ll dist = i - mp[now];
            ll remain = N - i - 1;
            remain = (remain / dist) * dist;
            if(remain > 0) {
                i += remain;
            }
            skip = true;
        }
        mp[now] = i;
        s.insert(now);
    }
    cerr << mp.size() << endl;
    cout << now.v1 << " " << now.v2 << " " << now.v3 << " " << now.v4 << endl;
    // printf("%lld %lld %lld %lld\n", now.v1, now.v2, now.v3, now.v4);
}