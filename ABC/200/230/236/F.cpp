#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct spice {
    ll aji;
    ll cost;
};
int main() {
    int N;
    cin >> N;
    vector<int> c(1 << N);
    vector<spice> s((1 << N)-1);
    REP(i, (1 << N) - 1) {
        cin >> c[i];
        s[i].aji = i + 1, s[i].cost = c[i];
    }
    sort(s.begin(), s.end(), [](spice l, spice r) {
        return l.cost < r.cost;
        });
    set<int> se;
    ll ans = s[0].cost;
    se = { s[0].aji };
    for(int i = 1;i < s.size();++i) {
        //cerr << i << endl;
        if(se.count(0))se.erase(0);
        if(se.count(s[i].aji))continue;
        if(se.size() == (1 << N) - 1)break;
        bool b = 1;
        if(b) {
            ans += s[i].cost;
            se.insert(s[i].aji);
            for(auto num : se) {
                auto nex = num ^ s[i].aji;
                se.insert(nex);
            }
        }
    }
    cout << ans << endl;
}