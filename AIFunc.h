//AIFunc.h
#ifndef _AIFUNC_H_
#define _AIFUNC_H_

class AI{
 private:
  int layerNum;
  vector<int> nodeNum;
  double Efunc;
  vector< vector<double> > w,h;

  public:
  void setLayer(int layerNumtmp, int *nodeNumtmp);
  void Efunc();
  void preLearning(int layer);
 

}:
 





#endif// _AIFUNC_H_
