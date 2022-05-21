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
int hugo(int x) {
  if(x < 0)return -1;
  if(x > 0)return 1;
  return 0;
}
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
  int type_id; //-1何もなし 0移動オンリー　1壁貼り5横移動だけで壁をはる
  coordinate c;

};
struct states {
  bool crossed;//十字マーク作成済み
  bool sealed;//3/4を封鎖
  states() :crossed(0), sealed(0) {}
};
struct center {
private:
  int x;
  coordinate pos;
public:
  center() :x(0) {}
  center(int a) :x(a) {}
  int get_x()const { return x; }
  void set_x(int a) { x = a; }
  coordinate get_pos()const { return pos; }
  void set_pos(coordinate c) { pos = c; }
};
struct huta_state {
  int y, x, dy, dx;
  bool created_defalt_task = 0;
};
struct input {
  int hum, anim;
  vector<animal> animals;
  vector<coordinate> humans;
  array<array < int, 30>, 30> board;
  array<array < int, 30>, 30> animal_cnt;
  deque<task> tasks;
  vector<task> human_tasks;
  vector<task> late_default_tasks;
  vector<coordinate> walls;
  states state;
  huta_state h_state;
  center cent;
  input() {
    cent.set_x(15);
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
    late_default_tasks.resize(hum);
    human_tasks.resize(hum, { -1,-1,-1 });
    REP(i, hum) {
      cin >> humans[i].y >> humans[i].x, humans[i].y--, humans[i].x--;
    }

    //初期タスク作成
    REP(i, 30) {
      if(i >= 14 && i <= 16)continue;
      tasks.push_back({ 1,i,15 });
    }
    REP(i, 30) {
      if(i >= 14 && i <= 16)continue;
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
    for(auto& a : animal_cnt)a.fill(0);
    for(auto const& h : humans) {
      board[h.y][h.x] |= get_obj_id(obj_type::Human);
    }
    for(auto const& a : animals) {
      board[a.pos.y][a.pos.x] |= get_obj_id(obj_type(a.type));
      animal_cnt[a.pos.y][a.pos.x]++;
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
  char dfs_move(int const id) const {
    if(humans[id].x == human_tasks[id].c.x && humans[id].y == human_tasks[id].c.y) { return '.'; }
    queue<pair<coordinate, string>> que;
    vector<vector<bool>> checked(30, vector<bool>(30, 0));
    que.push({ humans[id],"" });
    checked[humans[id].y][humans[id].x] = 1;
    while(!que.empty()) {
      auto [pos, str] = que.front();
      que.pop();
      if(pos.y == human_tasks[id].c.y && pos.x == human_tasks[id].c.x) {
        if(str.empty())return '.';
        else return str[0];
      }
      REP(i, 4) {
        auto next = pos + mov_d[i];
        if(!can_move(next)) continue;
        if(checked[next.y][next.x] == 1)continue;
        checked[next.y][next.x] = 1;
        que.push({ next,str + mov_s[i] });
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
  char dfs_wall_task(int const id) const {
    auto t = human_tasks[id];
    auto h = humans[id];
    int dist = abs(t.c.y - h.y) + abs(t.c.x - h.x);
    if(dist == 0) {
      return move_any_way(id);
    }
    if(dist > 1) {
      auto ret = dfs_move(id);
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
  char yoko_wall_task(int const id) {
    // "DURL";
    auto t = human_tasks[id];
    auto h = humans[id];
    if(abs(t.c.y - h.y) + abs(t.c.x - h.x) == 1) {
      REP(i, 4) {
        auto c = h + mov_d[i];
        if(c.y == t.c.y && c.x == t.c.x) {
          if(can_set_wall(t.c)) {
            return tolower(mov_s[i]);
          }
        }
      }
    }
    REP(i, 4) {
      if(i <= 1)continue;
      auto next = h + mov_d[i];
      int dist_now = abs(t.c.y - h.y) + abs(t.c.x - h.x);
      int dist_nex = abs(t.c.y - next.y) + abs(t.c.x - next.x);
      if(dist_now > dist_nex && can_move(next)) {
        return mov_s[i];
      }
    }
    return '.';
  }
  char solve_task(int const id) {
    auto t = human_tasks[id];
    if(t.type_id == -1)return '.';
    if(t.type_id == 0) return move_task(id);
    if(t.type_id == 1) return wall_task(id);
    if(t.type_id == 2) {//到着したらその場で停止するタイプの移動タスク
      if(t.c.x == humans[id].x && t.c.y == humans[id].y) {
        return '.';
      }
      return move_task(id);
    }
    if(t.type_id == 3) { //場所に置けなくても動かないタイプのタスク
      if(can_set_wall(human_tasks[id].c)) {
        return wall_task(id);
      } else {
        return '.';
      }
    }
    if(t.type_id == 4) {
      return dfs_wall_task(id);
    }
    if(t.type_id == 5) {
      return yoko_wall_task(id);
    }
    if(t.type_id == 6) {//dfsで移動してそこで停止  
      if(t.c.y == humans[id].y && t.c.x == humans[id].x)return '.';
      return dfs_move(id);
    }
    //タスクIDが壊れてる
    cerr << id << endl;

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
      if(t.type_id == 1 || t.type_id == 3 || t.type_id == 4 || t.type_id == 5) {
        if((board[t.c.y][t.c.x] & get_obj_id(obj_type::Wall)) != 0) {
          human_tasks[i] = { -1,-1,-1 };
        }
      }
      if(t.type_id == 2) {
        if(state.sealed) {
          //human_tasks[i] = { -1,-1,-1 };
          //ここでは消さない，1/4タスクの時のみ消す
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

  bool maked_cross() const {
    for(auto hum : humans) {
      if(hum.y !=
        cent.get_x() && hum.x !=
        cent.get_x())return false;
    }
    for(auto h_t : human_tasks) {
      if(h_t.type_id != 0)return false;
    }
    return true;
  }
  void add_tasks() {//個別に捕まえる用タスク
    int y, x, dy, dx;
    if(cent.get_pos().y == 23)y = 29, dy = -1;
    else y = 0, dy = 1;
    x = cent.get_x();
    if(cent.get_pos().x == 23)dx = 4;
    else dx = -4;
    //taskid=4を最短経路で目指すルートとする

    REP(i, 3) {
      REP(j, 3) {
        int ny = y + i * dy;
        int nx = x + (j + 1) * dx;
        if(OoR({ ny,nx }))assert(0);
        tasks.push_back({ 4,ny,nx });
      }
    }
    h_state.y = y, h_state.x = x, h_state.dx = dx, h_state.dy = dy;
    for(auto t : tasks) {
      cerr << t.c.y << "," << t.c.x << endl;
    }
  }
  void create_huta_task() {
    int dog_cnt = 0;
    REP(i, anim)if(animals[i].type == 4)dog_cnt++;
    dog_cnt = min(3, dog_cnt);//中に人を入れすぎるのはよくない
    REP(i, hum) {
      if(i < dog_cnt) {
        if(i == 0) {
          if(h_state.x == 23) {
            late_default_tasks[i] = { 6,h_state.y,29 };
          } else {
            late_default_tasks[i] = { 6,h_state.y,0 };
          }
        } else  late_default_tasks[i] = { 6,h_state.y,h_state.x + h_state.dx * i + hugo(h_state.dx) * 2 };
        continue;
      }
      int ni = i - dog_cnt;
      int x = h_state.x + h_state.dx * ni + hugo(h_state.dx) * 2;
      x = clamp(x, 0, 29);
      late_default_tasks[i] = { 2,h_state.y + h_state.dy * 4 ,x };
    }
    h_state.created_defalt_task = 1;
    REP(i, hum) {
      //cerr << i << "y:" << late_default_tasks[i].c.y << ",x:" << late_default_tasks[i].c.x << endl;
    }
    auto assert_make = [](int x) {
      if(x < 0 || x >= 30)assert(0);
    };
    assert_make(h_state.x);
    assert_make(h_state.y);
  }
  deque<task> find_confine_task() const {
    deque<task> ret;
    REP(i, 4) {
      int y = h_state.y + h_state.dy * 3;
      int x = h_state.x + h_state.dx * i + hugo(h_state.dx) * 1;
      auto bfs = [&](coordinate c, vector<int> dir) {//指定された方向だけのbfsで動物に何体合うか
        vector<vector<bool>> checked(30, vector<bool>(30, 0));
        checked[c.y][c.x] = 1;
        queue<coordinate> que;
        que.push(c);
        int ret = 0;
        while(!que.empty()) {
          auto pos = que.front();que.pop();
          ret += animal_cnt[pos.y][pos.x];
          for(auto i : dir) {
            auto next = pos + mov_d[i];
            if(can_move(next)) {
              if(!checked[next.y][next.x]) {
                checked[next.y][next.x] = 1;
                que.push(next);
              }
            }
          }
        }
        return ret;
      };
      vector<int> v;//"DURL";
      if(h_state.y == 29) {
        v = { 0,2,3 };
      } else {
        v = { 1,2,3 };
      }
      if(bfs({ y - h_state.dy,x }, v) >= 1) {
        coordinate nex = { y,x + hugo(h_state.dx) * 0 };
        if(can_set_wall(nex))
          ret.emplace_back(task{ 5,nex });
        nex = { y,x + hugo(h_state.dx) * 1 };
        if(can_set_wall(nex))
          ret.emplace_back(task{ 5,nex });
        nex = { y,x + hugo(h_state.dx) * 2 };
        if(can_set_wall(nex))
          ret.emplace_back(task{ 5,nex });
      }
    }
    return ret;
  }
  vector<coordinate> search_sealed_point() {//"DURL";
    vector<pair<int, coordinate>> kouho = { {0,{cent.get_x() - 1,cent.get_x() - 1}}, {0,{cent.get_x() + 1 ,cent.get_x() + 1}}, {0,{cent.get_x() - 1,cent.get_x() + 1}}, {0,{cent.get_x() + 1,cent.get_x() - 1}} };
    auto bfs = [&](coordinate c, vector<int> dir) {//指定された方向だけのbfsで動物に何体合うか
      vector<vector<bool>> checked(30, vector<bool>(30, 0));
      checked[c.y][c.x] = 1;
      queue<coordinate> que;
      que.push(c);
      int ret = 0;
      while(!que.empty()) {
        auto pos = que.front();que.pop();
        ret += animal_cnt[pos.y][pos.x];
        for(auto i : dir) {
          auto next = pos + mov_d[i];
          if(can_move(next)) {
            if(!checked[next.y][next.x]) {
              checked[next.y][next.x] = 1;
              que.push(next);
            }
          }
        }
      }

      return ret;
    };
    kouho[0].first = bfs(kouho[0].second, { 1,3 });
    kouho[1].first = bfs(kouho[1].second, { 0,2 });
    kouho[2].first = bfs(kouho[2].second, { 1,2 });
    kouho[3].first = bfs(kouho[3].second, { 0,3 });
    sort(kouho.begin(), kouho.end(), [](pair<int, coordinate> l, pair<int, coordinate> r) {
      return l.first > r.first;
      });
    vector<coordinate> ret;
    REP(i, 3) {
      ret.emplace_back(kouho[i].second);
    }

    auto p = kouho.back().second;
    if(p.y == cent.get_x() - 1 && p.x == cent.get_x() - 1) {
      cent.set_pos(coordinate{ 7,7 });
    } else if(p.y == cent.get_x() + 1 && p.x == cent.get_x() - 1) {
      cent.set_pos(coordinate{ 23,7 });
    } else if(p.y == cent.get_x() - 1 && p.x == cent.get_x() + 1) {
      cent.set_pos(coordinate{ 7,23 });
    } else {
      cent.set_pos(coordinate{ 23,23 });
    }
    //個別に捕まえるためのタスク追加
    add_tasks();
    return ret;
  }
  string solve() {
    set_board();
    erase_complete_task();
    if(state.sealed && tasks.empty() && (!h_state.created_defalt_task)) {
      bool b = 1;
      REP(i, hum)if(human_tasks[i].type_id == 4)b = 0;
      if(b)
        create_huta_task();
    }
    if(h_state.created_defalt_task) {
      tasks = find_confine_task();
    }
    REP(i, hum) {
      if(human_tasks[i].type_id != -1 && !h_state.created_defalt_task)continue;
      if(h_state.created_defalt_task) {
        if(human_tasks[i].c.y == 29 || human_tasks[i].c.y == 0)continue;
      }
      if(tasks.empty()) {

        if(h_state.created_defalt_task) {
          human_tasks[i] = late_default_tasks[i];
        } else if(state.sealed) {
          human_tasks[i] = { 2,cent.get_pos() };
        } else {
          human_tasks[i] = { 0,cent.get_x(),cent.get_x() };
        }
        continue;
      }
      sort(tasks.begin(), tasks.end(), [&](task l, task r) {
        int a = abs(l.c.x - humans[i].x) + abs(l.c.y - humans[i].y);
        int b = abs(r.c.x - humans[i].x) + abs(r.c.y - humans[i].y);
        return a < b;
        });

      human_tasks[i] = tasks.front();
      tasks.pop_front();
    }
    if(!state.crossed) {
      if(maked_cross()) {
        state.crossed = 1;
        tasks.push_back({ 2,cent.get_x() ,cent.get_x() - 1 });
        tasks.push_back({ 2,cent.get_x(),cent.get_x() + 1 });
        tasks.push_back({ 2,cent.get_x() + 1,cent.get_x() });
        tasks.push_back({ 2,cent.get_x() - 1,cent.get_x() });
      }
    }
    if(state.crossed && !state.sealed) {
      bool b = 1;
      REP(i, hum) {
        if(human_tasks[i].type_id == -1)continue;
        if(human_tasks[i].c.y != humans[i].y || human_tasks[i].c.x != humans[i].x) {
          b = 0;
        }
      }
      if(b) {//準備オッケー
        //封鎖する場所を決める
        auto target = search_sealed_point();
        assert(target.size() == 3);
        for(auto t : target) {
          REP(i, hum) {
            if(human_tasks[i].type_id != 2)continue;
            if(abs(humans[i].x - t.x) + abs(humans[i].y - t.y) == 1) {
              human_tasks[i] = { 3,t.y,t.x };
              break;
            }
          }
        }
        REP(i, hum) {
          if(human_tasks[i].type_id != 3)human_tasks[i] = { 0,cent.get_pos() };
        }
        state.sealed = 1;
      }
    }
    //test_tasks();
    string ret;
    REP(i, hum) {
      auto ans = solve_task(i);
      update_board(i, ans);
      ret += ans;
    }
    return ret;
  }
  void update() {
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
  }
};
int main() {

  input in;
  REP(i, 300) {
    cout << in.solve() << endl;
    //in.test_tasks();
    in.update();
  }
  cerr << "残り タ           スク"<<endl;
  for(auto t : in.tasks) {
    cerr << t.type_id << " " << t.c.y << "," << t.c.x << endl;
  }
}