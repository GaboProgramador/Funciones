//Funciones Grafos

int ** distancia(GrafoMatriz g){
    int a;
    int cont = 0;
    int n = g.getNumVerts();
    typedef int *punt;
    int ** p = new punt[n];
    string q;

    for(int i=0;i<n;i++){
        p[i] = new int[n];
    }

    cout<<endl<<"Ingrese el numero de arcos: "; cin>>a;
    cin.ignore();
    cout<<"Ingrese el nombre del vertice: "; getline(cin, q);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            p[i][j] = g.adyacente(i, j) ? 1:0;
        }
    }

    for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if (p[i][k] * p[k][j]){
					p[i][j] = 1;
				}
			}
		}
	}

	cout<<endl<<"Desde el vertice "<<g.getVertice(q).getNumero()+1<<" con "<<a<<" arcos se puede llegar a:";
	for(int i = g.getVertice(q).getNumero();i<n;i++){
		cont=0;

		for(int j=0;j<n;j++){
			if(p[g.getVertice(q).getNumero()][j]){
				cont++;
				if(cont > a){
			     cout<<endl<<"Vertice "<<g.getVertice(j).getNombre();
			   }
			}

		}
		i=n+1;
	}

	cout<<endl;
	return p;
}

void ingresarArcos(GrafoLista *g, string* sa){
	int nv = g->getNumVerts();
	int na;
	int v = 0;
	string aux, aux2;

	for (int i=0;i<nv;i++){
		Vertice x = g -> getVertice(i);
		cout<<endl<<"Vertice #"<<x.getNumero()+1<<": "<<x.getNombre();
		cout<<endl<<"Cantidad de arcos de salida del vertice: ";
		na = leerN(0, 10);
		cin.ignore();

		if(na > v){
            v = na;
            aux2 = x.getNombre();
		}

		for (int j=0;j<na;j++){
			cout<<endl<<"Identificador del Vertice Destino: ";
			getline(cin, aux);
			g->setArco(x.getNombre(), aux);
		}
	}

	*sa = aux2;
}

void imprimirGrafo(GrafoLista g, string* en){
	int nv = g.getNumVerts();
	int na, c;
	int ma = 0;
	string aux, aux2;

	cout<<endl<<"===============================================";
	cout<<endl<<"M A T R I Z     D E    A D Y A C E N C I A"<<endl;

	for(int i=0;i<nv;i++){
		Vertice x = g.getVertice(i);
		aux = x.getNombre();
		cout<<endl<<"Vertice #"<<x.getNumero()+1<<": "<<x.getNombre();

		c = 0;
		for(int j=0;j<nv;j++){
			if(g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout<<endl<<"\t\t--->"<<x.getNombre();
			}

			for(int k=0;k<nv;k++){
                Vertice x = g.getVertice(k);
                if(g.adyacente(j, k)) if(aux == x.getNombre()) c++;
			}
		}

		if(c > ma){
            ma = c;
            aux2 = aux;
		}
	}
	cout<<endl<<"==============================================="<<endl<<endl;

	*en = aux2;
}
GrafoLista ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	Tipo aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoLista *g){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g -> getNumVerts();
	int na;
	Tipo aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			getline(cin, aux);
			g -> setArco(x.getDato(), aux);
		}
	}
}

void ingresarArcosValor(GrafoLista *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g -> getNumVerts();
	int na;
	int peso;									//peso del arco
	Tipo aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			cin >> aux; 
			cout << endl << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g -> setArco(x.getDato(), aux, peso);
		}
	}
}

void imprimirGrafo(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();

	Tipo aux;
	cout << endl << "===============================================";
	cout << endl << "L I S T A    D E    A D Y A C E N C I A";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
	
		for (int j = 0; (j < nv); j++){
			if (g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout << endl << "\t\t--->" << x.getDato() ;
			}
		}
	}
	cout << endl << "===============================================";
	cout << endl;
}

void imprimirLista(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	NodoG* actual;								//apunta al nodo actual de la lista

	cout << endl << "ELEMENTOS CONTENIDOS EN LA LISTA";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();			//copiar la direccion del primer nodo de la lista

		while (actual != NULL){					//repetir el ciclo mientras haya nodos en la lista
			cout << endl << "> " << actual->getDato() << " > " << actual->getPeso();	//visualiza el contenido del nodo actual de la lista
			actual = actual->getPunt();			//apuntador actual avanza al siguiente nodo
		}
	}
}

void calcularGradoEntrada(GrafoLista g){                //calcula el grado de entrada de cada vertice

    int nv = g.getNumVerts();

	Tipo aux;
    int gradoEntrada [nv];                              //arreglo que almacena el grado de entrada de cada vertice
	
    cout << endl << "===============================================";
    cout << endl << "GRADOS DE ENTRADA DE CADA VERTICE";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

        

        for(int j = 0; j < nv; j++){
            ListaG vlista = g.listaAdyacencia(j);
            if(vlista.buscarValorEnLista(x.getDato()) != NULL){
                gradoEntrada[i]=gradoEntrada[i]+1;
            }  
        }
        cout << endl << "Grado de entrada: " << gradoEntrada[i];
	}
	cout << endl << "===============================================";
	cout << endl;
}
