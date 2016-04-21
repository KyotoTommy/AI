//RBMFunc.h
#ifndef _RBMFUNC_H_
#define _RBMFUNC_H_

class RBM{
 private:
  int layerNum;
  vector<int> nodeNum;
  double Efunc;
  vector< vector<double> > w,h;

  public:
  void setLayer(int layerNumtmp, int *nodeNumtmp);
  void Efunc();
  void preLearning(int layer);
  void CDmethod();

}:
 





#endif// _RBMFUNC_H_
