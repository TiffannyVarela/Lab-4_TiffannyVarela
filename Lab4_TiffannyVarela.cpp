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

//leer primera fila de la matriz
char** readMatriz(char**,int);

//calculo de azulejos
char** calculo(char**, int);

//metodo booleano revision
bool revision (char, char,char);

//contar azulejos seguros
int contar(char**, int);

int main(){
	int size;
	int opc=0;
	char** matriz = NULL;
	do {//inicio do while
                switch(opc=menu()){//inicio switch
                        case 1:
				cout<<"Ingrese el tamanio de la matriz"<<endl;
				cin>>size;
				matriz = provisionarMatriz(size);
				readMatriz(matriz,size);
				calculo(matriz, size);
				printMatrix(matriz,size); 
				cout<<"La cantidad de azulejos seguros es: "<<contar(matriz, size)<<endl;
				liberarMatriz(matriz, size);
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

char** readMatriz(char** matriz, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i==0){
				cout<<"Ingrese el valor de casilla ["<<i<<","<<j<<"]"<<endl;
				cin>>matriz[i][j];
			}
		}
	}
	return matriz;
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

char** calculo (char** matriz, int size){
	char x, y, z;
	int cont = 0;
	for(int i=1;i<size;i++){
		for(int j=0;j<size;j++){
			if(j==0){
				if(matriz[i-1][j] == '^' && matriz [i-1][j+1] == '^' || matriz[i-1][j] == '.' && matriz [i-1][j+1] == '^'){
					matriz [i][j] = '^';
				}
				else{
					matriz [i][j]='.';
				}
			}
			if (j==size-1){
				if((matriz[i-1][size-2] == '^' && matriz [i-1][size-1] == '^') || (matriz[i-1][size-2] == '^' && matriz [i-1][size-1] == '.')){
                                        matriz [i][j] = '^';
                                }
                                else{
                                        matriz [i][j]='.';
                                }

			}
			if (j !=0 && j!=size-1){
			x=matriz[i-1][j-1];
		      y=matriz[i-1][j];
	      	      z=matriz[i-1][j+1];
			if(revision (x,y,z)){	      
				matriz [i][j] = '^';
                     	}
			else{
				matriz [i][j] ='.';
			}
			}
		}
	}
	return matriz;
}

bool revision (char x, char y, char z){
	if(x == '^' && y == '^' && z == '.'){
		return true;
	}
	else if( x == '.' && y == '^' && z == '^'){
		return true;
	}
	else if(x == '.' && y == '.' && z == '^'){
		return true;
	}
	else if( x == '^' && y == '.' && z == '.'){
		return true;
	}
	else{
		return false;
	}
}

int contar(char** matriz, int size){
	int cont =0 ;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(matriz[i][j]=='.'){
				cont++;
			}
		}
	}
	return cont;
}
