#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    REP(i, n)cin >> A[i];
    deque<int> que;
    REP(i, n) {
        if(i % 2 == 0) {
            que.push_back(A[i]);
        } else {
            que.push_front(A[i]);
        }
    }
    vector<int> Ans(0);
    while(!que.empty()) {
        Ans.push_back(que.front());
        que.pop_front();
    }

    if(n % 2 == 1) {
        reverse(Ans.begin(), Ans.end());
    }
    REP(i, n) {
        if(i != 0) {
            cout << " " << Ans[i];
        } else {
            cout << Ans[i];
        }
    }
    cout << endl;
}