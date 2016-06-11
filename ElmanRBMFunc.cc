#include "RBMFunc.h"
#include "ElmanRBMFunc.h"

void ElmanRBM::ReadIni(){

}

void ElmanRBM::PastHidden(vector<int> &v_){
  H2 = H1;
  H3 = H2;

  H1 = RBM::output( prob_h_v(v_) );
}

vector<int> ElmanRBM::visiblePlus(vector<int> &v_){
  int i;
  vector<int> Vin;

  Vin.resize(v.size());
  Vin = v;

  for(i=0; i<H1.size(); i++)
    Vin.push_back( H1[i] );

  for(i=0; i<H2.size(); i++)
    Vin.push_back( H2[i] );

  for(i=0; i<H3.size(); i++)
    Vin.push_back( H3[i] );

  return Vin;
}
