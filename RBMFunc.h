//RBMFunc.h
#ifndef _RBMFUNC_H_
#define _RBMFUNC_H_

class RBM{
 private:
  double Efunc;
  vector< vector<double> > w;
  vector<double> b,c,v,h;

  public:
  void Efunc();
  void Learning(int layer);
  void CDmethod();

}:
 





#endif// _RBMFUNC_H_
