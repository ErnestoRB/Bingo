# include "bingo.h"
#include <windows.h>

using std::cout; 
using std::endl;

void bingohorizontal(char* alias1, char*alias2){
	const int H_REN=3, H_COL=9, H_MAX=100;
	int **tablero1, **tablero2, *valores1,*valores2;
	tablero1 = pedirespacio(H_REN,H_COL);
	valores1 = new int[H_REN*H_COL];
	tablero2 = pedirespacio(H_REN,H_COL);
	valores2 = new int[H_REN*H_COL];	

	llenarhorizontal(tablero1,H_REN,H_COL);
	llenarhorizontal(tablero2,H_REN,H_COL);
	
	int *bombo = new int [H_MAX];
	for(int n=1;n<H_MAX;n++){
		bombo[n]=n;
	}
	shuffle(bombo, H_MAX);
	int i1,i2; // contadores para la posici�n donde se almacenar�n los numeros que vayan saliendo en cada tablero
	i1=i2=0;
	for(int n=0;n<H_MAX;n++){
		system("cls");
		cout << "Salio el numero: " << bombo[n] << "\t Han salido "<<n<<" numeros"<< endl;
		cout << endl;
		
		mostrar(tablero1,tablero2,H_REN, H_COL,"BINGO HORIZONTAL",alias1,alias2,valores1,i1,valores2,i2);
		
		cout << endl;
		if(contiene(tablero1, H_REN, H_COL, bombo[n])){
			cout << endl;
			textcolor(2);
			cout << bombo[n] << " se encuentra en el tablero de "<<alias1  <<endl;
			valores1[i1] = bombo[n];
			i1++;
		}
		if(contiene(tablero2, H_REN, H_COL, bombo[n])){
			cout << endl;
			textcolor(3);
			cout << bombo[n]<< " se encuentra en el tablero de "<<alias2<<endl;
			valores2[i2] = bombo[n];
			i2++;
		}
		
		if(revisarhorizontal(tablero1,H_REN,H_COL)){
			cout << endl;
			textcolor(2);
			cout << alias1 << " gano!" << endl;			
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int i=0;i<i1;i++) {
				cout << valores1[i] << " ";
			}
			cout << endl;
			break;
		}
		if(revisarhorizontal(tablero2,H_REN,H_COL)){
			cout << endl;
			textcolor(6);
			cout <<  alias2 << " gano!" << endl;
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int i=0;i<i2;i++) {
				cout << valores2[i] << " ";
			}
			cout << endl;
			break;
		}
		textcolor(15);
		Sleep(VEL);
	}
}


bool revisarhorizontal(int **tablero, int ren, int col){
	for(int i=0;i<ren;i++){
		for(int j=0;j<col;j++){
			if(tablero[i][j]!=0) {
				break;
			}
			if(j==(col-1)){
				return true;
			}
		}
	}
	return false;
}


void llenarhorizontal(int** tablero, int ren, int col){
	// carta con 4 espacios en blanco por renglon!
	int *numeros;
	numeros = new int[100];
	for (int i=0; i<100; i++){
		numeros[i] = i + 1;
	}
	shuffle(numeros, 100);
	int *aux;
	aux = new int[9];
	
	int inicio = 0;
	int fin = 5;
	for (int r=0; r<ren; r++){
		for(int i=0; i<9; i++){
			aux[i] = 0;
		}
		int cont = 0;
		for (int i=inicio; i<fin; i++){
			aux[cont] = numeros[i];
			cont++;
		}
		shuffle(aux, 9);
		for (int c=0; c<col; c++){
			tablero[r][c] = aux[c];
		}
		inicio = fin;
		fin += 5;
	}
	delete []numeros;
}