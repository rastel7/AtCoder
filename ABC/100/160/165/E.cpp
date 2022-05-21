#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N, M;
    cin >> N >> M;
    if(M == 1) {
        cout << "1 2" << endl;
        return 0;
    }
    int i1 = 1, i2 = M + 2;
    for(int diff = M; diff >= 1; diff--) {
        cout << i1 << " " << i1 + diff << endl;
        i1++;
        swap(i1, i2);
    }
}