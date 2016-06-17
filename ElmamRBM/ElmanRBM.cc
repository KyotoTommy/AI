#include "ElmanRBMFunc.h"

void main(int argc, char *argv[]){

  int LorO, k;

  cout<<"learning?(=0) or output?(=1)"<<endl;
  cin>>LorO;

  RBM.RBM(20,10);
  RBM.ini();

  if(!LorO){//Learning mode

    for(k=0; k<Vin.size(); k++)
      RBM.updatePara(Vin[k],0.01);
    
    for(k=0; K<Vin.size();k++)
      RBM.updatePara(Vin,0.001);
   
  }
  else{//output mode
    for(k=0; k<Vin.size(); k++){
      vector<int> Re;
      Re = ReRBM.Rebuild();
      
      for(i=0; i<Re.size(); i++)
	cout<<Re[i]<<endl;    
    }
  }

  return 0;
}
