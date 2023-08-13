#include <iostream>
#include "ArbolBinario.h"

using namespace std;

int main(){
    system("color 0f");

    ArbolBinario a;
    int n=0;
    int mayor = 0, minimo = 999999;
  void sumar(ArbolBinario * a, NodoBinario * r, int *suma, int *c);
  void contarHojas(NodoBinario * r, int *n);
  void datosArbolBinario(ArbolBinario a);
  a.leer();
  contarHojas(a.getRaiz(), &n);
  cout<<endl<<" EN DICHA RAMA EXISTE"<< n <<endl;
    int sumas[n];
    int c = 0;
    for (int i = 0; i < n; i++){
        sumas[i] = 0;
    }
    sumar(&a, a.getRaiz(), sumas, &c);
    for (int i = 0; i < n; i++){
        cout << " LA SUMA RESPECTIVA :  " << i << " es = " << sumas[i];
        if (sumas[i] > mayor)
            mayor = sumas[i];
        if (sumas[i] < minimo)
            minimo = sumas[i];
    }

    cout << endl<< "LA DIFERENCIA ES: " << mayor - minimo;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void datosArbolBinario(ArbolBinario a) {
  if (!a.esVacio()) {
    //cout<<endl<<"El arbol no esta vacio..Tiene:"<<a.numNodos(a.getRaiz())<<" nodos...."<<endl;
    cout << endl << "El arbol posee una altura de " << a.calcularAltura(a.getRaiz()) << endl ;
  }
}

void sumar(ArbolBinario *a, NodoBinario *r, int suma[], int *c){
    if (r != NULL)
    {
        suma[*c] += r->getDato();

        if ((r->getIzq() == NULL) && (r->getDer() == NULL))
        {
            r->setDato(0);
            *c += 1;
            return;
        }
        else
        {
            sumar(a, r->getIzq(), suma, c);
            sumar(a, r->getDer(), suma, c);
        }
    }
}

void contarHojas(NodoBinario *r, int *n){
    if (r != NULL)
    {
        if ((r->getIzq() == NULL) && (r->getDer() == NULL))
        {
            *n += 1;
        } // visualiza dato contenido
        else
        {
            contarHojas(r->getIzq(), n);
            contarHojas(r->getDer(), n);
        }
    }
}
