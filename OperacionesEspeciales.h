#ifndef _OPES
#define _OPES

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class T, class U, class D, class F>
class OperacionesMatrizDisperasa{
public:
  T comparacion();
  F sumaMatrices(U, D);
  bool verificarElemento(F, T);
  T obtenerMayorElemento(F);
  F productoMatrizVector(F, vector<T>);
  T productoMatrizVector(T, list<T>);
  F matrizTranspuesta(F);
};

#endif
