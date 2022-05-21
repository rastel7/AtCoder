#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

struct c {
    string s;
    int l, r;
    void f() {
        l = r = 0;
        int n = 0;
        REP(i, s.size()) {
            if(s[i] == ')') {
                n++;
            } else {
                n--;
            }
            l = max(l, n);
        }
        n = 0;
        REP(i, s.size()) {
            if(s[s.size() - 1 - i] == '(') {
                n++;
            } else {
                n--;
            }
            r = max(r, n);
        }
    }
};
int main() {
    int N;
    cin >> N;
    vector<c> A(N);
    REP(i, N) {
        cin >> A[i].s;
        A[i].f();
    }
    vector<c> B, C;
    REP(i, N) {
        if(A[i].l > A[i].r) {
            C.emplace_back(A[i]);
        } else {
            B.emplace_back(A[i]);
        }
    }
    sort(B.begin(), B.end(), [](c l, c r) {
        return l.l < r.l;
        });
    sort(C.begin(), C.end(), [](c l, c r) {
        return l.r > r.r;
        });
    int x = 0;
    for(auto a : B) {
        for(auto ch : a.s) {
            if(ch == ')') {
                x--;
            } else {
                x++;
            }
            if(x < 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for(auto a : C) {
        for(auto ch : a.s) {
            if(ch == ')') {
                x--;
            } else {
                x++;
            }
            if(x < 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if(x != 0) {
        cout << "No" << endl;
        return 0;
    } else {
        cout << "Yes" << endl;
    }
}