#include "RBMFunc.h"
#include "ElmanRBMFunc.h"

void ElmanRBM::ini(){

  ifstream ifs("ini.dat");

}

void ElmanRBM::PastHidden(vector<int> &v_){
  H2 = H1;
  H3 = H2;

  H1 = RBM::output( prob_h_v(v_) );
}

vector<int> ElmanRBM::visiblePlus(vector<int> &v_){
  int i;
  vector<int> Vin;

  Vin.resize(v_.size());
  Vin = v_;

  if(!H1.size()){
    for(i=0; i<H1.size(); i++)
      Vin.push_back( H1[i] );
  }

  if(!H2.size()){
    for(i=0; i<H2.size(); i++)
      Vin.push_back( H2[i] );
  }

  if(!H3.size()){
    for(i=0; i<H3.size(); i++)
      Vin.push_back( H3[i] );
  }

  return Vin;
}
