#include "CSF.h"

template <class T>
CSF<T>::CSF(){
    nfil = 0;
    ncol = 0;
}

template <class T>
void CSF<T>::crearMatriz(vector< vector<T> >& matrix){
    bool pivot;
    int zeros;
    int count = 0;
    nfil = matrix.size();
    ncol = matrix[0].size();
    for(int fil = 0; fil < nfil; fil++){
        if(zeros == matrix.size()){
            cfilas.push_back(count);
        }
        pivot = true;
        zeros = 1;
        for(int col = 0; col < ncol; col++){
            if(matrix[fil][col] != NULL && pivot){
                valores.push_back(matrix[fil][col]);
                cols.push_back(col);
                cfilas.push_back(count++);
                pivot = false;
            }
            else if(matrix[fil][col] != NULL){
                valores.push_back(matrix[fil][col]);
                cols.push_back(col);
                count++;
            }
            else{
                zeros++;
            }

        }
    }
    cfilas.push_back(count);
}

template <class T>
vector<T> CSF<T>::obtenerFila(int fila){
    vector<T> resultado;
    if(cfilas[fila] != cfilas[fila+1] && fila+1 != cfilas.size()){
        for(int i = cfilas[fila]; i < cfilas[fila+1]; i++){
            resultado.push_back(valores[i]);
        }
        return resultado;
    }
}

template <class T>
vector<T> CSF<T>::obtenerColumna(int columna){
    vector<T> resultado;
    int colsSize = cols.size();
    for(int i = 0; i < colsSize; i++){
        if(cols[i] == columna){
            resultado.push_back(valores[i]);
        }
    }
    return resultado;
}

template <class T>
vector<T> CSF<T>::obtenerFilaDispersa(int fila){
    vector<T> resultado(ncol, 0);
    if(cfilas[fila] != cfilas[fila+1] && fila+1 != cfilas.size()){
        for(int i = cfilas[fila]; i < cfilas[fila+1]; i++){
            resultado[cols[i]] = valores[i];
        }
    }
    return resultado;

}

template <class T>
vector< vector<T> > CSF<T>::obtenerMatrizCompleta(){
    vector< vector<T> > resultado(nfil, vector<T>(ncol));
    for(int fil = 0; fil < nfil; fil++){
        vector<T> current = obtenerFilaDispersa(fil);
        for(int col = 0; col < ncol ; col++){
            resultado[fil][col] = current[col];
        }
    }
    return resultado;
}

template <class T>
T CSF<T>::obtenerElemento(int fila, int columna){
    T resultado;
    resultado = obtenerFilaDispersa(fila)[columna];
    return resultado;
}

template <class T>
vector<T> CSF<T>::obtenerColumnaDispersa(int columna){
    vector<T> resultado(nfil, 0);
    for(int i = 0; i < nfil; i++){
        resultado[i] = (obtenerFilaDispersa(i))[columna];
    }
    return resultado;
}

template <class T>
int CSF<T>::obtenerNumeroElementos(){
    return valores.size();
}

template <class T>
void CSF<T>::modificarPosicion(int j, int i, T elemento){
    typename vector<T>::iterator it;
    int indexfila = cfilas.at(j+1), diferencia;
    if (cols.at(indexfila-1) == i){
        if (elemento != NULL){
        valores.at(indexfila-1) = elemento;
        } else {
        valores.erase(valores.begin() + (indexfila-1));
        cols.erase(cols.begin() + (indexfila-1));
        for (it = cfilas.begin()+j+1; it != cfilas.end(); ++it)
            (*it)--;
        }
    } else {
        diferencia = indexfila - cfilas.at(j) - 1;
        for (int n = indexfila-1-diferencia; n < indexfila-1; n++){
        if (cols.at(n) == i)
            if (elemento != NULL){
            valores.at(n) = elemento;
            return;
            } else {
            valores.erase(valores.begin() + n);
            cols.erase(cols.begin() + n);
            for (it = cfilas.begin()+j+1; it != cfilas.end(); ++it)
                (*it)--;
                return;
            }
        }
        for (int e = indexfila-1-diferencia; e <= indexfila-1; e++){
        if (e > i){
            valores.insert(valores.begin()+(e+1), elemento);
            cols.insert(cols.begin()+(e+1), i);
            for (it = cfilas.begin()+j+1; it != cfilas.end(); ++it)
            (*it)++;
            break;
        }
        }
    }
}
