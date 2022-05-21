#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string S;
    cin >> S;
    vector<int> A(S.size() + 100, 0), Combo(S.size() + 100, 0);
    ll kabu = 5, com = 0, ans = 0, wt = 0;
    auto f = [&](ll dmg) {
        return dmg * (10 + (com / 10));
    };
    REP(i, S.size()) {
        kabu += A[i], com += Combo[i];
        wt--;
        if(wt > 0)continue;
        if(S[i] == '-')continue;
        if(S[i] == 'N') {
            if(kabu < 1)
                continue;
            kabu--;
            A[i + 7]++;
            ans += f(1);
            Combo[i+2]++;
        } else {
            if(kabu < 3)continue;
            kabu -= 3;
            ans += f(5);
            Combo[i + 4]++;
            A[i + 9] += 3;
            wt = 3;
        }
    }
    cout << ans << endl;
}