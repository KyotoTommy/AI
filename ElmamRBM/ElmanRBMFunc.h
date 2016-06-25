//RBMFunc.h
#ifndef _ELMANRBMFUNC_H_
#define _ELMANRBMFUNC_H_

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <random>
#include <sstream>
#include <string>
#include "RBMFunc.h"


using namespace std;

class ElmanRBM : public RBM{
 private:
  vector<int> H1, H2, H3;
 
 public:
 int docN;

 ElmanRBM(int n, int m) : RBM(n, m){ docN = 0; };
  void ini();
  void PastHidden(vector<int> &v_);
  vector<int> visiblePlus(vector<int> &V_);
  void Learn( vector< vector<string> > &v_, double learningRate);
  void output( vector< vector <string> > &v_);


};

#endif// _ELMANRBMFUNC_H_
