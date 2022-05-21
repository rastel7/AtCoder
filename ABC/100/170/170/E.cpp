#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, Q;
  cin >> N >> Q;
  vector<map<int, int>> Yotien((int)2e5 + 100);
  vector<int> enji_pos(N), enji_score(N);
  REP(i, N) {
    int a, b;
    cin >> a >> b, b--;
    Yotien[b][a]++;
    enji_pos[i] = b;
    enji_score[i] = a;
  }
  map<int, int> Daihyo;
  for(auto X : Yotien) {
    if(X.empty())continue;
    auto tmp = *(X.rbegin());
    Daihyo[tmp.first]++;
  }
  while(Q--) {
    int a, b;
    cin >> a >> b, b--, a--;
    //代表集合からscore_xを消す｡
    auto erase_score = [&](int score) {
      if(Daihyo[score] == 1) {
        Daihyo.erase(score);
      } else {
        Daihyo[score]--;
      }
    };
    //代表集合にscore_xをたす｡
    auto add_score = [&](int score) {
      Daihyo[score]++;
    };
    //aを今の幼稚園から抜く
    auto erase_enji = [&](int score, int yotien_id) {
      auto max_here = *(Yotien[yotien_id].rbegin());
      bool need_add = 0;
      if(max_here.first == score && max_here.second == 1) {
        erase_score(score);
        need_add = 1;
      }
      if(Yotien[yotien_id][score] != 1) {
        Yotien[yotien_id][score]--;
      } else {
        Yotien[yotien_id].erase(score);//いなくなったときは消す｡
      }
      if(need_add) {
        if(!Yotien[yotien_id].empty()) {
          auto max_here = *(Yotien[yotien_id].rbegin());
          add_score(max_here.first);
        }
      }
    };

    //aを幼稚園bに入れる
    auto add_yotien = [&](int score, int yotien_id) {
      if(!Yotien[yotien_id].empty()) {
        if(score > (*(Yotien[yotien_id].rbegin())).first) {
          erase_score((*(Yotien[yotien_id].rbegin())).first);
        }
      }
      Yotien[yotien_id][score]++;
      auto max_here = *Yotien[yotien_id].rbegin();
      if(max_here.first == score && max_here.second == 1) {
        add_score(score);
      }
    };
    erase_enji(enji_score[a], enji_pos[a]);
    enji_pos[a] = b;
    add_yotien(enji_score[a], enji_pos[a]);
    auto sc = *(Daihyo.begin());
    cout << sc.first << endl;
  }
}