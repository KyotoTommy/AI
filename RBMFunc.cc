#include "RBMFunc.h"

double RBM::randMake(){
 srand((unsigned)time(NULL));
 return (double)rand()/RAND_MAX;
}

void RBM::updatePara(){
int i,j;

//update  W
for(i=0; i<visibleNum; i++){
	for(j=0; j<hiddenNum; j++)
		w[i][j] += alpha * ( visible[i]*prob_h_v(j,visible) - visible_1[i]*prob_h_v(j,visible_1) );
}

//update b
for(i=0; i<visibleNum; i++)
	b[i] += alpha * ( visible[i] - visible_1[i] );

//update h
for(j=0; j<hiddenNum; j++)
	c[j] += alpha * ( prob_h_v(j,visible) - prob_h_v(j,visible_1) );

}

vector<int> RBM::output(vector<double> &prob){
int i;
vector<int> out;

for(i=0; i<prob.size(); i++){
	if( randMake() <=prob[i] )
		out.push_back(1);
	else
		out.push_back(0);
 
	}
	return out
}
vector<double> RBM::prob_h_v(vector<double> &v_){
double lambda;
int i,j;
vector<double> prob

for(j=0; j<hiddenNum; j++){
lambda = c[j];
for(i=0; i<visibleNum; i++)
	lambda += v_[i]*w[i][j];	
 prob.push_back( 1 / ( 1 + exp( -lambda ) ) );
}
return prob;
}

vector<double> RBM::prob_v_h(vector<double> &h_){
 double lambda;
 int i,j;
vector<double> prob

for(i=0; i<visibleNum; i++){
 lambda = b[i]; 
 for(j=0; j<hiddenNum; j++)
 	lambda += h_[j]*w[i][j];
prob.push_back( 1 / ( 1 + exp( -lambda ) ) )
}

return prob;
}

vector<double> RBM::Rebuild(vector<int> &v){
 h = output( prob_h_v(&v) );
 return output( prob_v_h(&h) );
}
