#include "RBMFunc.h"

int main(int argc, char *argv[])
{
    vector<int> v0{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> v1{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> v2{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    vector<int> v3{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    
  RBM RBM(20,10);
  
  for(int k=0; k<1000; k++){
  RBM.updatePara(v0,0.01);
  RBM.updatePara(v1,0.01);
  RBM.updatePara(v2,0.01);
  RBM.updatePara(v3,0.01);
  }

for(int k=0; k<1000; k++){
  RBM.updatePara(v0,0.001);
  RBM.updatePara(v1,0.001);
  RBM.updatePara(v2,0.001);
  RBM.updatePara(v3,0.001);
  }
 

  vector<int> Re0,Re1,Re2,Re3;
  Re0 = RBM.Rebuild(v0);
  Re1 = RBM.Rebuild(v1);
  Re2 = RBM.Rebuild(v2);
  Re3 = RBM.Rebuild(v3);

  for(int k=0; k<Re0.size(); k++)
    cout<<Re0[k];
  cout<<endl;

  for(int k=0; k<Re1.size(); k++)
    cout<<Re1[k];
  cout<<endl;

  for(int k=0; k<Re2.size(); k++)
    cout<<Re2[k];
  cout<<endl;

  for(int k=0; k<Re3.size(); k++)
    cout<<Re3[k];
  cout<<endl;

  return 0;
}
