#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int mem[101010];
int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    mem[N] = N;
    for(int i = 1;i < N;++i) {
        mem[i] = mem[i - 1];
        if(S[i] == '0')mem[i] = i;
    }
    vector<int> ans;
    for(int i = 0;i < N;) {
        int id = min(i + M, N);
        if(mem[id] <= i) {
            cout << -1 << endl;
            return 0;
        }
        ans.emplace_back(mem[id] - i);
        i = mem[id];
    }
    reverse(ans.begin(), ans.end());
    for(auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}