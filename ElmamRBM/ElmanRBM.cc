#include "ElmanRBMFunc.h"

int main(int argc, char *argv[]){

  int LorO, k, i;
  int l = 0; 
  vector< vector<string> > Vin;

  cout<<"learning?(=0) or output?(=1)"<<endl;
  cin>>LorO;

  ElmanRBM ElmanRBM(20,10);
  ElmanRBM.ini();

  if(!LorO){//Learning mode
    ifstream ifs(argv[1]);

    Vin.resize(20);

    //input date
    string str;
    while(getline(ifs,str)){
      string tmp;
      istringstream stream(str);
      while(getline(stream,tmp,',')){
	Vin[l].push_back(tmp); 
	ElmanRBM.docN++;
      }
      l++;
    }

      //learing 
    ElmanRBM.Learn(Vin, 0.01);
      ElmanRBM.Learn(Vin, 0.001);

  }
  else{//output mode

      string str;
      ifstream ifs(argv[1]);

     while(getline(ifs,str)){
      string tmp;
      istringstream stream(str);
      while(getline(stream,tmp,',')){
	Vin[l].push_back(tmp); 
	ElmanRBM.docN++;
      }
      l++;
     }
   
     ElmanRBM.output(Vin);

  }

  return 0;
}
