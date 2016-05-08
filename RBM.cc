#include "RBMFunc.h"

int main(int argc, char *argv[])
{
    vector<int> v0{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> v1{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> v2{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    vector<int> v3{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    
  RBM RBM(20,10);
  
  updatePara(V0,0.01);
  updatePara(V1,0.01);
  updatePara(V2,0.01);
  updatePara(V3,0.01);
  
  return 0;
}
