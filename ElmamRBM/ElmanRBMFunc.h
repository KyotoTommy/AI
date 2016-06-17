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


using namespace std;

class ElmanRBM : public RBM{
 private:
  vector<int> H1, H2, H3;

 public:
  void ReadIni();
  void pastHidden();

};

#endif// _ELMANRBMFUNC_H_
