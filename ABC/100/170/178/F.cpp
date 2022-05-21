#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int A[201010], B[201010];
int N;
int can() {
    sort(A, A + N), sort(B, B + N);
    map<int, int> a, b;
    REP(i, N)a[A[i]]++;
    REP(i, N)b[B[i]]++;
    int mx_a, mx_b;
    auto f = [](map<int, int>& mp, int& t) {
        int now = 0;
        for(auto [l, r] : mp) {
            if(mp[now] < r) {
                now = l;
            }
        }
        t = now;
    };
    for(auto [l, r] : a) {
        if(r + b[l] > N) {
            cout << "No" << endl;
            exit(0);
        }
    }
    vector<int> C(N + 1), D(N + 1);
    REP(i, N) {
        C[A[i]]++;
        D[B[i]]++;
    }
    REP(i, N) {
        C[i + 1] += C[i];
        D[i + 1] += D[i];
    }
    int ret = 0;
    REP(i, N) {
        ret = max(ret, C[i + 1] - D[i]);
    }
    return ret;
}
int main() {
    cin >> N;
    REP(i, N)cin >> A[i];
    REP(i, N)cin >> B[i];
    auto offset = can();
    cout<<"Yes\n";
    REP(i, N) {
        cout << B[(i - offset + N) % N] << " ";
    }
    cout << endl;
}