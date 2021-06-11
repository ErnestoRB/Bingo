#include "bingo.h"
#include <windows.h>
using std::cout;
using std::endl;

void llenarvertical(int **matriz, int ren, int col){
	int *vec;
	vec=new int[100];
	for (int i=0; i<100; i++){
		vec[i]=i+1;
	}
	shuffle(vec,100);
	int *aux;
	aux= new int[5];
	int inicio=0;
	int fin=5;
	for (int r=0; r<ren; r++){
		int cont=0;
		for( int i=inicio; i<fin; i++){
			aux[cont]=vec[i];
			cont++;
		}
		shuffle(aux,5);
		for(int c=0; c<col; c++){
			matriz[r][c]=aux[c];
		}
		inicio=fin;
		fin=fin+5;
	}
}
bool revisarvertical(int num, int **m,int ren, int col,int *vec, int &indice){
	bool exito=false;
	int c;
	c=2;
	for(int j=0; j<col; j++){
		for(int i=0; i<ren; i++){
			if(m[i][c]==num){
				vec[indice]=num;
				indice++;
				m[i][c]=0;
				return true;
			}
		}
	}
	return false;
}

bool ganarvertical(int **mat,int ren,int col){
	bool band=false;
	int cont;
	int c;
	c=2;
	for(int j=0; j<col; j++){
		cont=0;
		for(int i=0; i<ren; i++){
			if(mat[i][c]==0){
				cont++;
			}
		}
		if(cont==5){
			band=true;
			break;
		}
	}
	
	return band;
}


void bingovertical(char* alias1, char*alias2){
	int **tablero1;
	int **tablero2;
	int suma1=0, suma2=0;

	tablero1=pedirespacio(5,5);
	tablero2=pedirespacio(5,5);
	
	llenarvertical(tablero1,5,5);
	llenarvertical(tablero2,5,5);
		
	int *bolsa= new int[100];
	for(int i=1; i<=100; i++){
		bolsa[i]=i;
	}
	
	shuffle(bolsa,100);
	
	bool vertical1= false, vertical2=false;
	int okv1[100], in1=0;
	int okv2[100], in2=0;
	
	
	for(int i=0; i<100; i++){
		system("cls");
		cout<<endl<<endl<<"Salio el numero: "<<bolsa[i]<< "								Han salido: " << i + 1  << " numeros" << endl;
		cout << endl;
		
		mostrar(tablero1,tablero2,5, 5,"BINGO VERTICAL",alias1,alias2,okv1,in1,okv2,in2);
		
		
		if(revisarvertical(bolsa[i],tablero1,5,5,okv1,in1)){
			cout << endl;
			textcolor(2);
			cout << endl;
			cout << bolsa[i] << " se encuentra en el tablero de "<<alias1  <<endl;
		}
		if(revisarvertical(bolsa[i],tablero2,5,5,okv2,in2)){
			cout << endl;
			textcolor(3);
			cout << endl;
			cout << bolsa[i]<< " se encuentra en el tablero de "<<alias2<<endl;
		}
		
		if(ganarvertical(tablero1,5,5)){
			cout << endl;
			textcolor(6);
			cout << alias1 << " gano!" << endl;			
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int j=0;j<in1;j++) {
				cout<<okv1[j]<<" ";
				suma1+=okv1[j];
			}
			cout<<endl;
			cout<<endl<<"Total de Puntos: "<<suma1;
			cout << endl;
			break;
		}
		
		if(ganarvertical(tablero2,5,5)){
			cout << endl;
			textcolor(6);
			cout <<  alias2 << " gano!" << endl;
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int j=0; j<in2; j++){
				cout<<okv2[j]<<" ";
				suma2+=okv2[j];
			}
			cout<<endl;
			cout<<endl<<"Total de Puntos: "<<suma2;
			cout << endl;
			break;
		}
		textcolor(15);
		Sleep(VEL);
	}
	cout<<endl;
	
}
