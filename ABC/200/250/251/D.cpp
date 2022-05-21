#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll W;
    cin >> W;
    vector<int> ok(W + 3);
    vector<ll> ans;
    /*
    for(int i = 0;; ++i) {
        if((1ll << i) > W)
            break;
        ans.emplace_back(1ll << i);
    }
    cerr << ans.size() << endl;
    int ANSSIZE = ans.size();
    for(int i = 0; i < ANSSIZE; ++i) {
        for(int j = i + 1; j < ANSSIZE; ++j) {
            ans.emplace_back(ans[i] | ans[j]);
        }
    }
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = i + 1; j < ans.size() + 2; ++j) {
            for(int k = j + 1; k < ans.size() + 2; ++k) {
                ll num = 0;
                if(j < ans.size())
                    num += ans[j];
                if(k < ans.size())
                    num += ans[k];
                num += ans[i];
                if(num > W)
                    continue;
                ok[num] = 1;
            }
        }
    }*/
    for(int i = 1; i <= 100; ++i) {
        ans.emplace_back(i);
        ans.emplace_back(i * 100);
        ans.emplace_back(i * 10000);
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i];
        if(i + 1 != ans.size())
            cout << " ";
    }
    cout << "\n";
    return 0;
    cerr << "ans:" << ans.size() << endl;
    ll add = 0;
    for(int i = 1; i <= W; ++i) {
        if(ok[i] == 1) {
            continue;
        }
        add++;

        ok[i] = 1;
        for(int j = 0; j < ans.size() + 1; ++j) {
            for(int k = j + 1; k < ans.size() + 1; ++k) {
                ll num = 0;
                if(j != ans.size())
                    num += ans[j];
                if(k != ans.size())
                    num += ans[k];
                num += i;
                if(num > W)
                    continue;
                ok[num] = 1;
            }
        }
        ans.emplace_back(i);
    }
    cerr << add << endl;
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i];
        if(i + 1 != ans.size())
            cout << " ";
    }
    cout << "\n";
}