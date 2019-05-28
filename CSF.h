#ifndef COMPRIMIDOFILAS_
#define COMPRIMIDOFILAS_

#include<iostream>
#include<vector>
using namespace std;

template <class T>
class CSF{
    private:
    vector<T> valores;
    vector<int> cols;
    vector<int> cfilas;
    int nfil;
    int ncol;
    public:
    CSF();
    void crearMatriz(vector< vector<T> > &matrix);
    vector< vector<T> > obtenerMatrizCompleta();
    T obtenerElemento(int fila, int columna);
    vector<T> obtenerFila(int fila);
    vector<T> obtenerColumna(int columna);
    vector<T> obtenerFilaDispersa(int fila);
    vector<T> obtenerColumnaDispersa(int columna);
    int obtenerNumeroElementos();
    void modificarPosicion(int fila, int columna, T valor);
};

#endif
