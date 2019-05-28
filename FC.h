#ifndef FORMATOCOORDENADO_
#define FORMATOCOORDENADO_
#include <iostream>
#include <vector>
using namespace std;



template <class T>
class FC{
  private:
    vector<T> valores;
    vector<int> filas;
    vector<int> columnas;
    int m;
    int n;

  public:
    void imprimir();
    void crearMatriz(vector< vector<T> > &matrix);
    vector<vector<T> > obtenerMatrizCompleta();
    T obtenerElemento(int, int);
    vector<T> obtenerFila(int);
    vector<T> obtenerColumna(int);
    vector<T> obtenerFilaDispersa(int);
    vector<T> obtenerColumnaDispersa(int);
    int obtenerNumeroElementos();
    void modificarPosicion(int, int , T);
};
#endif
