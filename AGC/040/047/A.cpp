#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<vector<ll>> cnt(19, vector<ll>(19));
    while(N--) {
        string s, d;
        cin >> s;
        if(count(s.begin(), s.end(), '.') != 0) {
            while(s.back() != '.') {
                d.push_back(s.back());
                s.pop_back();
            }
            s.pop_back();
            reverse(d.begin(), d.end());
        }
        while(d.length() < 9)d.push_back('0');
        ll x = stol(s) * (ll)1e9 + stol(d);
        int t = 0, f = 0;
        while(x % 2 == 0 && t < 18) {
            x /= 2;
            t++;
        }
        while(x % 5 == 0 && f < 18) {
            x /= 5;
            f++;
        }
        cnt[t][f]++;
    }
    ll ans = 0;
    REP(tl, 19) {
        REP(fl, 19) {
            REP(tr, 19) {
                REP(fr, 19) {
                    if(tl + tr < 18 || fl + fr < 18)continue;
                    if(tl == tr && fl == fr) {
                        ans += cnt[tl][fl] * (cnt[tr][fr] - 1);
                    } else {
                        ans += cnt[tl][fl] * cnt[tr][fr];
                    }
                }
            }
        }
    }
    cout << ans / 2 << endl;
}