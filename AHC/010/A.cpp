#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
struct input {
    int s[30][30];
};
struct output {
    int ans[30][30];
};

int to[8][4] = {
    {1, 0, -1, -1}, {3, -1, -1, 0}, {-1, -1, 3, 2}, {-1, 2, 1, -1},
    {1, 0, 3, 2},   {3, 2, 1, 0},   {2, -1, 0, -1}, {-1, 3, -1, 1},
};
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
ll f(const input &in, const output &out, int i, int j, int d) {
    int si = i, sj = j, sd = d;
    int tileid = in.s[i][j];
    if(tileid < 4) {
        tileid = (tileid + out.ans[i][j]) % 4;
    } else if(tileid < 6) {
        tileid = (tileid + out.ans[i][j]) % 2 + 4;
    } else {
        tileid = (tileid + out.ans[i][j]) % 2 + 6;
    }
    ll length = 0;
    while(true) {
        tileid = in.s[i][j];
        if(tileid < 4) {
            tileid = (tileid + out.ans[i][j]) % 4;
        } else if(tileid < 6) {
            tileid = (tileid + out.ans[i][j]) % 2 + 4;
        } else {
            tileid = (tileid + out.ans[i][j]) % 2 + 6;
        }
        int d2 = to[tileid][d];
        if(d2 == -1)
            return 0;
        i += dy[d2];
        j += dx[d2];
        if(i < 0 || i >= 30 || j < 0 || j >= 30)
            return 0;
        d = (d2 + 2) % 4;
        length += 1;
        if(i == si && j == sj && d == sd) {
            return length;
        }
    }
}
ll f(const input &in, const output &out, int i, int j, int d,
     vector<vector<vector<ll>>> &cp) {
    int si = i, sj = j, sd = d;
    int tileid = in.s[i][j];
    if(tileid < 4) {
        tileid = (tileid + out.ans[i][j]) % 4;
    } else if(tileid < 6) {
        tileid = (tileid + out.ans[i][j]) % 2 + 4;
    } else {
        tileid = (tileid + out.ans[i][j]) % 2 + 6;
    }
    int d2 = to[tileid][d];
    if(d2 != -1) {
        if(cp[i][j][d2] != 0) {
            return -1e9;
        }
    }
    if(cp[i][j][d] != 0) {
        return -1e9;
    }
    ll length = 0;
    while(true) {
        tileid = in.s[i][j];
        if(tileid < 4) {
            tileid = (tileid + out.ans[i][j]) % 4;
        } else if(tileid < 6) {
            tileid = (tileid + out.ans[i][j]) % 2 + 4;
        } else {
            tileid = (tileid + out.ans[i][j]) % 2 + 6;
        }
        int d2 = to[tileid][d];
        if(d2 == -1)
            return 0;
        cp[i][j][d] = 1;
        i += dy[d2];
        j += dx[d2];
        if(i < 0 || i >= 30 || j < 0 || j >= 30)
            return 0;
        d = (d2 + 2) % 4;
        length += 1;
        if(i == si && j == sj && d == sd) {
            return length;
        }
    }
}
ll solve_score(const input &in, const output &out) {
    vector<vector<vector<ll>>> cp(30, vector<vector<ll>>(30, vector<ll>(4)));
    ll L1 = 0, L2 = 0, L3 = 0, L4 = 0;
    REP(i, 30) REP(j, 30) {
        REP(k, 4) {
            ll tmp = f(in, out, i, j, k, cp);
            if(tmp > L1) {
                L2 = L1;
                L3 = L2;
                L4 = L3;
                L1 = tmp;
            } else if(tmp > L2) {
                L3 = L2;
                L4 = L3;
                L2 = tmp;
            } else if(tmp > L3) {
                L4 = L3;
                L3 = tmp;
            } else if(tmp > L4) {
                L4 = tmp;
            }
        }
    }
    return L1 * L2;
}
int dfs(const input &in, const output &out, int i, int j, int d,
        tuple<int, int, int> turget) {
    if(turget == make_tuple(-1, -1, -1)) {
        REP(k, 4) {
            if(to[in.s[i][j]][k] == -1)
                continue;
            d = to[in.s[i][j]][k];
            turget = make_tuple(i, j, k);
            break;
        }
    }
    if(turget == make_tuple(i, j, d)) {
        return 0;
    }
}
int main() {
    clock_t start = clock();
    input in;
    output out;
    REP(i, 30) {
        string s;
        cin >> s;
        REP(j, 30) { in.s[i][j] = s[j] - '0'; }
    }
    std::random_device rnd; // 非決定的な乱数生成器
    std::mt19937 mt(rnd()+clock());
    ll prev_score = solve_score(in, out);
    auto prev_out = out;
    int mx_cnt = 30, mn_cnt = 5, max_time = 1900000;
    int loop = 0;
    while(clock() - start < 500000) {
        loop++;
        REP(_k, 30) {
            int i = mt() % 30, j = mt() % 30;
            out.ans[i][j] = mt() % 4;
            REP(k, 4) {
                int ny = i + dy[k], nx = j + dx[k];
                REP(l, 4) {
                    int nny = ny + dy[l], nnx = nx + dx[l];
                    if(nny < 0 || nnx < 0 || nnx >= 30 || nny >= 30)
                        continue;
                    out.ans[nny][nnx] = mt() % 4;
                }
            }
        }
        ll tmp = solve_score(in, out);
        if(prev_score < tmp) {
            prev_score = tmp;
            prev_out = out;
        } else {
            out = prev_out;
        }
    }
    while(clock() - start < 1500000) {
        loop++;
        REP(_k, 20) {
            int i = mt() % 30, j = mt() % 30;
            out.ans[i][j] = mt() % 4;
            REP(k, 4) {
                int ny = i + dy[k], nx = j + dx[k];
                if(ny < 0 || nx < 0 || nx >= 30 || ny >= 30)
                    continue;
                out.ans[ny][nx] = mt() % 4;
            }
        }
        ll tmp = solve_score(in, out);
        if(prev_score < tmp) {
            prev_score = tmp;
            prev_out = out;
        } else {
            out = prev_out;
        }
    }
     while(clock() - start < 1900000) {
        loop++;
        REP(_k, 10) {
            int i = mt() % 30, j = mt() % 30;
            out.ans[i][j] = mt() % 4;
        }
        ll tmp = solve_score(in, out);
        if(prev_score < tmp) {
            prev_score = tmp;
            prev_out = out;
        } else {
            out = prev_out;
        }
    }
    cerr << loop << endl;
    REP(i, 30) REP(j, 30) cout << out.ans[i][j];
    cout << endl;
}