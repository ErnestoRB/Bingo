# include "bingo.h"
#include <windows.h>
using std::cout;
using std::endl;

void llenardiagonal(int **matriz, int ren, int col){
	int *vec;
	vec=new int[99];
	for (int i=0; i<99; i++){
		vec[i]=i+1;
	}
	shuffle(vec,99);
	int *aux;
	aux= new int[ren];
	int inicio=0;
	int fin=ren;
	for (int r=0; r<ren; r++){
		int cont=0;
		for( int i=inicio; i<fin; i++){
			aux[cont]=vec[i];
			cont++;
		}
		shuffle(aux,ren);
		for(int c=0; c<col; c++){
			matriz[r][c]=aux[c];
		}
		inicio=fin;
		fin=fin+ren;
	}
}

bool revisardiagonal(int num, int **m,int ren, int col,int *vec, int &indice){
	
	for(int j=0; j<col; j++){
		for(int i=0; i<ren; i++){
			if(m[i][i]==num){
				cout<<endl<<endl<<"El "<<num<<" esta en el tablero. "<<endl;
				vec[indice]=num;
				indice++;
				m[i][i]=0;
			}
			
		}
	}
	return false;
}

bool ganardiagonal(int **mat,int ren,int col){
	bool band=false;
	int cont;
	int suma;

	for(int j=0; j<col; j++){
		cont=0;
		suma=0;
		for(int i=0; i<ren; i++){
			if(mat[i][i]==0){
				suma=suma+mat[i][j];
				cont++;
			}
		}
		if(cont==ren && cont==col){
			band=true;
			break;
		}
	}
	
	return band;
}



void bingodiagonal(char* alias1, char*alias2){
	int **tablero1;
	int **tablero2;
	int *val1,*val2;
	int dim;
	int suma1=0, suma2=0;
	dim = 3 + rand()%(6-3+1);
	
	tablero1=pedirespacio(dim,dim);
	tablero2=pedirespacio(dim,dim);
	
	llenardiagonal(tablero1,dim,dim);
	llenardiagonal(tablero2,dim,dim);
	
	
	

	int *bolsa= new int[100];
	for(int i=0; i<99; i++){
		bolsa[i]=i+1;
	}
	shuffle(bolsa,99);
	
	bool vertical1= false, vertical2=false;
	int okv1[99], in1=0;
	int okv2[99], in2=0;
	
	
	for(int i=0; i<99; i++){
		system("cls");
		cout<<endl<<endl<<"Salio el numero: "<<bolsa[i]<< "								Han salido: " << i + 1  << " numeros" << endl;
		cout << endl;
		
		mostrar(tablero1,tablero2,dim, dim,"BINGO DIAGONAL",alias1,alias2, okv1,in1,okv2,in2);
		
		
		if(revisardiagonal(bolsa[i],tablero1,dim,dim,okv1,in1)){
			cout << endl;
			textcolor(2);
			cout << bolsa[i] << " se encuentra en el tablero de "<<alias1 <<endl;
		}
		if(revisardiagonal(bolsa[i],tablero2,dim,dim,okv2,in2)){
			cout << endl;
			textcolor(3);
			cout << bolsa[i]<< " se encuentra en el tablero de "<<alias2<<endl;
		}
		
		if(ganardiagonal(tablero1,dim,dim)){
			Beep(523, 200);
			Beep(587, 400);
			Beep(659, 800);
			cout << endl;
			textcolor(2);
			cout << alias1 << " gano!" << endl;			
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int j=0;j<in1;j++) {
				cout<<okv1[j]<<" ";
				suma1+=okv1[j];
			}
				cout<<endl;
			cout<<endl<<"Total de Puntos: "<<suma1;
			cout << endl;
			
			Estadisticas stat;
			strcpy(stat.alias,alias1);
			strcpy(stat.fecha,obtenerhora());
			stat.modo = DIAGONAL;
			stat.puntuacion = suma1;
			guardar(stat);
			cout << endl;
			break;
		}
		
		if(ganardiagonal(tablero2,dim,dim)){
			Beep(523, 200);
			Beep(587, 400);
			Beep(659, 800);
			cout << endl;
			textcolor(6);
			cout <<  alias2 << " gano!" << endl;
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int j=0; j<in2; j++){
				cout<<okv2[j]<<" ";
				suma2+=okv2[j];
			}
			cout<<endl<<"Total de Puntos: "<<suma2;
			cout << endl;
			
			Estadisticas stat;
			strcpy(stat.alias,alias2);
			strcpy(stat.fecha,obtenerhora());
			stat.modo = DIAGONAL;
			stat.puntuacion = suma2;
			guardar(stat);
			cout << endl;
			break;
		}
		textcolor(15);
		Sleep(VEL);
	}
	cout<<endl;
}
