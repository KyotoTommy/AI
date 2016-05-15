//RBMFunc.h
#ifndef _RBMFUNC_H_
#define _RBMFUNC_H_

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;

class RBM{
 private:
  vector< vector<double> > w;
  vector<double> b,c;
  int visibleNum, hiddenNum;
  
 public:
  void updatePara(vector<int> &Vin, double alpha);
  void CDmethod();
  RBM(int i, int j){
    visibleNum = i;
    hiddenNum = j;  
    b.resize(i);
    c.resize(j);
    w.resize(i);
    for(int k=0; k<i; k++)
      w[i].resize(j);
  }
  double randMake();
  vector<int> output(vector<double> prob);
  vector<double> prob_h_v(vector<int> &v_);
  vector<double> prob_v_h(vector<int> &h_);
  vector<int> Rebuild(vector<int> &v_);
};

#endif// _RBMFUNC_H_
