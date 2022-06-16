#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
template<class T> struct Matrix {
  vector<vector<T>> mat;
  Matrix(int _n, int _m, T x = 0) :mat(_n, vector<T>(_m, x)) {}
  constexpr size_t Size() const { return mat.size(); }
  inline vector<T>& operator[] (int _i) { return mat[_i]; }
};

template<class T> int GaussJordan(Matrix<T>& A, bool is_extended = false) {
  const T EPS = -1e10;
  int m = A.Size(), n = A[0].size();
  int rank = 0;
  for(int col = 0;col < n;++col) {
    //拡大係数行列ならば最後の行は触らない
    if(is_extended && col == n - 1)break;
    int pivot = -1;
    T ma = EPS;
    for(int row = rank;row < m;++row) {
      if(abs(A[row][col]) > ma) {
        ma = abs(A[row][col]);
        pivot = row;
      }
    }
    if(pivot == -1) {
      continue;
    }
    //行のスワップ 
    swap(A[pivot], A[rank]);
    T fac = A[rank][col];
    for(int col2 = 0;col2 < n;++col2)A[rank][col2] /= fac;
    //ピボットのある列の値がすべて0になるように掃き出す
    for(int row = 0;row < m;++row) {
      if(row != rank && abs(A[row][col]) > EPS) {
        T fac = A[row][col];
        for(int col2 = 0;col2 < n;++col2) {
          A[row][col2] -= A[rank][col2] * fac;
        }
      }
    }
    ++rank;
  }
  return rank;
}
int main() {

}