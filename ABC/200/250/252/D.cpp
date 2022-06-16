#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0; i < (long long)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> allsum(2 * 2e5);
    REP(i, N) { allsum[A[i]]++; }
    ll ans = 0;
    auto right = allsum;
    vector<ll> left(2 * 2e5);
    ll same = 0;
    REP(i, N) {
        ll num = A[i];
        if(left[num] > 0 && right[num] > 0) {
            same -= left[num] * right[num];
        }
        ll left_cnt = i - left[num];
        ll right_cnt = N - i - right[num];
        if(left_cnt * right_cnt != 0) {
            ans += left_cnt * right_cnt - same;
        }
        left[num]++, right[num]--;
        if(left[num] > 0 && right[num] > 0) {
            same += left[num] * right[num];
        }
    }
    cout << ans << endl;
}