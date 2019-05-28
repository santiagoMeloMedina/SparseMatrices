#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "OperacionesEspeciales.h"
using namespace std;


template <class T, class U, class D, class F>
F OperacionesMatrizDisperasa<T,U,D,F>::sumaMatrices(U m1, D m2){
  vector< vector<T> > matrizU = m1.obtenerMatrizCompleta();
  vector< vector<T> > matrizD = m2.obtenerMatrizCompleta();
  F matrizUDef;
  vector<T> posiciones;
  vector< vector <T> > filas;
  if (matrizU.size() == matrizD.size() && matrizU.at(0).size() == matrizD.at(0).size())
    for (int n = 0; n < matrizU.size(); n++){
      for (int e = 0; e < matrizU.at(n).size(); e++){
        posiciones.push_back(matrizU.at(n).at(e) + matrizD.at(n).at(e));
      }
      filas.push_back(posiciones);
      posiciones.clear();
    }
  matrizUDef.crearMatriz(filas);
  return matrizUDef;
}

template <class T, class U, class D, class F>
bool OperacionesMatrizDisperasa<T,U,D,F>::verificarElemento(F m1, T elemento){
  int longitudfila = m1.obtenerFilaDispersa(0).size();
  int longitudcolumna = m1.obtenerColumnaDispersa(0).size();
  for (int n = 0; n < longitudfila; n++)
    for (int e = 0; e < longitudcolumna; e++)
      if (m1.obtenerElemento(e,n) == elemento)
        return true;
  return false;
}

template <class T, class U, class D, class F>
T OperacionesMatrizDisperasa<T,U,D,F>::obtenerMayorElemento(F m1){
  int longitudfila = m1.obtenerFilaDispersa(0).size();
  int longitudcolumna = m1.obtenerColumnaDispersa(0).size();
  T mayor = m1.obtenerElemento(0,0);
  for (int n = 1; n < longitudfila; n++)
    for (int e = 1; e < longitudcolumna; e++)
      mayor = (m1.obtenerElemento(e,n) > mayor) ? m1.obtenerElemento(e,n) : mayor;
  return mayor;
}

template <class T, class U, class D, class F>
F OperacionesMatrizDisperasa<T,U,D,F>::matrizTranspuesta(F m1){
  int longitudfila = m1.obtenerFilaDispersa(0).size();
  F matrizUDef;
  vector< vector <T> > filas;
  for (int n = 0; n < longitudfila; n++){
    filas.push_back(m1.obtenerColumnaDispersa(n));
  }
  matrizUDef.crearMatriz(filas);
  return matrizUDef;
}


template <class T, class U, class D, class F>
F OperacionesMatrizDisperasa<T,U,D,F>::productoMatrizVector(F m1, vector<T> v1){
  F matrizUDef;
  vector< vector<T> > filas;
  vector<T> columnas;
  int lfil = m1.obtenerFilaDispersa(0).size();
  int lcol = m1.obtenerColumnaDispersa(0).size();
  if (m1.obtenerFilaDispersa(0).size() == v1.size()){
    for (int n = 0; n < lcol; n++){
      for (int e = 0; e < lfil; e++){
        columnas.push_back(m1.obtenerFilaDispersa(n).at(e)*v1.at(e));
      }
      filas.push_back(columnas);
      columnas.clear();
    }
    matrizUDef.crearMatriz(filas);
  }
  return matrizUDef;
}
