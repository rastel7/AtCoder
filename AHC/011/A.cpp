#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
struct Input {
  int N, T;
  vector<vector<int>> v;
  Input() {
    cin >> N >> T;
    v.resize(N);
    REP(i, N) { v[i].resize(N); }
    vector<string> s(N);
    REP(i, N) cin >> s[i];
    REP(y, N) REP(x, N) {
      int p = s[y][x] - '0';
      if ('a' <= s[y][x] && s[y][x] <= 'f') {
        p = s[y][x] - 'a' + 10;
      }
      v[y][x] = p;
    }
  }
  void DebugOutPut() const {
    REP(y, N) {
      REP(x, N) { cerr << v[y][x] << ","; }
      cerr << "\n";
    }
  }
};
struct myClock {
  clock_t start;
  myClock() { start = clock(); }
  int GetTimeMilis() const {
    clock_t now = clock();
    int t = (now - start) / 1000;
    return t;
  }
};
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
char MoveC[4] = {'D', 'L', 'U', 'R'};
struct Col {
  int y, x;
  Col(int _y, int _x) : y(_y), x(_x) {}
};

struct Data {
  enum Move { Down, Left, Up, Right };
  Input in;
  vector<vector<bool>> fixed;
  string output;
  struct Rndm {
    random_device rnd;
    mt19937 mt;
    Rndm() { mt.seed(rnd()); }
    Move GetRandomMove() {
      int r = mt() % 4;
      return Move(r);
    }
  } rand;

  Data(Input _in) : in(_in), firstinput(_in), tmp_input(_in) {
    fixed.resize(in.N);
    REP(i, in.N) { fixed[i].resize(in.N); }
  }
  Col GetEmpty() const {
    REP(i, in.N) REP(j, in.N) {
      if (in.v[i][j] == 0) {
        return Col{i, j};
      }
    }
    return Col{-1, -1};
  }
  Move GetMove(char const& c) {
    switch (c) {
      case 'D':
        return Move::Down;
        break;
      case 'L':
        return Move::Left;
        break;
      case 'U':
        return Move::Up;
        break;
      case 'R':
        return Move::Right;
        break;
      default:
        break;
    }
    return Move(-1);
  }
  bool HasMoveDir(const int x, Move move) const {
    switch (move) {
      case Down:
        return (x >> 3) & 1;
        break;
      case Up:
        return (x >> 1) & 1;
        break;
      case Left:
        return (x)&1;
        break;
      case Right:
        return (x >> 2) & 1;
        break;
    }
    return false;
  }
  bool HasntCornerFixed() const {
    int ret = 0;
    ret += fixed[0][0];
    ret += fixed[0][in.N - 1];
    ret += fixed[in.N - 1][0];
    ret += fixed[in.N - 1][in.N - 1];
    return ret < 3;
  }
  bool HasntFixedPosition() const {
    REP(i, in.N) REP(j, in.N) {
      if (fixed[i][j] == true) {
        return true;
      }
    }
    return false;
  }
  bool SetStartFixedPosition() {
    bool ret = false;
    //左上
    if (in.v[0][0] != 0) {
      bool b = HasMoveDir(in.v[0][0], Move::Left) ||
               HasMoveDir(in.v[0][0], Move::Up);
      if (!b) {
        fixed[0][0] = 1;
        ret = true;
      }
    }
    //右上
    if (in.v[0][in.N - 1] != 0) {
      int X = in.v[0][in.N - 1];
      bool b = HasMoveDir(X, Move::Right) || HasMoveDir(X, Move::Up);
      if (!b) {
        fixed[0][in.N - 1] = 1;
        ret = true;
      }
    }
    //左下
    if (in.v[in.N - 1][0] != 0) {
      int X = in.v[in.N - 1][0];
      bool b = HasMoveDir(X, Move::Left) || HasMoveDir(X, Move::Down);
      if (!b) {
        fixed[in.N - 1][0] = 1;
        ret = true;
      }
    }
    //右下
    if (in.v[in.N - 1][in.N - 1] != 0) {
      int X = in.v[in.N - 1][in.N - 1];
      bool b = HasMoveDir(X, Move::Right) || HasMoveDir(X, Move::Down);
      if (!b) {
        fixed[in.N - 1][in.N - 1] = 1;
        ret = true;
      }
    }
    return ret;
  }
  Col GetMovePos(Col c, Move move) const {
    c.y += dy[move], c.x += dx[move];
    return c;
  }
  bool OoR(Col const& c) const {
    if (c.y < 0 || c.x < 0 || c.y >= in.N || c.x >= in.N) return true;
    return false;
  }
  bool CanMove(Col c, Move move) const {
    if (fixed[c.y][c.x] == true) return false;
    c.y += dy[move], c.x += dx[move];
    if (OoR(c)) return false;
    if (fixed[c.y][c.x] == true) return false;
    return true;
  }
  void DoMove(Col c, Move move) {
    Col next = GetMovePos(c, move);
    swap(in.v[c.y][c.x], in.v[next.y][next.x]);
    output += MoveC[move];
  }
  void Shuffle(int X) {
    while (X--) {
      Col pos = GetEmpty();
      Move move = rand.GetRandomMove();
      if (CanMove(pos, move)) {
        DoMove(pos, move);
      }
    }
  }
  void AddFixedPosition() {
    vector<Col> cornerposition;
    REP(i, in.N) {
      cornerposition.emplace_back(Col(0, i));
      cornerposition.emplace_back(Col(i, in.N - 1));
    }
    REP(y, in.N) REP(x, in.N) {
      if (fixed[y][x] == 0) continue;
      Col col(y, x);
      REP(m, 4) {
        Move move = Move(m);
        if (CanMove(col, move)) {
          Col next = GetMovePos(col, move);
          if (CanMove(next, (Move)(((int)move + 2) % 4))) {
            fixed[next.y][next.x] = true;
          }
        }
      }
    }
  }
  void EraseUnnecessaryOutput() {
    string next;
    for (int i = 0; i < output.size(); ++i) {
      if (i == output.size() - 1) {
        next += output[i];
        continue;
      }
      if (not(output[i] != output[i + 1] &&
              ((GetMove(output[i]) + GetMove(output[i + 1])) % 2 == 0))) {
        next += output[i];
      } else {
        i++;
      }
    }
    output = next;
  }

  void Update() {
    if ((int)output.size() >= in.T) {
      EraseUnnecessaryOutput();
      return;
    }
    if (HasntCornerFixed()) {
      SetStartFixedPosition();
      Shuffle(100);

      return;
    }
    Shuffle(100);
    AddFixedPosition();
  }

  int GetScore() const {
    int S = 0;
    REP(y, in.N) REP(x, in.N) {
      vector<vector<bool>> checked(in.N, vector<bool>(in.N, false));
      queue<Col> que;
      checked[y][x] = 1;
      que.push(Col(y, x));
      int tmpS = 1;
      while (!que.empty()) {
        auto now = que.front();
        que.pop();
        REP(m, 4) {
          Move move = Move(m);
          Col next = GetMovePos(now, move);
          if (OoR(now) || OoR(next)) {
            continue;
          }
          if (checked[next.y][next.x]) continue;
          if (HasMoveDir(in.v[now.y][now.x], move) &&
              HasMoveDir(in.v[next.y][next.x], Move((m + 2) % 4))) {
            checked[next.y][next.x] = 1;
            tmpS++;
            que.push(next);
          }
        }
      }
      S = max(S, tmpS);
    }
    // cerr << "S:" << S << endl;
    if (S != in.N * in.N - 1) {
      return round(500000.0 * S / (in.N * in.N - 1));
    } else {
      return round(500000.0 * (2 - (double)output.size() / in.T));
    }
  }
  //なまし用変数
  int tmp_score = -1;
  string tmp_ans;
  Input tmp_input;
  Input firstinput;
  vector<int> prev_score;
  //
  void UpdateNamasi() {
    Input input = in;
    string out = output;
    int score = GetScore();
    Shuffle(100);
    EraseUnnecessaryOutput();

    if (score >= GetScore() && output.size() < in.T) {
      in = input;
      output = out;
      score = GetScore();
    }
    prev_score.emplace_back(score);
    while (prev_score.size() > 60) {
      prev_score.erase(prev_score.begin());
    }
    if (prev_score.size() >= 55 && prev_score[0] == score) {
      if (tmp_score < score) {
        tmp_ans = output;
        tmp_score = score;
        tmp_input = in;
      }
      //cerr << "Score" << score << endl;
      output="";
      in = firstinput;
      prev_score.clear();
    }
  }
};
int main() {
  myClock myclock;
  Input input;
  Data q_data(input);

  while (myclock.GetTimeMilis() < 1900) {
    q_data.UpdateNamasi();
  }
  if (q_data.tmp_score != -1) {
    q_data.in = q_data.tmp_input;
    q_data.output = q_data.tmp_ans;
  }
  while ((int)q_data.output.size() > q_data.in.T) {
    q_data.output.pop_back();
  }
  cout << q_data.output << endl;
  cerr << "Score:" << q_data.GetScore() << endl;
}
