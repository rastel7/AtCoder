#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    string S;
    cin >> S;
    int a_cnt = 0;
    for(int i = S.size() - 1; i >= 0; i--) {
        if(S[i] == 'a')
            a_cnt++;
        else
            break;
    }
    reverse(S.begin(), S.end());
    int a_cnt_f = 0;
    for(int i = S.size() - 1; i >= 0; i--) {
        if(S[i] == 'a')
            a_cnt_f++;
        else
            break;
    }
    if(a_cnt_f > a_cnt) {
        cout << "No" << endl;
        return 0;
    }
    REP(i, a_cnt - a_cnt_f) S.push_back('a');
    REP(i, S.size()) {
        auto a = S[i];
        auto b = S[S.size() - 1 - i];
        if(a != b) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}