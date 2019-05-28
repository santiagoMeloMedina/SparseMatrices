#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "CSC.h"
using namespace std;


template <class T>
Csc<T>::Csc(){
  cout << "";
}

template <class T>
void Csc<T>::crearMatriz(vector< vector<T> > matrizcompleta){
  typename vector< vector<T> >::iterator it;
  int cuenta = 0;
  ccolumnas.push_back(0);
  lfilas = matrizcompleta.size();
  lcolumnas = matrizcompleta.at(0).size();
  for (int n = 0; n < matrizcompleta.at(0).size(); n++){
    for (it = matrizcompleta.begin(); it != matrizcompleta.end(); ++it)
      if ((*it).at(n) != NULL){
        valores.push_back((*it).at(n));
        filas.push_back(distance(matrizcompleta.begin(), it));
        cuenta++;
      }
    ccolumnas.push_back(cuenta);
  }
}


template <class T>
vector< vector<T> > Csc<T>::obtenerMatrizCompleta(){
  vector<T> vectorad;
  vector< vector<T> > mcompleta;
  typename vector<T>::iterator it;
  int cuenta = 0;
  bool agregado;
  for (int i = 0; i < lfilas; i++){
    for (it = ccolumnas.begin()+1; it != ccolumnas.end(); ++it){
      agregado = false;
      for (int n = cuenta; n < *it; n++){
        if (filas.at(n) == i){
          vectorad.push_back(valores.at(n));
          agregado = true;
        }
        cuenta++;
      }
      if (!agregado)
        vectorad.push_back(NULL);
    }
    mcompleta.push_back(vectorad);
    vectorad.clear();
    cuenta = 0;
  }
  return mcompleta;
}


template <class T>
T Csc<T>::obtenerElemento(int i, int j){
  typename vector< vector<T> >::iterator it, ti;
  int indexfila = ccolumnas.at(j+1), diferencia;
  if (filas.at(indexfila-1) == i){
    return valores.at(indexfila-1);
  } else {
    diferencia = ccolumnas.at(j+1) - ccolumnas.at(j) - 1;
    for (int n = ccolumnas.at(j+1)-1-diferencia; n < ccolumnas.at(j+1)-1; n++){
      if (filas.at(n) == i)
        return valores.at(n);
    }
    return NULL;
  }
}

template <class T>
vector<T> Csc<T>::obtenerFila(int i){
  vector<T> vectorad;
  typename vector<T>::iterator it;
  int cuenta = 0;
  for (it = ccolumnas.begin()+1; it != ccolumnas.end(); ++it){
    for (int n = cuenta; n < *it; n++){
      if (filas.at(n) == i){
        vectorad.push_back(valores.at(n));
      }
      cuenta++;
    }
  }
  return vectorad;
}


template <class T>
vector<T> Csc<T>::obtenerFilaDispersa(int i){
  vector<T> vectorad;
  typename vector<T>::iterator it;
  int cuenta = 0;
  bool agregado;
  for (it = ccolumnas.begin()+1; it != ccolumnas.end(); ++it){
    agregado = false;
    for (int n = cuenta; n < *it; n++){
      if (filas.at(n) == i){
        vectorad.push_back(valores.at(n));
        agregado = true;
      }
      cuenta++;
    }
    if (!agregado)
      vectorad.push_back(NULL);
  }
  return vectorad;
}


template <class T>
vector<T> Csc<T>::obtenerColumna(int j){
  vector<T> vectorad;
  typename vector<T>::iterator it;
  for (int n = ccolumnas.at(j); n < ccolumnas.at(j+1); n++){
    vectorad.push_back(valores.at(n));
  }
  return vectorad;
}


template <class T>
vector<T> Csc<T>::obtenerColumnaDispersa(int j){
  vector<T> vectorad;
  typename vector<T>::iterator it;
  for (int n = 0; n < lfilas; n++){
    vectorad.push_back(NULL);
  }
  for (int n = ccolumnas.at(j); n < ccolumnas.at(j+1); n++){
    vectorad.at(filas.at(n)) = valores.at(n);
  }
  return vectorad;
}


template <class T>
void Csc<T>::modificarPosicion(int i, int j, T elemento){
  typename vector<T>::iterator it;
  int indexfila = ccolumnas.at(j+1), diferencia;
  if (filas.at(indexfila-1) == i){
    if (elemento != NULL){
      valores.at(indexfila-1) = elemento;
    } else {
      valores.erase(valores.begin() + (indexfila-1));
      filas.erase(filas.begin() + (indexfila-1));
      for (it = ccolumnas.begin()+j+1; it != ccolumnas.end(); ++it)
        (*it)--;
    }
  } else {
    diferencia = indexfila - ccolumnas.at(j) - 1;
    for (int n = indexfila-1-diferencia; n < indexfila-1; n++){
      if (filas.at(n) == i)
        if (elemento != NULL){
          valores.at(n) = elemento;
          return;
        } else {
          valores.erase(valores.begin() + n);
          filas.erase(filas.begin() + n);
          for (it = ccolumnas.begin()+j+1; it != ccolumnas.end(); ++it)
            (*it)--;
            return;
        }
    }
    for (int e = indexfila-1-diferencia; e <= indexfila-1; e++){
      if (e > i){
        valores.insert(valores.begin()+(e+1), elemento);
        filas.insert(filas.begin()+(e+1), i);
        for (it = ccolumnas.begin()+j+1; it != ccolumnas.end(); ++it)
          (*it)++;
        return;
      }
    }
  }
}



template <class T>
void Csc<T>::immd(){
  typename vector<T>::iterator it;
  for (it = valores.begin(); it != valores.end(); ++it)
    cout << *it << " ";
  cout << endl;
  for (it = filas.begin(); it != filas.end(); ++it)
    cout << *it << " ";
  cout << endl;
  for (it = ccolumnas.begin(); it != ccolumnas.end(); ++it)
    cout << *it << " ";
  cout << endl;

}
