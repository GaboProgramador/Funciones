void agregarElemento(int valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = nullptr;

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    int obtenerRango() {
        if (cabeza == nullptr) {
            cout << "La lista está vacía." << endl;
            return 0;
        }

        int minimo = cabeza->dato;
        int maximo = cabeza->dato;
        Nodo* temp = cabeza->siguiente;

        while (temp != nullptr) {
            if (temp->dato < minimo) {
                minimo = temp->dato;
            } else if (temp->dato > maximo) {
                maximo = temp->dato;
            }
            temp = temp->siguiente;
        }

        return maximo - minimo;
    }
void dividirListas(Lista& listaPares, Lista& listaImpares) {
        Nodo* temp = cabeza;

        while (temp != nullptr) {
            if (temp->dato % 2 == 0) {
                listaPares.agregarElemento(temp->dato);
            } else {
                listaImpares.agregarElemento(temp->dato);
            }
            temp = temp->siguiente;
        }
    }

    void mostrarLista() {
        Nodo* temp = cabeza;

        while (temp != nullptr) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }

        cout << endl;
    }    
void ordenarPorDigitos() {
        if (cabeza == nullptr || cabeza->siguiente == nullptr) {
            return; // La lista está vacía o solo tiene un elemento
        }

        bool intercambioRealizado = true;
        while (intercambioRealizado) {
            intercambioRealizado = false;
            Nodo* actual = cabeza;
            Nodo* siguiente = cabeza->siguiente;

            while (siguiente != nullptr) {
                if (cantidadDigitos(actual->dato) > cantidadDigitos(siguiente->dato)) {
                    intercambiarNodos(actual, siguiente);
                    intercambioRealizado = true;
                }

                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
        }
    }

    int cantidadDigitos(int numero) {
        if (numero == 0) {
            return 1;
        }

        int contador = 0;
        while (numero != 0) {
            contador++;
            numero /= 10;
        }

        return contador;
    }

    void intercambiarNodos(Nodo* nodo1, Nodo* nodo2) {
        int temp = nodo1->dato;
        nodo1->dato = nodo2->dato;
        nodo2->dato = temp;
    }

    void mostrarLista() {
        Nodo* temp = cabeza;

        while (temp != nullptr) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }

        cout << endl;
    }    
    void eliminarPenultimoNodo() {
        if (cabeza == nullptr || cabeza->siguiente == nullptr) {
            cout << "La lista no tiene suficientes nodos." << endl;
            return;
        }

        Nodo* temp = cabeza;
        while (temp->siguiente->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        Nodo* penultimo = temp->siguiente;
        temp->siguiente = nullptr;
        delete penultimo;
    }
    int busquedaBinaria(const vector<int>& lista, int valor) {
    int inicio = 0;
    int fin = lista.size() - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (lista[medio] == valor) {
            return medio;
        } else if (lista[medio] < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1;
}
int calcularSumaPares() {
        int suma = 0;
        Nodo* temp = cabeza;

        while (temp != nullptr) {
            if (temp->dato % 2 == 0) {
                suma += temp->dato;
            }
            temp = temp->siguiente;
        }

        return suma;
    }

    int calcularSumaImpares() {
        int suma = 0;
        Nodo* temp = cabeza;

        while (temp != nullptr) {
            if (temp->dato % 2 != 0) {
                suma += temp->dato;
            }
            temp = temp->siguiente;
        }

        return suma;
    }

    void mostrarLista() {
        Nodo* temp = cabeza;

        while (temp != nullptr) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }

        cout << endl;
    }