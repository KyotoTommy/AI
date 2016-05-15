#include "RBMFunc.h"

int main(int argc, char *argv[])
{
    vector<int> v0{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> v1{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> v2{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    vector<int> v3{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    
  RBM RBM(20,10);
  
  RBM.updatePara(v0,0.01);
  RBM.updatePara(v1,0.01);
  RBM.updatePara(v2,0.01);
  RBM.updatePara(v3,0.01);
  
  RBM.Rebuild(v0);
  RBM.Rebuild(v1);
  RBM.Rebuild(v2);
  RBM.Rebuild(v3);

  return 0;
}
