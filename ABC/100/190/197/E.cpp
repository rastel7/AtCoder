#include<bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
struct Atai {
    ll left_pos, right_pos;
    ll left_num, right_num;
};
Atai calc(ll pos, vector<ll> const& lis) {
    Atai ret;
    ret.left_pos = *lis.begin();
    ret.right_pos = lis.back();
    if(*lis.begin() > pos) {
        ret.left_num = abs(lis.back() - pos) + abs(lis.back() - *lis.begin());
        ret.right_num = abs(lis.back() - pos);
    } else if(lis.back() < pos) {
        ret.left_num = abs(pos - *lis.begin());
        ret.right_num = abs(pos - *lis.begin()) + abs(lis.back() - *lis.begin());
    } else {
        ret.left_num = abs(lis.back() - pos) + abs(lis.back() - *lis.begin());
        ret.right_num = abs(pos - *lis.begin()) + abs(lis.back() - *lis.begin());
    }
    return ret;
}
int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> balls(N + 100);
    REP(i, N) {

        ll x, c;
        cin >> x >> c;
        balls[c].emplace_back(x);
    }
    for(auto& v : balls) {
        sort(v.begin(), v.end());
    }
    Atai tmp = { 0,0,0,0 };
    REP(i, balls.size()) {
        auto v = balls[i];
        if(v.empty())continue;
        Atai left = calc(tmp.left_pos, v);
        Atai right = calc(tmp.right_pos, v);
        Atai next;
        next.left_pos = v[0];
        next.left_num = min(tmp.left_num + left.left_num, tmp.right_num + right.left_num);
        next.right_pos = v[v.size() - 1];
        next.right_num = min(tmp.left_num + left.right_num, tmp.right_num + right.right_num);
        tmp = next;
        cerr << tmp.left_num << "," << tmp.left_pos << " " << tmp.right_num << "," << tmp.right_pos <<"\n";
    }
    cout << min(tmp.left_num + abs(tmp.left_pos), tmp.right_num + abs(tmp.right_pos)) << endl;
}