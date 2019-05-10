#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <fstream>
using std::ifstream;

int menu();
//Provisionar la matriz de chars
char** provisionarMatriz(int);

//liberar memoria de la matriz
void liberarMatriz(char**&,int);

//imprimir la matriz
void printMatrix(char**,int);



int main(){
	int size;
	char** matriz = NULL;
	do {//inicio do while
                switch(opc=menu()){//inicio switch
                        case 1:
				cout<<Ingrese el tamanio de la matriz<<endl;
				cin>>size;

                        break;

			case 2:
                        cout<<"Fin del programa"<<endl;
                        break;
                }
        }while (opc!=2);

	return 0;
}

int menu(){
        while(true){
        cout<<"MENU"<<endl
        <<"1.- Ejercicio 1"<<endl
        <<"2.- Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        int opcion =0;
        cin>>opcion;
        if(opcion>=1 && opcion<= 2){
                return opcion;
          }
          else{

        cout<<"La opcion elegida no es valida, ingrese 1 o 2"<<endl;
  }
  }//end del while
        return 0;
}


char** provisionarMatriz(int size){
        char** matrix = new char* [size];
        for(int i=0; i<size; i++){
                matrix[i]=new char[size];
        }
        return matrix;
}

void liberarMatriz(char**& matrix, int size){
        for(int i=0;i<size;i++){
                if (matrix[i]!=NULL){
                         delete[]matrix[i];
                        matrix[i]=NULL;
                }
        }

        if(matrix!=NULL){
                delete[] matrix;
                matrix=NULL;
        }
}

void printMatrix(char** matriz, int size){
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++)
                        cout<<"[ "<<matriz[i][j]<<" ] ";

                cout<<endl;
        }
}

