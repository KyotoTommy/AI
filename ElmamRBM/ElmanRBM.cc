#include "ElmanRBMFunc.h"

void main(int argc, char *argv[]){

  int LorO, k, i;
  vector<string> Vin;

  cout<<"learning?(=0) or output?(=1)"<<endl;
  cin>>LorO;

  ElmanRBM ElmanRBM;

  ElmanRBM.RBM(20,10);
  ElmanRBM.ini();

  if(!LorO){//Learning mode
    ifstream ifs(argv[1]);

    string str;
    while(getline(ifs,str))
      Vin.push_back(str);

    for(k=0; k<Vin.size(); k++){
      ElmanRBM.updatePara(visiblePlus(Vin[k]),0.01);
      ElmanRBM.PastHidden(Vin)
    }

    for(k=0; k<Vin.size();k++){
      ElmanRBM.updatePara(visiblePlus(Vin[k]),0.001);
      ElmanRBM.PastHidden(Vin[k])
      }

  }
  else{//output mode
    for(k=0; k<Vin.size(); k++){

      ifstream ifs(argv[1]);

      string str;
      while(getline(ifs,str))
	Vin.push_back(str);
      
      vector<int> Re;
      Re = ElmanRBM.Rebuild(Vin);
      
      for(i=0; i<Re.size(); i++)
	cout<<Re[i]<<endl;    
    }
  }

  return 0;
}
