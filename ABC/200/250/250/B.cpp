#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    string s;
    REP(i, B * N) {
        if((i / (B)) % 2 == 0) {
            s += '.';
        } else {
            s += "#";
        }
    }
    REP(i, A * N) {
        if((i / A) % 2 == 0) {
            cout << s << endl;
        } else {
            for(auto &a : s) {
                if(a == '#') {
                    cout << ".";
                } else {
                    cout << "#";
                }
            }
            cout << endl;
        }
    }
}