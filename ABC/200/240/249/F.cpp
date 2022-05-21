#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> A(N);
    REP(i, N) cin >> A[i].first >> A[i].second;
    ll ans = -1e18;
    priority_queue<ll> que;
    ll sum = 0;
    ll mins_que = 0;
    for(ll i = N - 1; i >= -1; i--) {
        if(K == -1) {
            break;
        }
        while((ll)que.size() > K) {
            mins_que -= que.top();
            que.pop();
        }
        if(i == -1) {
            ll tpans = 0 + sum - mins_que;
            ans = max(ans, tpans);
            continue;
        }
        if(A[i].first == 1) {
            ll tpans = sum - mins_que + A[i].second;
            ans = max(tpans, ans);
            K--;
        } else {
            sum += A[i].second;
            if(A[i].second < 0) {
                que.push(A[i].second);
                mins_que += A[i].second;
            }
        }
    }
    cout << ans << endl;
}
