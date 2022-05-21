#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<int> f(int x) {
    vector<int> ret;
    if(x == 1) {
        ret.emplace_back(1);
        return ret;
    }
    vector<int> s = f(x - 1);
    auto cp = s;
    s.emplace_back(x);
    for(auto x : cp) {
        s.emplace_back(x);
    }
    return s;
}
int main() {
    int N;
    cin >> N;
    auto ans = f(N);
    REP(i, ans.size()) {
        cout << ans[i];
        if(i + 1 != ans.size()) {
            cout << " ";
        }
    }
    cout << endl;
}
