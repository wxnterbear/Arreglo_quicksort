#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 20

using namespace std;

void arregloAleatorio(int dimension, int arreglo[]){	
    
    srand(time(NULL));
    
    // ---  Para que el primer número sea diferente de 0
    
    arreglo[0] = 1 + rand() % 100; 
    
    // --- Arreglo con números aleatorios

    for (int i = 0; i < dimension ; i++){
    	
        arreglo[i] = rand() % 100; 
    }
    
    // --- Imprimir el arreglo
    
    cout<< "El arreglo original: ";
    
    for(int i = 0; i < dimension ; i++){
		
    	cout<< arreglo[i] << " " ;
	}
	
	cout << endl;
}

void quickSort(int izquierda, int derecha, int arreglo[]){
	
	int izq = izquierda;
	int der = derecha;
	int aux;
	int pivote = arreglo [izq];
	
	
	do {
	
		while (arreglo[der] > pivote) {
			
                der--;
            }

            while (arreglo[izq] < pivote) {
            	
                izq++;
            }
		
		if (izq <= der){
			
			aux = arreglo [izq];
			arreglo [izq] = arreglo [der];
			arreglo [der] = aux;
			izq++;
			der--;
		}
	
	}while (izq <= der);
	
	if (izquierda < der){
		
		quickSort(izquierda, der, arreglo);
	}
	
	if (derecha > izq){
		
		quickSort (izq, derecha, arreglo);
	}
	
}



int main(){
	
	int arreglo[MAX];
	int dimension = MAX;
	
	
	arregloAleatorio (dimension, arreglo);
	
	quickSort(0, dimension - 1, arreglo);
	
	cout << "\nEl arreglo ordenadoi: ";
	
	for (int i = 0; i < dimension; i++){
		
		cout << arreglo [i] << " ";
	}
	
	return 0;

	
}
