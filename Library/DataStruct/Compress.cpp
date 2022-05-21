#include<bits/stdc++.h>
using namespace std;
template <typename T>
struct compress {
    vector<T> origin, vals;
    compress(vector<T> vec) {
        origin = vec;
        vals = vec;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        for(int i = 0;i < (int)origin.size();++i) {
            origin[i] = lower_bound(vals.begin(), vals.end(), origin[i]) - vals.begin();
        }
    }
    T ret_id(T val) {
        //値を入力すると何番目の値かを返す
        return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
    }
    T ret_val(T id){
        //何番目の値化を入力するとidを返す
        return vals[id];
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0;i < n;++i)cin >> A[i];
    compress<int> com(A);
    for(int i = 0; i < n;++i) {
        cout << com.origin[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n;++i) {
        cout<<com.ret_val(com.origin[i])<<" ";
    }
    cout << endl;
}