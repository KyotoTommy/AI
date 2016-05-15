#include "RBMFunc.h"

double RBM::randMake(){
 srand((unsigned)time(NULL));
 return (double)rand()/RAND_MAX;
}

void RBM::updatePara(vector<int> &Vin, double alpha){
  int i,j,k;
  vector<int> h_,visible,visible_1;

  for(k=0; k<Vin.size(); k++)
    visible.push_back( Vin[k] );
  
  h_ = output( prob_h_v(Vin) );
  
  visible_1 = output( prob_v_h(h_) );

  //update  W
  for(i=0; i<visibleNum; i++){
    for(j=0; j<hiddenNum; j++){
      vector<double> Probtmp,Probtmp2;
      Probtmp  = prob_h_v(visible);
      Probtmp2 = prob_h_v(visible_1);
      w[i][j] += alpha * ( visible[i]*Probtmp[j] - visible_1[i]*Probtmp2[j] );
    }
  }
  
  //update b
  for(i=0; i<visibleNum; i++)
    b[i] += alpha * ( visible[i] - visible_1[i] );

  //update h
  for(j=0; j<hiddenNum; j++){   
    vector<double> Probtmp,Probtmp2;
    Probtmp  = prob_h_v(visible);
    Probtmp2 = prob_h_v(visible_1);
    c[j] += alpha * ( Probtmp[j] - Probtmp2[j] );
  }
}

vector<int> RBM::output(vector<double> prob){
  vector<int> out;

  for(int i=0; i<prob.size(); i++){
    if( randMake() <=prob[i] )
      out.push_back(1);
    else
      out.push_back(0);
  }
  return out;
}

vector<double> RBM::prob_h_v(vector<int> &v_){
  double lambda;
  int i,j;
  vector<double> prob;

  for(j=0; j<hiddenNum; j++){
    lambda = c[j];
    for(i=0; i<visibleNum; i++)
      lambda += v_[i]*w[i][j];	
    prob.push_back( 1 / ( 1 + exp( -lambda ) ) );
  }
  return prob;
}

vector<double> RBM::prob_v_h(vector<int> &h_){
  double lambda;
  int i,j;
  vector<double> prob;
  
  for(i=0; i<visibleNum; i++){
    lambda = b[i]; 
    for(j=0; j<hiddenNum; j++)
      lambda += h_[j]*w[i][j];
    prob.push_back( 1 / ( 1 + exp( -lambda ) ) );
  }
  
  return prob;
}

vector<int> RBM::Rebuild(vector<int> &v_){
  vector<int> h_;
  h_ = output( prob_h_v(v_) );
 return output( prob_v_h(h_) );
}
