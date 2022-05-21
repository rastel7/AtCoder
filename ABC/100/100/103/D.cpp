#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> A(M);
    REP(i, M)cin >> A[i].first >> A[i].second;
    sort(A.begin(), A.end(), [](pair<int, int> l, pair<int, int> r) {return l.second < r.second;});
    int ans = 0, right = -1;
    for(auto [l, r] : A) {
        if(l <= right)continue;
        ans++;
        right = r - 1;
    }
    cout << ans << endl;
}