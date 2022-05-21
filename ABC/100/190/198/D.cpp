#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
string S1, S2, S3;
const string UN = "UNSOLVABLE";
int main() {
    cin >> S1 >> S2 >> S3;
    set<char> chars;
    REP(i, S1.size())chars.insert(S1[i]);
    REP(i, S2.size())chars.insert(S2[i]);
    REP(i, S3.size())chars.insert(S3[i]);
    if(chars.size() > 10) {
        cout << UN << endl;
        return 0;
    }
    vector<int> ten(10);
    REP(i, ten.size()) {
        ten[i] = i;
    }
    vector<ll> beki(16);
    beki[0] = 1;
    REP(i, 14) {
        beki[i + 1] = beki[i] * 10;
    }
    reverse(S1.begin(), S1.end());
    reverse(S2.begin(), S2.end());
    reverse(S3.begin(), S3.end());
    do {
        map<char, ll> mp;
        int id = 0;
        for(auto x : chars) {
            mp[x] = ten[id++];
        }
        ll n1, n2, n3;
        auto f = [&](ll& x, string S) {
            x = 0;
            for(int i = S.size() - 1;i >= 0;i--) {
                x += mp[S[i]] * beki[i];
            }
        };
        if(mp[S1.back()] == 0)continue;
        if(mp[S2.back()] == 0)continue;
        if(mp[S3.back()] == 0)continue;
        f(n1, S1);
        f(n2, S2);
        f(n3, S3);
        if(n1 + n2 == n3) {
            cout << n1 << endl << n2 << endl << n3 << endl;
            return 0;
        }
    } while(next_permutation(ten.begin(), ten.end()));
    cout << UN << endl;
}