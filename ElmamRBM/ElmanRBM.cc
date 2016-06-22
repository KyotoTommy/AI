#include "ElmanRBMFunc.h"

int main(int argc, char *argv[]){

  int LorO, k, i;
  vector<string> Vin;

  cout<<"learning?(=0) or output?(=1)"<<endl;
  cin>>LorO;

  ElmanRBM ElmanRBM;
  ElmanRBM.ini();

  if(!LorO){//Learning mode
    ifstream ifs(argv[1]);

    string str;
    while(getline(ifs,str))
      Vin.push_back(str);

    for(k=0; k<Vin.size(); k++){
      vector<int> Vtmp;
      Vtmp = ElmanRBM.visiblePlus(Vin);
      ElmanRBM.updatePara(Vtmp,0.01);
      ElmanRBM.PastHidden(Vin)
    }

    for(k=0; k<Vin.size();k++){
      vector<int> Vtmp;
      Vtmp = ElmanRBM.visiblePlus(Vin);
      ElmanRBM.updatePara(Vtmp,0.001);
      ElmanRBM.PastHidden(Vin)
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
