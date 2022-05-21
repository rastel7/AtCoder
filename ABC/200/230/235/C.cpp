#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;

template <typename T> struct compress {
    vector<T> origin, vals;
    compress(vector<T> vec) {
        origin = vec;
        vals = vec;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        for(int i = 0; i < (int)origin.size(); ++i) {
            origin[i] =
                lower_bound(vals.begin(), vals.end(), origin[i]) - vals.begin();
        }
    }
    T ret_id(T val) {
        //値を入力すると何番目の値かを返す
        return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
    }
    T ret_val(T id) {
        //何番目の値化を入力するとidを返す
        return vals[id];
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];
    vector<ll> x(Q), k(Q);
    REP(i, Q) cin >> x[i] >> k[i];
    map<ll, ll> cnt;
    for(auto tm : a)
        cnt[tm]++;
    compress<ll> comp(a);
    vector<vector<ll>> TM(comp.vals.size());
    REP(i, N) {
        int id = comp.ret_id(a[i]);
        TM[id].emplace_back(i);
    }
    REP(i, Q) {
        if(!cnt.count(x[i])) {
            cout << -1 << "\n";
            continue;
        }
        int id = comp.ret_id(x[i]);
        if(TM[id].size() < k[i]) {
            cout << -1 << "\n";
            continue;
        }
        cout << TM[id][k[i] - 1] + 1 << "\n";
    }
}