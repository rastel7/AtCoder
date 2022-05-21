#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> cnt(N + 1);
    REP(i, 4 * N - 1) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for(int i = 1; i <= N; ++i) {
        if(cnt[i] != 4) {
            cout << i << endl;
            return 0;
        }
    }
}