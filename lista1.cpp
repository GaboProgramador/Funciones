//1. Insertar ordenadamente los elementos en una lista, desde el final de la misma
//Keyla Munoz

#include "Lista.h"

using namespace std;

int main(){
	system("color f0");
	Lista listaA;

	void ingresarLista(Lista *a);			            //funcion que ingresa los valores a incluir en la lista
	void imprimirLista(Lista a);			            //funcion que presenta los valores contenidos en los nodos de una lista

	ingresarLista(&listaA);
	cout << endl << "VALORES INGRESADOS EN LA LISTA ";
	imprimirLista(listaA);



	cout << endl;
	system("pause");
}

void ingresarLista(Lista *a){	                        //funcion que ingresa los valores a incluir en la lista
	Tipo aux;			                                //var de lectura
	Tipo fin = 99999;	                                //marcador de final de lectura

	do {
		cout << endl << "Ingrese un valor para la lista, finalice con [" << fin <<"]: ";
		cin >> aux;

		if (aux != fin){								//no ingresa marcador de fin de lectura
			a->insertarAlFinal(aux);					//llamado al metodo que inserta un nuevo nodo al final de una lista
		}
	}while (aux != fin);								//termina lectura con ingreso de marcador de fin
}

void imprimirLista(Lista a){	                        //funcion que presenta los valores contenidos en los nodos de una lista
	//recorrido de la lista
	Nodo* actual;		                                //referencia al nodo actual de la lista

	actual = a.getPrimero();	                        //almacenar temporalmente la posicion del primero nodo de la lista
	while (actual != NULL){		                        //repetir mientras no se alcance el final de la lista
		cout << endl << "> " << actual->getDato();
		actual = actual->getPunt();		                //desplaza el puntero actual al siguiente nodo de la lista
	}
}
