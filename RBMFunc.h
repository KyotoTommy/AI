//RBMFunc.h
#ifndef _RBMFUNC_H_
#define _RBMFUNC_H_

class RBM{
 private:
  double Efunc;
  vector< vector<double> > w;
  vector<double> b,c,v,h;
  int visibleNum, hiddenNum;

  public:
  void Efunc();
  void updatePara();
  void CDmethod();
　void RBM(int i, int j){
　 visibleNum = i;
　 b.resize(i);
　 hiddenNum = j;
　 c.resize(j)
　 w.resize(i);
　 for(int k=0; k<i; k++)
　  w[i].resize(j);
　}
};

#endif// _RBMFUNC_H_
