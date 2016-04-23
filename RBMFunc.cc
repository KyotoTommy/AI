#include "RBMFunc.h"

void RBM::Efunc(){

    for(int i=0; i<nodeNum[i]; i++){
      for(int j=0; j<nodeNum[j]; j++){

	Efunc += -b[i]*v[i] - c[j]*h[j] -w[i][j]*v[i]*c[j];

      }}}

}

void RBM::updatePara(){


}

void RBM::CDmethod(){


}
