//Funciones AB

NodoBinario* encontrarNodoMenor(NodoBinario* nodo) {
    if (nodo == nullptr)
        return nullptr;

    NodoBinario* nodoMenorIzq = encontrarNodoMenor(nodo->getIzq());
    NodoBinario* nodoMenorDer = encontrarNodoMenor(nodo->getDer());

    NodoBinario* nodoMenorActual = nodo;

    if (nodoMenorIzq != nullptr && nodoMenorIzq->getDato() < nodoMenorActual->getDato()) {
        nodoMenorActual = nodoMenorIzq;
    }

    if (nodoMenorDer != nullptr && nodoMenorDer->getDato() < nodoMenorActual->getDato()) {
        nodoMenorActual = nodoMenorDer;
    }

    return nodoMenorActual;
}
void encontrarMayorPorNivel(NodoBinario* raiz) {
    if (raiz == nullptr) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    vector<NodoBinario*> nivelActual;
    vector<NodoBinario*> nivelSiguiente;
    nivelActual.push_back(raiz);

    while (!nivelActual.empty()) {
        Tipo mayorValor = nivelActual[0]->getDato();

        for (NodoBinario* nodo : nivelActual) {
            if (nodo->getDato() > mayorValor) {
                mayorValor = nodo->getDato();
            }

            if (nodo->getIzq() != nullptr) {
                nivelSiguiente.push_back(nodo->getIzq());
            }
            if (nodo->getDer() != nullptr) {
                nivelSiguiente.push_back(nodo->getDer());
            }
        }

        cout << "Mayor valor del nivel: " << mayorValor << endl;

        nivelActual = nivelSiguiente;
        nivelSiguiente.clear();
    }
}

int encontrarValorMenor(NodoBinario* nodo, int nivel, int& nivelMaximo) {
    if (nodo == nullptr)
        return INT_MAX;

    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        if (nivel > nivelMaximo) {
            nivelMaximo = nivel;
            return nodo->getDato();
        } else {
            return INT_MAX;
        }
    }

    int valorIzq = encontrarValorMenor(nodo->getIzq(), nivel + 1, nivelMaximo);
    int valorDer = encontrarValorMenor(nodo->getDer(), nivel + 1, nivelMaximo);

    return min(valorIzq, valorDer);
}
int encontrarMinimo(NodoBinario* nodo) {
    if (nodo == nullptr) {
        return INT_MAX;
    }

    int minimo = nodo->getDato();
    int minimoIzquierdo = encontrarMinimo(nodo->getIzq());
    int minimoDerecho = encontrarMinimo(nodo->getDer());

    if (minimoIzquierdo < minimo) {
        minimo = minimoIzquierdo;
    }

    if (minimoDerecho < minimo) {
        minimo = minimoDerecho;
    }

    return minimo;
}
int encontrarMaximo(NodoBinario* nodo) {
    if (nodo == nullptr) {
        return INT_MIN;
    }

    int maximo = nodo->getDato();
    int maximoIzquierdo = encontrarMaximo(nodo->getIzq());
    int maximoDerecho = encontrarMaximo(nodo->getDer());

    if (maximoIzquierdo > maximo) {
        maximo = maximoIzquierdo;
    }

    if (maximoDerecho > maximo) {
        maximo = maximoDerecho;
    }

    return maximo;
}
bool esLleno(NodoBinario *r){
    if (r == NULL){
        return true;
    } else if (r -> getIzq() == NULL && r -> getDer() == NULL){
        return true;
    } else if (r -> getIzq() != NULL && r -> getDer() != NULL){
        return esLleno(r -> getIzq()) && esLleno(r -> getDer());
    } else {
        return false;
    }
}

bool esCompleto(NodoBinario *r){
    if (r == NULL){
        return true;
    } else if (r -> getIzq() == NULL && r -> getDer() == NULL){
        return true;
    } else if (r -> getIzq() != NULL && r -> getDer() != NULL){
        return esCompleto(r -> getIzq()) && esCompleto(r -> getDer());
    } else if (r -> getIzq() != NULL && r -> getDer() == NULL){
        return false;
    } else {
        return esCompleto(r -> getIzq());
    }
}

bool esDegenerado(NodoBinario *r){
    if (r == NULL){
        return true;
    } else if (r -> getIzq() == NULL && r -> getDer() == NULL){
        return true;
    } else if (r -> getIzq() != NULL && r -> getDer() != NULL){
        return false;
    } else if (r -> getIzq() != NULL && r -> getDer() == NULL){
        return esDegenerado(r -> getIzq());
    } else {
        return esDegenerado(r -> getDer());
    }
}