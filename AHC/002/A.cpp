#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
struct Input {
    int sy, sx;
    vector<vector<int>> T, P;
};
const int MAX_TIME = 1900000;
P move(P now, char dir) {
    // Y,X
    switch(dir) {
    case 'U':
        now.first--;
        break;
    case 'D':
        now.first++;
        break;
    case 'L':
        now.second--;
        break;

    case 'R':
        now.second++;
        break;
    default:
        break;
    }
    return now;
}
bool OoR(P nex) {
    if(nex.first < 0 || nex.second < 0 || 49 < nex.first || 49 < nex.second) {
        return true;
    }
    return false;
}
int calc_score(string const &s, Input const &input) {
    int ret = 0;
    P pos = P(input.sy, input.sx);
    for(auto &c : s) {
        ret += input.P[pos.first][pos.second];
        pos = move(pos, c);
    }
    ret += input.P[pos.first][pos.second];
    return ret;
}
int calc_score(string const &s, Input const &input, bool b) {
    int ret = 0;
    set<int> sets;
    P pos = P(input.sy, input.sx);
    for(auto &c : s) {
        ret += input.P[pos.first][pos.second];
        if(sets.count(input.T[pos.first][pos.second])) {
            return 0;
        }
        sets.insert(input.T[pos.first][pos.second]);

        pos = move(pos, c);
        if(OoR(pos))
            return 0;
    }
    if(OoR(pos))
        return 0;
    if(sets.count(input.T[pos.first][pos.second])) {
        return 0;
    }
    ret += input.P[pos.first][pos.second];
    return ret;
}
void dfs(int y, int x, string &past, set<int> &checked, Input const &input) {
    // シャッフル

    vector<char> v = {'U', 'L', 'R', 'D'};
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);

    for(auto &c : v) {
        auto nex = move(P(y, x), c);
        bool b = 0;
        while(!OoR(nex)) {
            if(!checked.count(input.T[nex.first][nex.second])) {
                b = 1;
                checked.insert(input.T[nex.first][nex.second]);
                past.push_back(c);
                nex = move(P(nex.first, nex.second), c);
            } else {
                break;
            }
        }
        switch(c) {
        case 'U':
            nex.first++;
            break;
        case 'L':
            nex.second++;
            break;
        case 'D':
            nex.first--;
            break;
        case 'R':
            nex.second--;
            break;
        default:
            break;
        }
        if(b) {
            dfs(nex.first, nex.second, past, checked, input);
            return;
        }
    }
    return;
}
string random_walk(Input const input) {
    string ret = "";
    set<int> checked;
    checked.insert(input.T[input.sy][input.sx]);
    dfs(input.sy, input.sx, ret, checked, input);
    return ret;
}
void yama(string &s, Input const &input) {
    random_device rnd;
    int id = rnd() % s.size();
    vector<char> v = {'U', 'L', 'R', 'D'};
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);
    string nex = s;
    if(nex[id] != v[0]) {
        nex[id] = v[0];
    } else {
        nex[id] = v[1];
    }
    if(calc_score(s, input, 1) < calc_score(nex, input, 1)) {
        s = nex;
    }
    return;
}
void dameosi(string &s, Input const &input) {
    P pos = P(input.sy, input.sx);
    set<int> sets;
    sets.insert(input.T[pos.first][pos.second]);
    for(auto &c : s) {
        pos = move(pos, c);
        sets.insert(input.T[pos.first][pos.second]);
    }
    dfs(pos.first, pos.second, s, sets, input);
    return;
}
int main() {
    clock_t start = clock();
    int sx, sy;
    cin >> sy >> sx;
    vector<vector<int>> T(50, vector<int>(50)), P(50, vector<int>(50));
    REP(i, 50) REP(j, 50) { cin >> T[i][j]; }
    REP(i, 50) REP(j, 50) { cin >> P[i][j]; }
    Input input;
    input.sx = sx, input.sy = sy, input.P = P, input.T = T;
    string ans = random_walk(input);
    int score = calc_score(ans, input);
    while((clock() - start) < MAX_TIME / 2) {
        // cout << (clock() - start) << endl;
        string nex = random_walk(input);
        int tmp = calc_score(nex, input);
        if(tmp > score) {
            score = tmp, ans = nex;
        }
    }
    int i = 0;
    // cout << ans << endl;
    while((clock() - start) < MAX_TIME) {
        i++;
        if(i % 30 == 0) {
            dameosi(ans, input);
            // cout << ans.size() << "\n";
        } else {
            yama(ans, input);
        }
        i %= 30;
    }
    dameosi(ans, input);
    cout << ans << endl;
}
