# include "bingo.h"
#include <windows.h>

using std::cout;
using std::endl;

void cartacompleta(char *alias1, char *alias2){
	const int RENFULL = 3, COLFULL =9, MAX=100;
	int **tablero1, **tablero2, *valores1,*valores2;
	tablero1 = pedirespacio(RENFULL, COLFULL);
	valores1 = new int[RENFULL * COLFULL];
	tablero2 = pedirespacio(RENFULL, COLFULL);
	valores2 = new int[RENFULL * COLFULL];	
	int sumatoria1, sumatoria2;
	sumatoria1 = sumatoria2 = 0;

	llenarhorizontal(tablero1,RENFULL, COLFULL); //se manda a llenar con esta funcion porque este modo tambien tiene cuatro espacios por renglon
	llenarhorizontal(tablero2,RENFULL, COLFULL);
	
	int *bolsa = new int [MAX];
	for (int i=1; i<MAX; i++){
		bolsa[i] = i;
	}
	shuffle(bolsa, MAX);
	int cont1, cont2;
	cont1 = cont2 = 0;
	
	for(int i=0; i<MAX; i++){
		system("cls");
		cout << "Salio el numero: " << bolsa[i] << "								Han salido: " << i + 1  << " numeros" << endl;
		cout << endl;
		mostrar(tablero1, tablero2, RENFULL, COLFULL , "BINGO CARTA COMPLETA", alias1, alias2,valores1,cont1,valores2,cont2);
		cout << endl;
		
		if(contiene(tablero1, RENFULL, COLFULL, bolsa[i])){
			cout << endl;
			textcolor(2);
			cout << bolsa[i] << " se encuentra en el tablero de "<< alias1 <<endl;
			valores1[cont1] = bolsa[i];
			cont1++;
		}
		
		if(contiene(tablero2, RENFULL, COLFULL, bolsa[i])){
			cout << endl;
			textcolor(3);
			cout << bolsa[i] << " se encuentra en el tablero de "<< alias2 << endl;
			valores2[cont2] = bolsa[i];
			cont2++;
		}
		
		if(revisarcompleto(tablero1, RENFULL, COLFULL)){
			Beep(523, 200);
			Beep(587, 400);
			Beep(659, 800);
			cout << endl;
			textcolor(6);
			cout << alias1 << " gano!" << endl;			
			cout << "Todos los numeros que salieron en su carta: "<<endl;
			for(int j=0; j<cont1; j++){
				sumatoria1 += valores1[j];
				cout << valores1[j] << " ";
			}
			cout << endl << "Total de puntos: " << sumatoria1;
			cout << endl;
			Estadisticas stat;
			strcpy(stat.alias,alias1);
			strcpy(stat.fecha,obtenerhora());
			stat.modo = COMPLETA;
			stat.puntuacion = sumatoria1;
			guardar(stat);
			cout << endl;
			break;
		}
		if(revisarcompleto(tablero2, RENFULL, COLFULL)){
			Beep(523, 200);
			Beep(587, 400);
			Beep(659, 800);
			cout << endl;
			textcolor(6);
			cout <<  alias2 << " gano!" << endl;
			cout << "Todos los numeros que salieron en su carta: "<< endl;
			for(int j=0; j<cont2; j++){
				sumatoria2 += valores2[j];
				cout << valores2[j] << " ";
			}
			cout << endl << "Total de puntos: " << sumatoria2;
			cout << endl;
			Estadisticas stat;
			strcpy(stat.alias,alias2);
			strcpy(stat.fecha,obtenerhora());
			stat.modo = COMPLETA;
			stat.puntuacion = sumatoria2;
			guardar(stat);
			cout << endl;
			break;
		}
		textcolor(15);
		Sleep(VEL);
	}
	system("pause");
	system("cls");
	menu();	
}

bool revisarcompleto(int **tablero, int ren, int col){
	int cont = 0;
	for(int i=0; i<ren; i++){
		for(int j=0; j<col; j++){
			if(tablero[i][j] == 0){
				cont++;
			}
			else{
				break;
			}
		}
	}
	if (cont == 27){
		return true;
	}
	return false;
}

