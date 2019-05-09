#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
  double eps=1.0;
  double beta=1.0;
  double t_max = 2.0;
  double dt = 0.01;
  double t;
  double dx = 0.01;
  int ns = 1.0/(dx);
  double To[ns];
  double Tn[ns];
  int i;
  ofstream outfile;

  for(i=0;i<ns;i++){
    To[i] = 0.05*sin(4*M_PI*i*dx);     
  }
  Tn[0] = 0.0;
  Tn[ns-1] = 0.0;

  outfile.open("eq.dat");
  while(t < t_max){
    for(i=1;i<ns-1;i++){
      Tn[i] = To[i] - ((beta/4) * ((To[i+1]*To[i+1])-(To[i-1]*To[i-1])))+ (((beta*beta)/8)*(((To[i+1]+To[i])*((To[i+1]*To[i+1])-(To[i]*To[i])))-((To[i]+To[i-1])*((To[i]*To[i])-(To[i-1]*To[i-1])))));
    }
    for(i=0;i<ns;i++){
      outfile << Tn[i] << " ";
    }
    outfile << "\n";

    for(i=1;i<ns-1;i++){
      To[i] = Tn[i];
    }
    t = t + dt;
  }
  outfile.close();
  return 0;
}
