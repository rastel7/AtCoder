#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;

int main() {
    int H, W, M;
    cin >> H >> W >> M;
    vector<vector<ll>> T(H);
    REP(i, M) {
        int a, b;
        cin >> a >> b, a--, b--;
        T[a].emplace_back(b);
    }
    for(auto& t : T)sort(t.begin(), t.end());
    ll ans = 0;
    REP(i, H) {
        if(T[i].empty()) {
            ans += W;
            continue;
        }
        if(T[i][0] == 0) {
            break;
        }
        ans += T[i][0];
    }
    vector<vector<int>> Yoko(W);
    REP(i, H)REP(j, T[i].size()) {
        Yoko[T[i][j]].emplace_back(i);
    }
    for(auto& t : Yoko)sort(t.begin(), t.end());
    fenwick_tree<int> bit(H);
    auto bset = [&](int i) {
        if(i == H)return;
        if(bit.sum(i, i + 1) == 0) {
            bit.add(i, 1);
        }
    };
    for(int i = 0;i < W;++i) {
        if(i == 0) {
            if(Yoko[0].empty())continue;
            for(int y = Yoko[0][0];y < H;++y) {
                bset(y);
            }
            continue;
        }
        int h;
        if(Yoko[i].empty())h = H;
        else h = Yoko[i][0];
        if(h == 0)break;
        ans += bit.sum(0, h);
        for(auto y : Yoko[i]) {
            bset(y);
        }
    }
    cout << ans << endl;
}