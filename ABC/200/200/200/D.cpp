#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N;
    cin >> N;
    map< ll, vector<ll>> mp;
    vector<ll> A(N);
    REP(i, N)cin >> A[i];
    for(ll i = 1;i < (min(1 << min(N,10), 250));++i) {
        vector<ll> tmp;
        ll sm = 0;
        ll cp = i, id = 0;
        while(cp != 0) {
            if(cp & 1) {
                sm += A[id];
                sm %= 200;
                tmp.emplace_back(id + 1);
            }
            cp /= 2;
            id++;
        }
        if(mp.count(sm % 200)) {
            cout << "Yes" << endl;
            auto v = mp[sm % 200];
            cout << v.size() << " ";
            REP(j, v.size()) {
                cout << v[j];
                if(i != v.size() - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
            v = tmp;
            cout << v.size() << " ";
            REP(j, v.size()) {
                cout << v[j];
                if(i != v.size() - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
            return 0;
        }
        mp[sm % 200] = tmp;
    }
    cout << "No" << endl;
}