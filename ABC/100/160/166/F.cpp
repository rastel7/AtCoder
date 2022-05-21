#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<string> S(N);
    REP(i, N)cin >> S[i];
    map<char, ll> mp;
    mp['A'] = A, mp['B'] = B, mp['C'] = C;
    if(A + B + C == 0) {
        cout << "No" << endl;
        return 0;
    }
    if(A + B + C == 1) {
        vector<char> ans;
        REP(i, N) {
            if(mp[S[i][0]] == 0 && mp[S[i][1]] == 0) {
                cout << "No" << endl;
                return 0;
            }
            if(mp[S[i][0]] == 0) {
                ans.emplace_back(S[i][0]);
                mp[S[i][0]]++;
                mp[S[i][1]]--;
            } else {
                ans.emplace_back(S[i][1]);
                mp[S[i][0]]--;
                mp[S[i][1]]++;
            }
        }
        cout << "Yes" << endl;
        for(auto s : ans) {
            cout << s << "\n";
        }
        return 0;
    }
    vector<char> ans;
    REP(i, N) {
        if(mp[S[i][0]] == 0 && mp[S[i][1]] == 0) {
            cout << "No" << endl;
            return 0;
        }
        if(i != N - 1) {

            if(mp[S[i][0]] == 0) {
                ans.emplace_back(S[i][0]);
                mp[S[i][0]]++;
                mp[S[i][1]]--;
                continue;
            }
            if(mp[S[i][1]] == 0) {
                ans.emplace_back(S[i][1]);
                mp[S[i][1]]++;
                mp[S[i][0]]--;
                continue;
            }
            set<char> s;
            s.insert(S[i + 1][0]);
            s.insert(S[i + 1][1]);
            if(s.count(S[i][0])) {
                ans.emplace_back(S[i][0]);
                mp[S[i][0]]++;
                mp[S[i][1]]--;
                continue;
            } else {
                ans.emplace_back(S[i][1]);
                mp[S[i][1]]++;
                mp[S[i][0]]--;
                continue;
            }
        } else {
            if(mp[S[i][0]] > mp[S[i][1]])
                ans.emplace_back(S[i][1]);
            else
                ans.emplace_back(S[i][0]);
        }
    }
    cout << "Yes" << endl;
    for(auto c : ans) {
        cout << c << "\n";
    }
}