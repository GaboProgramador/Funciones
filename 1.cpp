#include <iostream>
using namespace std;

int main(){
	int n;
	void ingreoV(int a, int *U,int b);
	void MostrarV(int a, int *U,int b);
	int DemostrarVA(int a, int *U,int b);
	int DemostrarVD(int a, int *U,int b);
	int busquedaBinariai(int a, int *U,int b, int o);
	int busquedaBinarias(int a, int *U,int b, int o);
	cout << endl << "Ingrese la dimencion del vector :";
	cin>>n;
	int U[n],c,C;
	ingreoV(n,U,0);
	cout << endl << "===========  vector ===========:";
	MostrarV(n,U,0);
	cout << endl;
	cout << endl << "===========  Odenado ===========:";
	cout << endl;
	c=DemostrarVA(n,U,0);
	C=DemostrarVD(n,U,0);
	cout << endl;
	if(c==n-1||C==n-1){
		cout<<"Ordenado ";
		if(c>C)
			cout<<"   Crecientemente  ";
		else
			cout<<"   Decrecientemente  ";
		cout << endl;
		cout << endl;
		cout<<"========= Busqueda Binaria ==========: "<< endl;
		cout<<"Ingrese el valor a buscar  ";
	  	int o,t=0,T=0;
	  	cin>> o;
	  	t=busquedaBinariai(n,U,n/2,o);
		T=busquedaBinarias(n,U,n/2,o);
		cout<<t<<"-----"<<T;
		if(t==1 || T==1)
			cout<<" El valor existe   ";
		else
			cout<<" El valor no existe   ";
	}else
		cout<<"No ordenado";
	cout << endl;
	system("pause");
}


void ingreoV(int a, int *U,int b){
	int aux;
	if(b<a){
		cout << endl << "Ingrese el valor "<<b+1<<" :";
		cin>>aux;
		U[b]=aux;
		ingreoV(a,U,b+1);
	}
}

void MostrarV(int a, int *U,int b){
	if(b<a){
		cout << endl <<U[b];
		MostrarV(a,U,b+1);
	}
}

int DemostrarVA(int a, int *U,int b){
	if(b>=a)
		return b+1;
//	cout<< b;
	if(b<a){
		if(b!=a-1){
			if(U[b]<U[b+1]){
				DemostrarVA(a,U,b+1);
			}
		}


	}

}

int DemostrarVD(int a, int *U,int b){

	if(b>=a)
		return b+1;
//	cout<< b;
	if(b<a){
		if(b!=a-1){
			if(U[b]>U[b+1]){
				DemostrarVD(a,U,b+1);

			}
		}
	}

}

int busquedaBinariai(int a, int *U,int b, int o){
	if(b==-1)
		return 0;
	if(b<a){
		if(U[b]==o)
			return 1;
		if(b!=-1){
			if(U[b]<o)
				busquedaBinariai(a,U,b-1,o);
		}
	}
}

int busquedaBinarias(int a, int *U,int b, int o){
	if(b==a)
		return 0;
	if(b<a){
		if(U[b]==o)
			return 1;
		if(b!=a-1){
			if(U[b]>o)
				busquedaBinarias(a,U,b+1,o);
		}
	}

}
