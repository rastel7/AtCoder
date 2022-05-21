#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

vector<int> G[201010];
pair<int, int> vert[201010];
vector<pair<int, int>> oils[201010];
int oiler(int id, int num) {
    vert[id].first = num;
    num++;
    for(auto a : G[id]) {
        num = oiler(a, num);
    }
    vert[id].second = num++;
    //cerr << id << ":<" << vert[id].first << "," << vert[id].second << ">\n";
    return num;
}
void dfs(int id, int depth) {
    oils[depth].emplace_back(vert[id]);
    for(auto a : G[id])dfs(a, depth + 1);
}
int N;
void test() {
    REP(id, N) {
        cerr << id << ":<" << vert[id].first << "," << vert[id].second << ">\n";
    }

    REP(i, N) {
        cerr << "d:" << i << endl;
        for(auto [l, r] : oils[i]) {
            cerr << l << "," << r << "-";
        }
        cerr << endl;
    }
}
int main() {
    cin >> N;
    REP(i, N - 1) {
        int a;
        cin >> a;
        G[a - 1].emplace_back(i + 1);
    }
    REP(i, N) {
        sort(oils[i].begin(), oils[i].end());
    }
    oiler(0, 0);
    dfs(0, 0);
    //test();
    int Q;
    cin >> Q;
    while(Q--) {
        int U, D;
        cin >> U >> D, U--;
        auto o = vert[U];
        auto x = lower_bound(oils[D].begin(), oils[D].end(), make_pair(o.first, -1));
        auto y = upper_bound(oils[D].begin(), oils[D].end(), make_pair(o.second,  -1));
        cout << (y - x) << endl;
    }
}