#include "ElmanRBMFunc.h"

int main(int argc, char *argv[]){

  int LorO, k, i;
  int l = 0; 
  vector< vector<string> > Vin;

  while(1){
    
    cout<<"learning?(=2) or output?(=1) or exit(=0)"<<endl;
    cin>>LorO;

    ElmanRBM ElmanRBM(20,10);
    ElmanRBM.ini();

    if(LorO==2){//Learning mode
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

    }else if(LorO==1){//output mode

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

    }else{
      break;//finish 
    }
    
  }

  cout<<"bye!";

  return 0;
}
