#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
string ds_m = "RDLU";
string ds_q = "rdlu";
enum obj {
    Null,
    Human,  //人
    Cow,    //一回移動
    Pig,    //二回移動
    Rabbit, //三回移動
    Dog,    //人を探す
    Cat,    //ランダムな場所へ
    Wall,
};
struct coordinate {
    int y, x;
};
struct situation {
    array<array<obj, 31>, 31> board;
    array<array<bool, 31>, 31> animal_reach;
    int animal, human;
    vector<int> px, py, pt;
    vector<int> hx, hy;
    vector<bool> center;
    vector<coordinate> target;
    vector<coordinate> walls;
    int tarn;
    situation() {
        cin >> animal;
        px.resize(animal);
        py.resize(animal);
        pt.resize(animal);
        REP(i, animal) { cin >> py[i] >> px[i] >> pt[i]; }
        cin >> human;
        hx.resize(human);
        hy.resize(human);
        center.resize(human, 0);
        REP(i, human) cin >> hy[i] >> hx[i];
        target.resize(human);
        REP(i, human) target[i] = coordinate{ 0, 0 };
        REP(i, 31) REP(j, 31) board[i][j] = Null;
        REP(i, animal) { board[py[i]][px[i]] = obj(pt[i] + 1); }
        REP(i, human) { board[hy[i]][hx[i]] = Human; }
    }
    void test_output() {
        for(int i = 1; i <= 30; ++i) {
            for(int j = 1; j <= 30; ++j) {
                if(animal_reach[i][j]) {
                    //cerr << 1;
                } else {
                    //cerr << 0;
                }
            }
            //cerr << endl;
        }
        REP(i, human) {
            //cerr << i << " : " << target[i].y << "," << target[i].x << endl;
        }
    }
    bool OoR(int y, int x) {
        if(y <= 0 || x <= 0 || y > 30 || x > 30) {
            return true;
        }
        return false;
    }
    bool can_move(coordinate c) {
        if(OoR(c.y, c.x))
            return false;
        for(auto g : walls) {
            if(c.y == g.y && c.x == g.x) {
                return false;
            }
        }
        return true;
    }
    bool can_set_wall(coordinate c) {
        if(OoR(c.y, c.x))
            return false;
        for(auto g : walls) {
            if(c.y == g.y && c.x == g.x) {
                return false;
            }
        }
        REP(i, human) {
            if(hy[i] == c.y && hx[i] == c.x)
                return false;
        }
        REP(i, animal) {
            if(abs(py[i] - c.y) + abs(px[i] - c.x) <= 1)
                return false;
        }
        return true;
    }
    bool wall_test(coordinate c) {
        if(tarn >= 100) {
            return true;
        }
        //そこに壁をおいて嬉しいか？置くならtrue
        int animal_cnt = 0; // 1以下なら壁置かない
        queue<coordinate> bfs;
        bfs.push(c);
        array<array<bool, 31>, 31> moved;
        moved[c.y][c.x] = 1;
        while(!bfs.empty()) {
            auto now = bfs.front();
            bfs.pop();
            if(board[now.y][now.x] != Wall && board[now.y][now.x] >= 2)
                animal_cnt++;
            REP(i, 4) {
                auto next = coordinate{ now.y + dy[i], now.x + dx[i] };
                if(!can_move(next))
                    continue;
                if(moved[next.y][next.x] == 0) {
                    moved[next.y][next.x] = 1;
                    bfs.push(next);
                }
            }
        }
        if(animal_cnt <= 1)
            return false;

        //自分の領域にいなかったら閉じる
        REP(i, 31) REP(j, 31) { moved[i][j] = false; }

        bfs.push(c);
        moved[c.y][c.x] = 1;
        while(!bfs.empty()) {
            auto now = bfs.front();
            bfs.pop();
            if(board[now.y][now.x] != Wall && board[now.y][now.x] >= 2)
                animal_cnt++;
            REP(i, 4) {
                if(i < 2)
                    continue;
                auto next = coordinate{ now.y + dy[i], now.x + dx[i] };
                if(!can_move(next))
                    continue;
                if(moved[next.y][next.x] == 0) {
                    moved[next.y][next.x] = 1;
                    bfs.push(next);
                }
            }
        }
        if(animal_cnt == 0)
            return true;
        return false;
    }
    bool can_fill_x_line(coordinate c) {
        while(true) {
            if(!can_move(c))
                break;
            if(animal_reach[c.y][c.x] == 1)
                return false;
            c.x++;
        }
        c.x--;
        while(true) {
            if(!can_move(c))
                break;
            if(animal_reach[c.y][c.x] == 1)
                return false;
            c.x--;
        }
        return true;
    }
    bool no_bottom_animal(coordinate c) {
        //人の下側に動物がいないかチェック
        //やめ　上よりも少なければ良い
        // string ds_m = "RDLU";
        array<array<bool, 31>, 31> checked;
        for(auto& a : checked) {
            for(auto& b : a)
                b = 0;
        }
        queue<coordinate> bfs;
        int bottom = 0, upper = 0;
        bfs.push(c);
        while(!bfs.empty()) {
            auto now = bfs.front();
            bfs.pop();
            if(board[now.y][now.x] == Wall)
                continue;
            if(board[now.y][now.x] >= 2)
                bottom++;
            REP(i, 3) {
                auto next = coordinate{ now.y + dy[i], now.x + dx[i] };
                if(can_move(next)) {
                    if(checked[next.y][next.x] == 1)
                        continue;
                    checked[next.y][next.x] = 1;
                    bfs.push(next);
                }
            }
        }
        for(auto& a : checked) {
            for(auto& b : a)
                b = 0;
        }
        bfs.push(c);
        while(!bfs.empty()) {
            auto now = bfs.front();
            bfs.pop();
            if(board[now.y][now.x] == Wall)
                continue;
            if(board[now.y][now.x] >= 2)
                upper++;
            REP(i, 4) {
                if(i == 1)
                    continue;
                auto next = coordinate{ now.y + dy[i], now.x + dx[i] };
                if(can_move(next)) {
                    if(checked[next.y][next.x] == 1)
                        continue;
                    checked[next.y][next.x] = 1;
                    bfs.push(next);
                }
            }
        }
        /*
        cerr << "[" << c.y << "," << c.x << "]"
             << "b:" << bottom << ",u:" << upper << endl;
        */
        return bottom + 1 < upper;
    }
    string action(int id) {
        if(target[id].y == -1) {
            return ".";
        }
        auto tar = target[id];
        if(abs(tar.y - hy[id]) + abs(tar.x - hx[id]) == 1) {
            if(tarn < 100)
                return ".";
            if(center[id] == 0) {
                if(tar.y == 30) {
                    auto b = (!wall_test(tar)) ||
                        (!can_set_wall(coordinate{ tar.y, tar.x }));
                    if(b)
                        return ".";
                }
                if(tar.x == 30) {
                    center[id] = 1;
                    target[id].x = 30;
                    target[id].y = 15;
                    return ".";
                }

            } else {
                if((!no_bottom_animal(coordinate{ hy[id], hx[id] })) ||
                    (!can_fill_x_line(tar)))
                    return ".";
            }
            if(can_set_wall(coordinate{ tar.y, tar.x })) {
                string ret;
                if(tar.y < hy[id]) {
                    ret = 'u';
                    board[hy[id] - 1][hx[id]] = Wall;
                    walls.emplace_back(coordinate{ hy[id] - 1, hx[id] });
                } else if(tar.y > hy[id]) {
                    ret = 'd';
                    board[hy[id] + 1][hx[id]] = Wall;
                    walls.emplace_back(coordinate{ hy[id] + 1, hx[id] });
                } else if(tar.x < hx[id]) {
                    ret = 'l';
                    board[hy[id]][hx[id] - 1] = Wall;
                    walls.emplace_back(coordinate{ hy[id], hx[id] - 1 });
                } else if(tar.x > hx[id]) {
                    ret = 'r';
                    board[hy[id]][hx[id] + 1] = Wall;
                    walls.emplace_back(coordinate{ hy[id], hx[id] + 1 });
                }
                if(center[id] == 0) {
                    target[id].y++;
                    if(target[id].y > 30) {
                        target[id].y = 15, target[id].x = target[id].x - 1;
                        center[id] = 1;
                    }
                } else {
                    target[id].x--;
                    if(board[target[id].y][target[id].x] == Wall) {

                        target[id].y = -1;
                    }
                }
                return ret;

            } else {
                return ".";
            }
        } else {
            string act;
            auto x = hx[id], y = hy[id];
            if(tar.y < hy[id]) {
                act = "U";
                y--;
            } else if(tar.y > hy[id]) {
                act = "D";
                y++;
            } else if(tar.x < hx[id]) {
                act = "L";
                x--;
            } else {
                act = "R";
                x++;
            }
            if(can_move(coordinate{ y, x })) {
                board[hy[id]][hx[id]] = Null;
                board[y][x] = Human;
                hy[id] = y, hx[id] = x;
                return act;
            } else {
                x = hx[id], y = hy[id];
                if(tar.x < hx[id]) {
                    act = "L";
                    x--;
                } else if(tar.x > hx[id]) {
                    act = "R";
                    x++;
                } else if(tar.y < hy[id]) {
                    act = "U";
                    y--;
                } else {
                    act = "D";
                    y++;
                }
                if(can_move(coordinate{ y, x })) {
                    board[hy[id]][hx[id]] = Null;
                    board[y][x] = Human;
                    hy[id] = y, hx[id] = x;
                    return act;
                }
                return ".";
            }
        }
    }
    void update_board() {
        // cerr << "update_board->";
        for(auto& g : board) {
            for(auto& e : g) {
                e = Null;
            }
        }
        for(auto wall : walls) {
            board[wall.y][wall.x] = Wall;
        }
        REP(i, animal) { board[py[i]][px[i]] = obj(1 + pt[i]); }
        // cerr << "end" << endl;
    }
    void update_reach() {

        int count_tarn = 1;
        for(int i = 0; i <= 30; ++i)
            for(int j = 0; j <= 30; ++j)
                animal_reach[i][j] = false;
        queue<pair<coordinate, int>> bfs;
        array<array<int, 31>, 31> tmp_vec;
        for(auto& x : tmp_vec) {
            for(auto& b : x)
                b = -1;
        }
        REP(i, animal) {
            auto m = make_pair(coordinate{ py[i], px[i] }, count_tarn);
            if(pt[i] == 2)
                m.second *= 2;
            if(pt[i] == 3)
                m.second *= 3;
            if(pt[i] == 4)
                m.second *= 0;
            bfs.push(m);
        }
        while(!bfs.empty()) {
            auto [c, g] = bfs.front();
            bfs.pop();
            animal_reach[c.y][c.x] = true;
            if(g <= 0)
                continue;
            REP(i, 4) {
                auto next = coordinate{ c.y + dy[i], c.x + dx[i] };
                if(can_move(next)) {
                    if(tmp_vec[next.y][next.x] >= g - 1)
                        continue;
                    tmp_vec[next.y][next.x] = g - 1;
                    bfs.push(make_pair(next, g - 1));
                }
            }
        }
    }
    string solve() {
        // cerr << "solve->";
        if(tarn == 61) {
            REP(i, human) { target[i] = coordinate{ 1, (30 / human) * (i + 1) }; }
            target[human - 1].x = 30;
        }
        update_board();
        update_reach();
        // test_output();

        string ret;
        REP(i, human) {
            ret += action(i);
        }
        // cerr << ret << "<-end" << endl;
        ;
        return ret;
    }
    void update(vector<string> in) {
        map<char, int> mp;
        mp['R'] = 0;
        mp['D'] = 1;
        mp['L'] = 2;
        mp['U'] = 3;
        REP(i, animal) {
            for(auto c : in[i]) {
                if(c == '.')
                    continue;
                board[py[i]][px[i]] = Null;
                py[i] += dy[mp[c]], px[i] += dx[mp[c]];
                board[py[i]][px[i]] = obj(pt[i] + 1);
            }
        }
    }
};

int main() {
    situation input;
    REP(i, 300) {

        input.tarn = i;
        auto out = input.solve();
        // input.test_output();
        if((int)out.size() != input.human) {
            cerr << "出力の数が違います" << endl;
            assert(0);
        }
        cout << out << endl;
        vector<string> in(input.animal);
        REP(i, input.animal) { cin >> in[i]; }
        input.update(in);
    }
}