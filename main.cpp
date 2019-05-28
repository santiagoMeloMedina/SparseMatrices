#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "CSC.cpp"
#include "OperacionesEspeciales.cpp"
#include "FC.cpp"
#include "CSF.cpp"
using namespace std;


int main(){
  vector< vector <int> > miu;
  int valorespv[] = {0,2,0,0,0,0,4};
  int valorespv1[] = {0,8,9,0,0,1,0};
  int valorespv2[] = {0,0,0,3,0,0,0};
  int valorespv3[] = {0,0,0,0,0,0,0};
  int valorespv4[] = {5,0,0,0,0,6,0};
  int valorespv5[] = {1,2,0,0,0,0,0};
  int valorespv6[] = {4,0,0,0,0,0,0};
  int valorespv7[] = {0,0,7,0,0,11,0};
  vector <int> miuc(valorespv, valorespv + sizeof(valorespv)/sizeof(*valorespv));
  vector <int> miuc1(valorespv1, valorespv1 + sizeof(valorespv1)/sizeof(*valorespv1));
  vector <int> miuc2(valorespv2, valorespv2 + sizeof(valorespv2)/sizeof(*valorespv2));
  vector <int> miuc3(valorespv3, valorespv3 + sizeof(valorespv3)/sizeof(*valorespv3));
  vector <int> miuc4(valorespv4, valorespv4 + sizeof(valorespv4)/sizeof(*valorespv4));
  vector <int> miuc5(valorespv5, valorespv5 + sizeof(valorespv5)/sizeof(*valorespv5));
  vector <int> miuc6(valorespv6, valorespv6 + sizeof(valorespv6)/sizeof(*valorespv6));
  vector <int> miuc7(valorespv7, valorespv7 + sizeof(valorespv7)/sizeof(*valorespv7));
  miu.push_back(miuc);
  miu.push_back(miuc1);
  miu.push_back(miuc2);
  miu.push_back(miuc3);
  miu.push_back(miuc4);
  miu.push_back(miuc5);
  miu.push_back(miuc6);
  miu.push_back(miuc7);
  int valorespvector[] = {2,1,2,2,2,2,3};
  vector <int> miuvector(valorespvector, valorespvector + sizeof(valorespvector)/sizeof(*valorespvector));
  Csc<int> me;
  CSF<int> mj;
  FC<int> ms;

  me.crearMatriz(miu);
  mj.crearMatriz(miu);
  ms.crearMatriz(miu);
  OperacionesMatrizDisperasa< int, CSF<int>, FC<int>, CSF<int> > op;
  //cout << op.obtenerMayorElemento(me, miuvector) << endl;
  //vector< vector<int> > matrizcompleta = op.matrizTranspuesta(mj).obtenerMatrizCompleta();
  //vector< vector<int> > matrizcompleta = op.matrizTranspuesta(me).obtenerMatrizCompleta();


  for (int n = 0; n < matrizcompleta.size(); n++){
    for (int e = 0; e < matrizcompleta.at(n).size(); e++)
      cout << matrizcompleta.at(n).at(e) << "  ";
    cout << endl;
  }

  return 0;
}
