#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll N, L;
vector<ll> A;

int main() {
    cin >> N >> L;
    A.resize(N);
    ll sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>> queue;
    REP(i, N) queue.push(A[i]);
    if(L - sum)
        queue.push(L - sum);
    ll ans = 0;

    while(queue.size() > 1) {
        N--;
        auto f1 = queue.top();
        queue.pop();
        auto f2 = queue.top();
        queue.pop();
        ans += f1 + f2;
        queue.push(f1 + f2);
    }
    cout << ans << endl;
}