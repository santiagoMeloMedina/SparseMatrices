#ifndef _CSCMD
#define _CSCMD

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <class T>
class Csc {
private:
  vector<T> valores;
  vector<int> filas;
  vector<int> ccolumnas;
  int lfilas;
  int lcolumnas;

public:
  Csc();
  void crearMatriz(vector< vector<T> >);
  vector< vector<T> > obtenerMatrizCompleta();
  T obtenerElemento(int, int);
  vector<T> obtenerFila(int);
  vector<T> obtenerColumna(int);
  vector<T> obtenerFilaDispersa(int);
  vector<T> obtenerColumnaDispersa(int);
  int obtenerNumeroElementos();
  void modificarPosicion(int, int, T);
  void immd();

};

#endif
