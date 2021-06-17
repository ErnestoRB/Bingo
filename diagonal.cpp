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

bool revisardiagonal(int num, int **m,int dim,int *vec, int &indice){

	for(int j=0; j<dim; j++){
		if(m[j][j]==num){
			vec[indice]=num;
			indice++;
			m[j][j]=0;
			return true;
		}
		if(m[j][dim-1-j]==num){
			vec[indice]=num;
			indice++;
			m[j][dim-1-j]=0;
			return true;
		}
	}
	return false;
}



bool ganardiagonal(int**mat, int dim) {
	bool diag1, diag2;
	diag1=diag2=true;
	for(int j=0;j<dim;j++){
		if(mat[j][j]!=0){
			diag1=false;
		}
		if(mat[j][dim-1-j]!=0){
			diag2=false;
		}
	}
	return diag2 || diag1;
	
}


void bingodiagonal(char* alias1, char*alias2){
	int **tablero1;
	int **tablero2;
	int *val1,*val2;
	int dim,diagonal;
	int suma1=0, suma2=0;
	dim = 3 + rand()%(6-3+1);
	diagonal = 1 + rand()%(2-1+1);//Numero 1:Diagonal Izquierda a Derecha, Numero 2:Diagonal derecha a Izquierda
	
	tablero1=pedirespacio(dim,dim);
	tablero2=pedirespacio(dim,dim);
	
	llenardiagonal(tablero1,dim,dim);
	llenardiagonal(tablero2,dim,dim);
		

	int *bolsa= new int[100];
	for(int i=0; i<99; i++){
		bolsa[i]=i+1;
	}
	shuffle(bolsa,99);
	
	
	int okv1[99], in1=0;
	int okv2[99], in2=0;
	
		for(int i=0; i<99; i++){
			system("cls");
			gotoxy(0,0);
			cout<<"Salio el numero: "<<bolsa[i]<< "								Han salido: " << i + 1  << " numeros" << endl;
			cout << "Han salido los numeros: ";
			for(int j=0;j<i;j++){
				cout << bolsa[j] << " ";
			}
			
			mostrar(tablero1,tablero2,dim, dim,"BINGO DIAGONAL",alias1,alias2, okv1,in1,okv2,in2);
			
			
			if(revisardiagonal(bolsa[i],tablero1,dim,okv1,in1)){
				cout << endl;
				textcolor(2);
				cout << bolsa[i] << " se encuentra en el tablero de "<<alias1 <<endl;
			}
			if(revisardiagonal(bolsa[i],tablero2,dim,okv2,in2)){
				cout << endl;
				textcolor(3);
				cout << bolsa[i]<< " se encuentra en el tablero de "<<alias2<<endl;
			}
			
			if(ganardiagonal(tablero1,dim)){
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
			
			if(ganardiagonal(tablero2,dim)){
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
	
}
