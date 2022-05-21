#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define PER(i, n) for (int i = (int)(n-1); i>=0; i--)
using ll = long long;
using namespace std;
using P = pair<int, int>;
int a[1000], b[1000], c[1000], d[1000];
struct vert {
  int id, type;//type==0店
};

int score_calc(vector<P> const& loot) {
  P now = loot[0];
  double time = 0;
  for(int i = 1;i < loot.size();++i) {
    time += abs(now.first - loot[i].first) + abs(now.second - loot[i].second);
    now = loot[i];
  }
  return round(1e8 / (time + 1000));
}
vector<P> prev_calc(vector<int> ids) {
  vector<P> mise(50), ie(50);
  REP(i, ids.size()) {
    int id = ids[i];
    mise[i] = P(a[id], b[id]);
    ie[i] = P(c[id], d[id]);
  }
  sort(mise.begin(), mise.end(), [](P l, P r) { return (l.first + l.second) < (r.first + r.second);});
  sort(ie.begin(), ie.end(), [](P l, P r) { return (l.first + l.second) < (r.first + r.second);});
  vector<P> ret = { P(400,400) };
  for(auto x : mise) {
    ret.emplace_back(x);
  }
  for(auto x : ie) {
    ret.emplace_back(x);
  }
  ret.emplace_back(P(400, 400));
  return ret;
}
vector<P> calc(vector<int> ids) {
  vector<P> ret = { P(400,400) };

  //最初に左上
  P mn = P(1e9, 1e9);
  int first_id = -1;

  REP(i, ids.size()) {
    int _id = ids[i];
    if((mn.first + mn.second) > a[_id] + b[_id]) {
      mn = P(a[_id], b[_id]);
      first_id = _id;
    }
  }
  ret.emplace_back(P(a[first_id], b[first_id]));

  vector<vert> kouho;
  for(auto& x : ids) {
    if(x != first_id)kouho.emplace_back(vert{ x,0 });
    else kouho.emplace_back(vert{ x,1 });
  }
  P now = P(a[first_id], b[first_id]);
  while(!kouho.empty()) {
    sort(kouho.begin(), kouho.end(), [&](vert l, vert r) {
      int dis_l, dis_r;
      if(l.type == 0) {
        dis_l = abs(a[l.id] - now.first) + abs(b[l.id] - now.second);
      } else {
        dis_l = abs(c[l.id] - now.first) + abs(d[l.id] - now.second);
      }
      if(r.type == 0) {
        dis_r = abs(a[r.id] - now.first) + abs(b[r.id] - now.second);
      } else {
        dis_r = abs(c[r.id] - now.first) + abs(d[r.id] - now.second);
      }
      return dis_l > dis_r;
      });
    auto next = kouho.back();kouho.pop_back();
    if(next.type == 0) {
      kouho.emplace_back(vert{ next.id,1 });
    }
    if(next.type == 0) {
      ret.emplace_back(P(a[next.id], b[next.id]));
      now = P(a[next.id], b[next.id]);
    } else {
      ret.emplace_back(P(c[next.id], d[next.id]));
      now = P(c[next.id], d[next.id]);
    }
  }
  ret.emplace_back(P(400, 400));
  return ret;
}
int main() {
  std::chrono::system_clock::time_point  start, end; // 型は auto で可
  start = std::chrono::system_clock::now(); // 計測開始時間
  std::random_device seed_gen;

  REP(i, 1000)cin >> a[i] >> b[i] >> c[i] >> d[i];
  vector<int> ids(50);
  REP(i, 50)ids[i] = i;
  vector<P> v = calc(ids);
  end = chrono::system_clock::now();
  while(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() < 200) {
    //cerr << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "\n";
    end = chrono::system_clock::now();
    vector<int> next_id(1000);
    REP(i, 1000) {
      next_id[i] = i;
    }
    std::mt19937 engine(seed_gen());
    shuffle(next_id.begin(), next_id.end(), engine);
    next_id.erase(next_id.begin() + 50, next_id.end());
    assert(next_id.size() == 50);
    auto next_vec = calc(next_id);
    if(score_calc(v) < score_calc(next_vec)) {
      v = next_vec;
      ids = next_id;
    }
  }
  set<int> id_set;
  REP(i, ids.size())id_set.insert(ids[i]);
  id_set.insert(-1);

  std::mt19937 mt;            // メルセンヌ・ツイスタの32ビット版
  std::random_device rnd;     // 非決定的な乱数生成器

  while(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() < 1900) {
    end = chrono::system_clock::now();
    int next_id = -1;
    while(id_set.count(next_id)) {
      mt.seed(rnd());
      next_id = mt() % 1000;
    }
    mt.seed(rnd());
    int prev_id = mt() % 50;
    int prev_num = ids[prev_id];
    ids[prev_id] = next_id;
    auto next_v = calc(ids);
    if(score_calc(next_v) > score_calc(v)) {
      v = next_v;
      id_set.erase(prev_num);
      id_set.insert(next_id);
    } else {
      ids[prev_id] = prev_num;

    }
  }
  cout << ids.size();
  for(auto& id : ids) {
    cout << " " << id + 1;
  }
  cout << endl;
  cout << v.size();
  for(auto& x : v) {
    cout << " " << x.first << " " << x.second;
  }
  cout << endl;
  cerr << "time:" << score_calc(v) << endl;
}