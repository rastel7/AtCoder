#include <atcoder/all>
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    list<int> A(1);
    vector<int> pos(N + 1);
    vector<std::__cxx11::list<int>::iterator> itr_(N + 1);
    itr_[0] = A.begin();
    REP(i, S.size()) {
        if(S[i] == 'L') {
            auto itr = itr_[i];
            A.insert(itr, i + 1);
            itr_[i + 1] = --itr;
        } else {
            auto itr = itr_[i];
            A.insert(++itr, i + 1);
            itr_[i + 1] = --itr;
        }
        }
    for(auto a : A) {
        cout << a << " ";
    }
    cout << endl;
}