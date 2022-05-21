#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N, M;
vector<int> G[25];
vector<int> tops[25];
int color[25];
int checked[25];
ll dfs(int id, int prev) {
    checked[id] = 1;
    if(color[id] != 0)return 1;
    set<int> kouho = { 1,2,3 };
    for(auto i : tops[id]) {
        kouho.erase(color[i]);
    }
    if(G[id].empty()) {
        return kouho.size();
    }
    ll ret = 0;
    for(auto next : G[id]) {
        if(next == prev)continue;
        tops[next].emplace_back(id);
    }
    for(auto c : kouho) {
        color[id] = c;
        for(auto next : G[id]) {
            if(next == prev)continue;
            checked[next] = 0;
        }
        ll tmp = 1;
        for(auto next : G[id]) {
            if(next == prev)continue;
            if(checked[next] == 0)tmp *= dfs(next, id);
        }
        ret += tmp;
    }
    color[id] = 0;
    for(auto next : G[id]) {
        if(next == prev)continue;
        tops[next].pop_back();
    }
    return ret;
}
int main() {
    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b, a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    ll ans = 1;
    REP(i, N) {
        if(checked[i] == 1)continue;
        ans *= dfs(i, -1);
    }
    cout << ans << endl;
}