#include <bits/stdc++.h>

#include "atcoder/all"
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct ANS {
  ll id, prev, num;
};
int main() {
  ll N, M, Q;
  cin >> N >> M >> Q;
  vector<ll> A(Q), B(Q), C(Q), D(Q);
  REP(i, Q) {
    cin >> A[i];
    if (A[i] == 1) {
      cin >> B[i] >> C[i] >> D[i];
    } else {
      cin >> B[i] >> C[i];
    }
  }
  vector<ANS> ansA;
  {
    vector<ll> H(N + 1), prev(N + 1, -1);
    atcoder::fenwick_tree<ll> fen(M + 2);

    REP(i, Q) {
      if (A[i] == 2) {
        H[B[i]] = C[i];
        prev[B[i]] = i;
        continue;
      }
      if (A[i] == 1) {
        fen.add(B[i], D[i]);
        fen.add(C[i] + 1, -D[i]);
      }
      if (A[i] == 3) {
        ansA.emplace_back(ANS{i, prev[B[i]], H[B[i]] + fen.sum(0, C[i] + 1)});
      }
    }
  }
  sort(ansA.begin(), ansA.end(), [](ANS l, ANS r) { return l.prev < r.prev; });
  {
    vector<ll> H(N + 1), prev(N + 1);
    atcoder::fenwick_tree<ll> fen(M + 2);
    int j = 0;
    REP(i, Q) {
      while (j < ansA.size()) {
        if (ansA[j].prev == -1) {
          ++j;
        } else {
          break;
        }
      }
      if (A[i] == 2) {
        H[B[i]] = C[i];
        prev[B[i]] = i;
      }
      if (A[i] == 1) {
        fen.add(B[i], D[i]);
        fen.add(C[i] + 1, -D[i]);
      }
      while (j < ansA.size()) {
        if (ansA[j].prev == i) {
          ansA[j].num -= fen.sum(0, C[ansA[j].id] + 1);
          ++j;
        } else {
          break;
        }
      }
    }
  }

  sort(ansA.begin(), ansA.end(), [](ANS l, ANS r) { return l.id < r.id; });
  for (auto a : ansA) {
    cout << a.num << endl;
  }
}