//RBMFunc.h
#ifndef _RBMFUNC_H_
#define _RBMFUNC_H_

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <random>

using namespace std;

class RBM{
 protected:
  vector< vector<double> > w;
  vector<double> b,c;
  int visibleNum, hiddenNum;
  
 public:
  void updatePara(vector<int> &visible, double alpha);
  void CDmethod();
  RBM(int i, int j){
    visibleNum = i;
    hiddenNum = j;  
    b.resize(i);
    c.resize(j);
    w.resize(i);

    for(int k=0; k<i; k++)
      w[k].resize(j);
    
    for(int k=0; k<i; k++)
      b[k] = 0;//b.push_back(0);
   
    for(int k=0; k<j; k++)
      c[k] = 0;//c.push_back(0);
   
    random_device seed_gen;
    default_random_engine engine(seed_gen());

    normal_distribution<> dist(0,0.01);

    for(int k=0; k<i; k++){
      for(int q=0; q<j; q++)
	w[k][q] = dist(engine);
    }

  }
  double randMake();
  vector<int> output(vector<double> prob);
  vector<double> prob_h_v(vector<int> &v_);
  vector<double> prob_v_h(vector<int> &h_);
  vector<int> Rebuild(vector<int> &v_);
};

#endif// _RBMFUNC_H_
