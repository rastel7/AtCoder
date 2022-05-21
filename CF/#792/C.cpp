#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<string> ans;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> A(n, vector<ll>(m));
    REP(i, n) REP(j, m) cin >> A[i][j];
    auto collect = [&]() {
        REP(i, n) {
            ll mx = A[i][0];
            REP(j, m) {
                if(A[i][j] < mx)
                    return false;
                mx = A[i][j];
            }
        }
        return true;
    };
    if(collect()) {
        ans.emplace_back("1 1");
        return;
    }
    int i_t = 0;
    int j_t = 0;
    REP(i, n) {
        bool ok = false;
        REP(j, m) {
            bool f = true;
            if(j != 0) {
                if(A[i][j - 1] > A[i][j]) {
                    i_t = i;
                    j_t = j;
                    ok = 1;
                    break;
                }
            }
            if(j != m - 1) {
                if(A[i][j + 1] < A[i][j]) {
                    i_t = i;
                    j_t = j;
                    ok = 1;
                    break;
                }
            }
        }
        if(ok)
            break;
    }
    ll l, r;
    if(j_t != 0) {
        l = A[i_t][j_t - 1];
    } else {
        l = 1;
    }
    if(j_t != m - 1) {
        r = A[i_t][j_t + 1];
    } else {
        r = 1e9;
    }
    int j_t2 = j_t + 1;
    for(int i = j_t + 1; i < m; ++i) {
        if(l <= A[i_t][i] && A[i_t][i] <= r) {
            j_t2 = i;
        }
    }
    REP(i, n) { swap(A[i][j_t], A[i][j_t2]); }
    if(collect()) {
        ans.emplace_back(to_string(j_t + 1) + " " + to_string(j_t2 + 1));
        return;
    } else {
        ans.emplace_back("-1");
        return;
    }
    // iranai
    /*
    vector<vector<pair<ll, ll>>> CPA(n, vector<pair<ll, ll>>(m));
    REP(i, n) REP(j, m) { CPA[i][j] = {A[i][j], m}; }
    REP(i, n) {
        sort(CPA[i].begin(), CPA[i].end(),
             [&](pair<ll, ll> const &l, pair<ll, ll> const &r) {
                 if(l.first == r.first) {
                     return l.second < r.second;
                 }
                 return l.first < r.first;
             });
    }
    int i1, i2;
    set<ll> s;
    REP(i, n) REP(j, m) {
        if(CPA[i][j].second != j) {
            s.insert(j);
        }
    }
    if(s.size() > 3) {
        ans.emplace_back("-1");
        return;
    }
    {
        auto itr = s.begin();
        i1 = *itr;
        itr++;
        if(itr == s.end()) {
            assert(false);
        }
        i2 = *itr;
    }
    REP(i, n) { swap(A[i][i1], A[i][i2]); }
    if(collect()) {
        ans.emplace_back(to_string(i1 + 1) + " " + to_string(i2 + 1));
        return;
    } else {
        ans.emplace_back("-1");
        return;
    }*/
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    for(auto str : ans) {
        cout << str << "\n";
    }
}