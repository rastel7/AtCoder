#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int T;
    cin >> T;
    int i = 1;
    while(T--) {
        int N, K;
        cin >> N >> K;
        set<int> s;
        REP(i, N) {
            int a;
            cin >> a;
            s.insert(a);
        }
        double mx = 0;
        for(int i = 1; i <= K; ++i) {
            for(int j = 1; j <= K; ++j) {
                double sum = 0;
                for(int k = 1; k <= K; ++k) {
                    if(s.count(k))
                        continue;
                    int dis_min_en = INF;
                    for(auto &item : s) {
                        dis_min_en = min(dis_min_en, abs(item - k));
                    }
                    int dis_min_me = min(abs(k - i), abs(k - j));
                    if(dis_min_me < dis_min_en) {
                        sum++;
                    }
                }
                mx = max(mx, sum);
            }
        }
        printf("Case #%d: %0.8f\n", i++, mx / (double)K);
    }
}