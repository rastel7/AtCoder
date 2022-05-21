#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll N, M;
bool check[(int)1e6 + 100];
void dfs(int id, vector<vector<int>> &S, vector<pair<int, int>> &ans) {
    check[id] = 1;
    for(auto a : S[id]) {
        if(check[a] == 0) {
            ans.emplace_back(make_pair(id, a));
            dfs(a, S, ans);
        }
    }
}
void solveA(vector<vector<int>> &G) {
    REP(i, 1e6) { check[i] = 0; }
    set<pair<int, int>> S;
    vector<set<int>> SA;
    REP(i, N) {
        for(auto a : G[i]) {
            S.insert(make_pair(i, a));
        }
    }
    vector<pair<int, int>> hoge;
    dfs(0, G, hoge);
    vector<int> c(N);
    c[0] = 1;
    queue<int> que;
    que.push(0);
    vector<pair<int, int>> ans;
    while(!que.empty()) {
        auto id = que.front();
        que.pop();
        for(auto a : G[id]) {
            if(c[a] == 1)
                continue;
            ans.emplace_back(make_pair(id, a));
            c[a] = 1;
            que.push(a);
        }
    }
    set<pair<int, int>> anss;
    for(auto a : ans)
        anss.insert(a);
    vector<pair<int, int>> ANS2;
    for(auto [l, r] : S) {
        if(anss.count(make_pair(l, r)) || anss.count(make_pair(r, l)))
            continue;
        ANS2.emplace_back(make_pair(l, r));
    }
    for(auto [l, r] : hoge) {
        cout << l + 1 << " " << r + 1 << "\n";
    }
    cerr << "hoge" << endl;
    for(auto [l, r] : ans) {
        cout << l + 1 << " " << r + 1 << "\n";
    }
}
int main() {
    cin >> N >> M;
    vector<vector<int>> G(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    cerr << "hoge" << endl;
    solveA(G);
}