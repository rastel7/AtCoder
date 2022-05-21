#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
random_device seed_gen;
mt19937 engine(seed_gen());
struct coordinate {
  int y, x;
  coordinate operator+(coordinate& r) {
    return coordinate{ y + r.y, x + r.x };
  }
  coordinate operator+=(coordinate& r) {
    return coordinate{ y + r.y, x + r.x };
  }
};
coordinate mov_d[4] = { {1,0},{-1,0},{0,1},{0,-1} };
string mov_s = "DURL";
struct animal {
  coordinate pos;
  int type;
};
enum obj_type {
  Null, Human, Cow, Pig, Rabbit, Dog, Cat, Wall
};
int get_obj_id(obj_type obj) {
  return (1 << obj);
}
struct task {
  int type_id; //-1何もなし 0移動オンリー　1壁貼り
  coordinate c;

};
struct input {
  int hum, anim;
  vector<animal> animals;
  vector<coordinate> humans;
  array<array < int, 30>, 30> board;
  deque<task> tasks;
  vector<task> human_tasks;
  vector<coordinate> walls;
  input() {
    cin >> anim;
    animals.resize(anim);
    REP(i, anim) {
      int y, x, t;
      cin >> y >> x >> t, y--, x--, t++;
      animals[i].pos.y = y,
        animals[i].pos.x = x,
        animals[i].type = t;
    }
    cin >> hum;
    humans.resize(hum);
    human_tasks.resize(hum, { -1,-1,-1 });
    REP(i, hum) {
      cin >> humans[i].y >> humans[i].x, humans[i].y--, humans[i].x--;
    }

    //初期タスク作成
    REP(i, 30) {
      if(i >= 14 && i <= 16)continue;
      tasks.push_back({ 1,i,14 });
    }
    REP(i, 30) {
      if(i >= 13 && i <= 15)continue;
      tasks.push_back({ 1,15,i });
    }
  }
  void test_tasks()const {
    REP(i, hum) {
      cerr << i << "{id:" << human_tasks[i].type_id << ",y:" << human_tasks[i].c.y << ",x:" << human_tasks[i].c.x << "}" << endl;
      //cerr << i << "{number:" << i << ",y:" << humans[i].y << ",x:" << humans[i].x << "}" << endl;
    }
    for(auto w : walls) {
      //cerr << w.y << "," << w.x << endl;
    }
  }
  bool OoR(coordinate c) const {
    if(c.x < 0 || c.y < 0 || c.x >= 30 || c.y >= 30)return true;
    return false;
  }
  bool can_move(coordinate c) const {
    if(OoR(c))return false;
    if((board[c.y][c.x] & get_obj_id(obj_type::Wall)) == 0) {
      return true;
    }
    return false;
  }
  bool can_set_wall(coordinate c) const {
    if(OoR(c))return false;
    for(auto& a : animals) {
      if(abs(a.pos.y - c.y) + abs(a.pos.x - c.x) <= 1)return false;
    }
    for(auto& h : humans)  if(h.y == c.y && h.x == c.x)return false;
    for(auto& h : walls)  if(abs(h.y - c.y) + abs(h.x - c.x) <= 0)return false;
    if((board[c.y][c.x] & get_obj_id(obj_type::Human)) != 0) return false;
    return true;
  }
  void set_board() {

    for(auto& a : board)a.fill(0);
    for(auto const& h : humans) {
      board[h.y][h.x] |= get_obj_id(obj_type::Human);
    }
    for(auto const& a : animals) {
      board[a.pos.y][a.pos.x] |= get_obj_id(obj_type(a.type));
    }
    for(auto const& w : walls) {
      board[w.y][w.x] |= get_obj_id(obj_type::Wall);
    }

  };
  char move_task(int const id) const {
    vector<pair<int, char>> move_id;
    auto t = human_tasks[id];
    auto h = humans[id];
    if(t.c.x == h.x && t.c.y == h.y)return '.';
    REP(i, 4) {
      coordinate nex = h + mov_d[i];
      if(!can_move(nex))continue;
      int dist_now = abs(t.c.y - h.y) + abs(t.c.x - h.x);
      int dist_next = abs(t.c.y - nex.y) + abs(t.c.x - nex.x);
      if(dist_next < dist_now || dist_now == 0) {
        move_id.emplace_back(make_pair(i, mov_s[i]));
      }
    }
    if(move_id.empty())  return move_any_way(id);
    shuffle(move_id.begin(), move_id.end(), engine);
    for(auto [i, ret] : move_id) {
      return ret;
    }
    return move_any_way(id);
  }
  char move_any_way(int const id)  const {
    vector<int> mov = { 0,1,2,3 };
    shuffle(mov.begin(), mov.end(), engine);
    REP(i, 4) {
      auto movs = mov[i];
      auto next = coordinate{ humans[id].y + mov_d[movs].y,humans[id].x + mov_d[movs].x };
      if(can_move(next)) {
        return mov_s[movs];
      }
    }
    return '.';
  }
  char wall_task(int const id)const {
    auto t = human_tasks[id];
    auto h = humans[id];
    int dist = abs(t.c.y - h.y) + abs(t.c.x - h.x);
    if(dist == 0) {
      return move_any_way(id);
    }
    if(dist > 1) {
      auto ret = move_task(id);
      if(ret == '.')  return move_any_way(id);
      else return ret;
    }
    REP(i, 4) {
      auto c = h + mov_d[i];
      if(c.y == t.c.y && c.x == t.c.x) {
        if(can_set_wall(t.c)) {
          return tolower(mov_s[i]);
        }
      }
    }
    return move_any_way(id);
  }
  char solve_task(int const id) {
    auto t = human_tasks[id];
    if(t.type_id == -1)return '.';
    if(t.type_id == 0) return move_task(id);
    if(t.type_id == 1) return wall_task(id);
    //タスクIDが壊れてる
    cerr << id << endl;
    assert(0);
    return '.';
  }
  void erase_complete_task() {//終了済みタスクを削除
    REP(i, hum) {
      auto h = humans[i];
      auto t = human_tasks[i];
      if(t.type_id == -1)continue;
      if(t.type_id == 0) {
        if(h.y == t.c.y && h.x == t.c.x) {
          human_tasks[i] = { -1,-1,-1 };
        }
      }
      if(t.type_id == 1) {
        if((board[t.c.y][t.c.x] & get_obj_id(obj_type::Wall)) != 0) {
          human_tasks[i] = { -1,-1,-1 };
        }
      }
    }
  }
  void update_board(const int id, const char c) {
    // "DURL";
    coordinate pos;
    switch(c) {
    case '.':
      break;
    case 'D':
      humans[id] = humans[id] + mov_d[0];
      break;
    case 'U':
      humans[id] = humans[id] + mov_d[1];
      break;
    case 'R':
      humans[id] = humans[id] + mov_d[2];
      break;
    case 'L':
      humans[id] = humans[id] + mov_d[3];
      break;
    case 'd':
      pos = humans[id] + mov_d[0];
      walls.emplace_back(pos);
      board[pos.y][pos.x] = get_obj_id(obj_type::Wall);
      break;
    case 'u':
      pos = humans[id] + mov_d[1];
      walls.emplace_back(pos);
      board[pos.y][pos.x] = get_obj_id(obj_type::Wall);
      break;
    case 'r':
      pos = humans[id] + mov_d[2];
      walls.emplace_back(pos);
      board[pos.y][pos.x] = get_obj_id(obj_type::Wall);
      break;
    case 'l':
      pos = humans[id] + mov_d[3];
      walls.emplace_back(pos);
      board[pos.y][pos.x] = get_obj_id(obj_type::Wall);
      break;
    default:
      break;
    }
  }
  string solve() {
    cerr << "solve->";
    set_board();
    erase_complete_task();
    REP(i, hum) {
      if(human_tasks[i].type_id != -1)continue;
      if(tasks.empty()) {
        human_tasks[i] = { 0,14,14 };
        continue;
      }
      sort(tasks.begin(), tasks.end(), [&](task l, task r) {
        int a = abs(l.c.x - human_tasks[i].c.x) + abs(l.c.y - human_tasks[i].c.y);
        int b = abs(r.c.x - human_tasks[i].c.x) + abs(r.c.y - human_tasks[i].c.y);
        return a < b;
        });
      human_tasks[i] = tasks.front();
      tasks.pop_front();
    }
    test_tasks();
    string ret;
    REP(i, hum) {
      auto ans = solve_task(i);
      update_board(i, ans);
      ret += ans; //タスク実行がおかしい
    }
    cerr << "end" << endl;
    return ret;
  }
  void update() {//重い気がする "DURL";
    cerr << "update->";
    vector<string> str(anim);
    REP(i, anim) { cin >> str[i]; }
    map<char, int> mp;
    mp['D'] = 0, mp['U'] = 1, mp['R'] = 2, mp['L'] = 3;
    REP(i, anim) {
      for(auto const& c : str[i]) {
        if(c == '.')continue;
        animals[i].pos = animals[i].pos + mov_d[mp[c]];
      }
    }
    cerr << "end" << endl;
  }
};
int main() {

  input in;
  REP(i, 300) {

    cout << in.solve() << endl;

    in.update();
  }
}