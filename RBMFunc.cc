#include "RBMFunc.h"

void RBM::Efunc(){

    for(int i=0; i<nodeNum[i]; i++){
      for(int j=0; j<nodeNum[j]; j++){

	Efunc += -b[i]*v[i] - c[j]*h[j] -w[i][j]*v[i]*c[j];

      }}}

}

void RBM::updatePara(){
int i,j;

//update  W
for(i=0; i<visibleNum; i++){
	for(j=0; j<hiddenNum; j++)
		w[i][j] += alpha * ( visible[i]*prob_h_v(j,visible[i]) - visible_1[i]*prob_h_v(j,visible_1[i]) );
}

//update b
for(i=0; i<visibleNum; i++)
	b[i]    += alpha * ( visible[i] - visible_1[i] );

//update h
for(j=0; j<hiddenNum; j++)
	c[j]    += alpha * ( prob_h_v(j,visible[i]) - prob_h_v(j,visible_1[i]) );

}

void RBM::CDmethod(){


}

double RBM::sigmoid(double tmp){
return 1 / ( 1 + exp( -tmp ) );
}

double RBM::lambda()
