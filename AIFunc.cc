#include "AIFunc.h"

void AI::setLayer(int layerNumtmp, int *nodeNumtmp){
  layerNum = layerNumtmp;
  
  for(int i=0; i<nodeNumtmp.size(); i++)
    nodeNum.push_back(nodeNumtmp[i]);

  h.resize(layerNum);

}

void AI::Efunc(){

  for(int r=0; r<layerNum; r++){
    for(int i=0; i<nodeNum[i]; i++){
      for(int j=0; j<nodeNum[j]; j++){

	Efunc = -w[i][j]*h[r-1][i]*h[r][j];

      }}}

}

void AI::preLearning(int layer){


}