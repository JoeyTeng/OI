/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: new_elements_part_2.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 18-May-2019
 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<double>> Matrix;
double Z;
set<int> P;
size_t cn, bn;

bool Pivot(pair<size_t, size_t> &p) //返回0表示所有的非轴元素都小于0
{
  int x = 0, y = 0;
  double cmax = -INT_MAX;
  vector<double> C = Matrix[0];
  vector<double> B;

  for (size_t i = 0; i < bn; i++) {
    B.push_back(Matrix[i][cn - 1]);
  }

  for (size_t i = 0; i < C.size(); i++) //在非轴元素中找最大的c
  {
    if (cmax < C[i] && P.find(i) == P.end()) {
      cmax = C[i];
      y = i;
    }
  }
  if (cmax < 0) {
    return 0;
  }

  double bmin = INT_MAX;
  for (size_t i = 1; i < bn; i++) {
    double tmp = B[i] / Matrix[i][y];
    if (Matrix[i][y] != 0 && bmin > tmp) {
      bmin = tmp;
      x = i;
    }
  }

  p = make_pair(x, y);

  for (set<int>::iterator it = P.begin(); it != P.end(); it++) {
    if (Matrix[x][*it] != 0) {
      // cout<<"erase "<<*it<<endl;
      P.erase(*it);
      break;
    }
  }
  P.insert(y);
  // cout<<"add "<<y<<endl;
  return true;
}

void pnt() {
  for (size_t i = 0; i < Matrix.size(); i++) {
    for (size_t j = 0; j < Matrix[0].size(); j++) {
      cout << Matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "result z:" << -Matrix[0][cn - 1] << endl;
}

void Gaussian(pair<size_t, size_t> p) //行变换
{
  size_t x = p.first;
  size_t y = p.second;
  double norm = Matrix[x][y];
  for (size_t i = 0; i < cn; i++) //主行归一化
  {
    Matrix[x][i] /= norm;
  }
  for (size_t i = 0; i < bn && i != x; i++) {
    if (Matrix[i][y] != 0) {
      double tmpnorm = Matrix[i][y];
      for (size_t j = 0; j < cn; j++) {
        Matrix[i][j] = Matrix[i][j] - tmpnorm * Matrix[x][j];
      }
    }
  }
}

void solve() {
  pair<size_t, size_t> t;
  while (1) {

    pnt();
    if (Pivot(t) == 0) {
      return;
    }
    cout << t.first << " " << t.second << endl;
    for (set<int>::iterator it = P.begin(); it != P.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
    Gaussian(t);
  }
}

int main(int argc, char *argv[]) {
  // ifstream fin;
  // fin.open("./test");
  cin >> cn >> bn;
  for (size_t i = 0; i < bn; i++) {
    vector<double> vectmp;
    for (size_t j = 0; j < cn; j++) {
      double tmp = 0;
      cin >> tmp;
      vectmp.push_back(tmp);
    }
    Matrix.push_back(vectmp);
  }

  for (size_t i = 0; i < bn - 1; i++) {
    P.insert(cn - i - 2);
  }
  solve();
}
