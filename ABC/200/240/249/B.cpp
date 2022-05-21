#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    string S;
    cin >> S;
    map<char, int> mp;
    for(auto c : S)
        mp[c]++;
    bool ok = true;
    for(auto [l, r] : mp) {
        if(r >= 2)
            ok = false;
    }
    bool c = false;
    for(char i = 'a'; i < 'z'; ++i) {
        if(mp.count(i))
            c = true;
    }
    if(!c)
        ok = false;
    c = false;
    for(char i = 'A'; i < 'Z'; ++i) {
        if(mp.count(i))
            c = true;
    }
    if(!c)
        ok = false;
    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}