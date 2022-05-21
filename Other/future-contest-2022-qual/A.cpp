#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct Input {
  int N, M, K, R;
  vector<vector<int>> d;
  vector<int> u, v;
  Input() {
    cin >> N >> M >> K >> R;
    d.resize(N);
    REP(i, N) {
      d[i].resize(K);
      REP(j, K)cin >> d[i][j];
    }
    u.resize(R);
    v.resize(R);
    REP(i, R)cin >> u[i] >> v[i], u[i]--, v[i]--;

  }
};
struct State {
  vector<vector<int>> G;
  vector<int> prev_task_num;
  queue<int> usable;
  vector<int> working;//人のリスト,働いていない-1,働いてる:仕事id
  State(Input const& in) {
    G.resize(in.N);
    prev_task_num.resize(in.N);
    REP(i, in.R) {
      G[in.u[i]].emplace_back(in.v[i]);
      prev_task_num[in.v[i]]++;
    }
    REP(i, in.N) {
      if(prev_task_num[i] == 0) {
        usable.push(i);
        prev_task_num[i] = -1;
      }
    }
    working.resize(in.M, -1);
  }
};
struct task_alloc {
  int mem, task;
};
int main() {
  Input in = Input();
  State state(in);
  vector<int> rest_mem;
  while(true) {
    vector<task_alloc> out;
    while(!state.usable.empty()) {
      auto task_id = state.usable.front();state.usable.pop();
      int mem_id = -1;
      REP(i, in.M) {
        if(state.working[i] == -1) {
          mem_id = i;
          break;
        }
      }
      if(mem_id == -1) { state.usable.push(task_id);break; }
      state.working[mem_id] = task_id;
      out.push_back(task_alloc{ mem_id,task_id });
      for(auto const& id : state.G[task_id]) {
        state.prev_task_num[id]--;
        if(state.prev_task_num[id] == 0) {
          state.usable.push(id);
          state.prev_task_num[id] = -1;
        }
      }
    }
    cout << out.size() << flush;
    REP(i, out.size()) {
      cout << " " << out[i].mem + 1 << flush << " " << out[i].task + 1 << flush;
    }
    cout << endl << flush;
    REP(i, rest_mem.size()) {
      state.working[rest_mem[i]] = -1;
    }
    rest_mem.erase(rest_mem.begin(), rest_mem.begin() + rest_mem.size());
    int upd_n;
    cin >> upd_n;
    if(upd_n == -1)return 0;
    REP(i, upd_n) {
      int id;
      cin >> id, id--;
      rest_mem.emplace_back(id);
    }
  }
}