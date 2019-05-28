#include "FC.h"
#include <iostream>
#include <vector>

using namespace std;
template <class T>
void FC<T>::imprimir()
{

    for (int i = 0; i < valores.size(); i++)
    {
        cout << valores[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < valores.size(); i++)
    {
        cout << columnas[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < valores.size(); i++)
    {
        cout << filas[i] << " ";
    }
    cout << endl;
}

template <class T>
void FC<T>::crearMatriz(vector< vector<T> > &matrix)
{
    m = matrix.size();
    n = matrix[0].size();
    for (int fil = 0; fil < matrix.size(); fil++){
        for (int col = 0; col < matrix[fil].size(); col++){
            if (matrix[fil][col] != NULL){
                valores.push_back(matrix[fil][col]);
                filas.push_back(fil);
                columnas.push_back(col);
            }
        }
    }

}

template <class T>
vector<vector<T> > FC<T>::obtenerMatrizCompleta()
{
    int w = 0;
    vector<vector<T> > matriz_completa(m, vector<T>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (i == filas[w] && j == columnas[w] && w + 1 <= valores.size()){
                matriz_completa[i][j] = valores[w];
                w++;
            }
            else{
                matriz_completa[i][j] = NULL;
            }
        }
    }

    return matriz_completa;
}

template <class T>
T FC<T>::obtenerElemento(int i, int j)
{
    for (int w = 0; w < valores.size(); w++){
        if (filas[w] == i & columnas[w] == j)
            return valores[w];
    }
    return 0;
}

template <class T>
vector<T> FC<T>::obtenerFila(int j)
{
    vector<T> fila;
    for(int i = 0 ; i < filas.size() ; i++){
        if(filas[i] == j)
            fila.push_back(valores[i]);
    }
    return fila;
}

template <class T>
vector<T> FC<T>::obtenerColumna(int j)
{
    vector<T> columna;
    for (int i = 0; i < columnas.size(); i++)
    {
        if (columnas[i] == j)
            columna.push_back(valores[i]);
    }
    return columna;
}

template <class T>
vector<T> FC<T>::obtenerFilaDispersa(int j)
{
    vector<T> fila_d(n, 0);
    for (int i = 0; i < filas.size(); i++){
        if (filas[i] == j)
            fila_d[columnas[i]] = valores[i];
    }
    return fila_d;
}

template <class T>
vector<T> FC<T>::obtenerColumnaDispersa(int j)
{
    vector<T> columna_d(m, 0);
    for (int i = 0; i < columnas.size(); i++){
        if (columnas[i] == j)
            columna_d[filas[i]] = valores[i];
    }
    return columna_d;
}

template <class T>
int FC<T>::obtenerNumeroElementos()
{
    return valores.size();
}

template <class T>
void FC<T>::modificarPosicion(int i, int j, T val)
{
    bool flag = false;
    if(val == 0){
        for (int n = 0; n < filas.size(); n++){
            if (filas[n] == i & columnas[n] == j){
                valores.erase(valores.begin()+n);
                filas.erase(filas.begin()+n);
                filas.erase(columnas.begin()+n);

            }
        }
        flag = true;
    }
    if(i <= filas[0] && flag == false){
        if(filas[0]==i){
            if(j < columnas[0]){
                valores.insert(valores.begin(), val);
                filas.insert(filas.begin(), i);
                columnas.insert(columnas.begin(), j);
                flag = true;

            }
        }
        else{
            valores.insert(valores.begin(), val);
            filas.insert(filas.begin(), i);
            columnas.insert(columnas.begin(), j);
            flag = true;
        }


    }
    if(flag == false){
        for(int n = 0 ; n < filas.size() ; n++){
            if (filas[n] == i & columnas[n] == j){
                valores[n] = val;
                flag = true;
            }
        }
    }
    if(flag == false){
        for (int n = 0; n < filas.size()-1; n++)
        {
            if (i >= filas[n] && i <= filas[n + 1])
            {
                if (filas[n] == filas[n + 1])
                {
                    if (j >= columnas[n] && j <= columnas[n + 1])
                    {
                        valores.insert(valores.begin() + n + 1, val);
                        columnas.insert(columnas.begin() + n + 1, j);
                        filas.insert(filas.begin() + n + 1, i);
                        flag = true;
                        break;
                    }
                }
                else
                {
                    valores.insert(valores.begin() + n + 1, val);
                    columnas.insert(columnas.begin() + n + 1, j);
                    filas.insert(filas.begin() + n + 1, i);
                    flag = true;
                    break;
                }
            }
        }

    }
    if(flag == false){
        valores.push_back(val);
        columnas.push_back(j);
        filas.push_back(i);
    }
}
