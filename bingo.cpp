/*Proyecto Final 2021
BINGO!
Juan Miguel Casillas Romo
Iker Jimenez Tovar
Sergio Fernando Marentes Jimenez
Ernesto Rodrigo Ramirez Briano*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <iomanip>
#define SLEEPBINGO 200	//Tiempo que se tarda en mostrar la palabra "BINGO!"
#define VEL 500 //tiempo de espera en partida
#define WINDOW_TITLE_PREFIX "BINGO!"


using namespace std;
using std::cout;



void gotoxy(int x, int y);
void textcolor(int n);
void mainmenu();
void uaalogo();
void bingologo();
void options();
void menu();
void submenu();
char *captura(string texto);
void llenarhorizontal(int** tablero, int ren, int col);
void mostrar(int **t1, int **t2, int ren, int col, string titulo, char *alias1, char *alias2);
bool revisartablero(int **tablero, int ren, int col);
bool contiene(int **tablero, int ren, int col, int num);
void bingohorizontal(char*, char*);
void setWindowTitle(string texto);
int **pedirespacio(int ren, int col);
void shuffle(int *array, int n);
void cartacompleta(char *alias1, char *alias2);
bool revisarcompleto(int **tablero, int ren, int col);



int main(){
	system("cls");// garantiza una pantalla limpia si se ejecuta desde cmd o PowerShell (evita sobreescritura del buffer anterior)
	mainmenu(); //Inicio de la presentacion
	system("cls");
	options(); //muestra el menu de opciones
	return 0;
}

void mainmenu(){ //Menu de inicio, se muestran datos del equipo y se incia el juego
	setWindowTitle(WINDOW_TITLE_PREFIX);
	uaalogo(); //Logo UAA
	gotoxy(12, 10);
	cout << "UNIVERSIDAD AUTONOMA DE AGUASCALIENTES" << endl;
	gotoxy(20, 11);
	cout << "ISC              2B";
	gotoxy(27, 12);
	cout << "BINGO!";
	gotoxy(14, 13);
	cout << "Profesora: Georgina Salazar Partida";
	gotoxy(25, 15);
	cout << "INTEGRANTES";
	textcolor(4);
	gotoxy(14, 17);
	cout << "Ernesto Rodrigo Ramirez Briano";
	gotoxy(14, 18);
	textcolor(1);
	cout << "Iker Jimenez Tovar";
	gotoxy(14, 19);
	textcolor(14);
	cout << "Sergio Fernando Marentes Jimenez";
	gotoxy(14, 20);
	textcolor(10);
	cout << "Juan Miguel Casillas Romo";
	textcolor(15);
	gotoxy(14, 22);
	system("pause");
	system("cls");
	bingologo(); //Palabra "BINGO!"
	
}


void uaalogo(){
/*	LOGO
	***     **********
	***     ****    ***
	***             ***
	***      ***    ***
	***      **     ***
	***             ***
 	 ****   ****    ***
  	  **********    ***
*/
	int x = 21, y = 0;
	gotoxy(x, y+1);
	textcolor(1);
	cout << "*"; textcolor(7); cout << "**     *****"; textcolor(1); cout << "***** " << endl;
	gotoxy(x, y+2);
	cout << "*"; textcolor(7); cout << "**     ****   **"; textcolor(1); cout << "** " << endl;
	gotoxy(x, y+3);
	cout << "*"; textcolor(7); cout << "**             **"; textcolor(1); cout << "*" << endl;
	gotoxy(x, y+4);
	cout << "*"; textcolor(7); cout << "**      "; textcolor(14); cout << "**"; textcolor(4); cout << "*"; textcolor(7); cout << "    **"; textcolor(1); cout << "*" << endl;
	gotoxy(x, y+5);
	cout << "*"; textcolor(7); cout << "**      "; textcolor(14); cout << "*"; textcolor(4); cout << "*"; textcolor(7); cout << "     **"; textcolor(1); cout << "*" << endl;
	gotoxy(x, y+6);
	cout << "*"; textcolor(7); cout << "**     "; textcolor(14); cout << "*"; textcolor(4); cout << "**     "; textcolor(7); cout << "**"; textcolor(1); cout << "*" << endl;
	gotoxy(x, y+7);
	cout << "*"; textcolor(7); cout << "**             **"; textcolor(1); cout << "*" << endl;
	gotoxy(x, y+8);
	cout << " **"; textcolor(7); cout << "**   ****    **"; textcolor(1); cout << "*" << endl;
	gotoxy(x, y+9);
	cout << "  *****"; textcolor(7); cout << "*****    **"; textcolor(1); cout << "*" << endl;
	textcolor(15);
	gotoxy(12, 10);
}

void bingologo(){
/*	
__/\\\\\\\\\\\\\\______/\\\\\\\\\\\____/\\\\\\______/\\\______/\\\\\\\\\\\\\_________/\\\\\________
 _\/\\\//////////\\\___\/////\\\///____\/\\\\\\\_____/\\\____/\\\///////////________/\\\///\\\______
  _\/\\\________\/\\\_______\/\\\_______\/\\\\\\\\___\/\\\___\/\\\_________________/\\\/__\///\\\____
   _\/\\\\\\\\\\\\\\/________\/\\\_______\/\\\\\\\\\__\/\\\___\/\\\_____/\\\\\\\___/\\\______\//\\\___
    _\/\\\/////////\\_________\/\\\_______\/\\\\\\\\\\\\\\\\___\/\\\____\/////\\\__\/\\\_______\/\\\___
     _\/\\\________\/\\\_______\/\\\_______\/\\\///\/\\\\\\\\___\/\\\________\/\\\__\//\\\______/\\\____
      _\/\\\________\/\\\_______\/\\\_______\/\\\___\//\\\\\\\___\/\\\________\/\\\___\///\\\__/\\\______
       _\/\\\\\\\\\\\\\/______/\\\\\\\\\\\___\/\\\____\//\\\\\\___\//\\\\\\\\\\\\\/______\///\\\\\/_______
        _\/////////////_______\///////////____\///______\//////_____\/////////////__________\/////_________      
*/
	int x = 30, y = 1;
	system("color 01");
	gotoxy(x, y);
	cout << "//////   /  //      /   ///////   /////////  //";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+1);
	system("color 02");
	cout << "******   *  **      *   *******   *********  **";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+2);
	system("color 03");
	cout << "*     *  *  * *     *  *      *   *       *  **";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+3);
	system("color 04");
	cout << "*     *  *  *  *    *  *          *       *  **";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+4);
	system("color 05");
	cout << "******   *  *   *   *  *          *       *  **";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+5);
	system("color 06");
	cout << "*     *  *  *    *  *  *    ****  *       *  **";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+6);
	system("color 07");
	cout << "*     *  *  *     * *  *       *  *       *  ";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+7);
	system("color 09");
	cout << "******   *  *      **   *******   *********  **";
	system("color 0D");
	Sleep(SLEEPBINGO);
	gotoxy(20, 10);
	textcolor(15);
	cout << "Version 1.0						    ISC 2B";
	gotoxy(20, 11);
	system("pause");
}

void options(){ //Menu de opciones
	int op, opc;
	char *alias1, *alias2;
	bool capturadas = false;
	do{
		
		menu(); //Menu 1
		cin >> op;
		Beep(370, 200); //Sonido de pulso (Frecuencia en Hz, Tiempo en milisegundos) 370 = F#4/Gb4
		system("cls");

		switch(op){
			case 1:{
				system("cls");
				capturadas=true;
				alias1 = captura("Inserte Alias #1: ");
				alias2 = captura("Inserte Alias #2: ");
				break;
			}
			case 2:{
				if(capturadas==true) {
					bingohorizontal(alias1,alias2);
				} else {
					cout << "Primero captura alias!"<<endl;
				}
				
				system("pause");
				system("cls");
				break;
			}
			case 3:{
				if (capturadas == true){
					cartacompleta(alias1, alias2);
				}
				else{
					cout << "Primero captura alias!" << endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 4:{
				cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl;
				system("pause");
				system("cls");
				break;
			}
			case 5:{
				cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl;
				system("pause");
				system("cls");
				break;
			}
			case 6: {
				system("cls");
				do{
					do{
						submenu(); //Menu de estadisticas
						cin >> opc;
						Beep(370, 200); //Sonido de pulso (Frecuencia en Hz, Tiempo en milisegundos) 370 = F#4/Gb4
						system("cls");
					}while (opc < 1 || opc > 8);
					switch (opc){
						case 1:{
							system("cls");
							cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl; break;
							system("pause");
							break;
						}
						case 2:{
							cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 3:{
							cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 4:{
							cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 5:{
							cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 6:{
							cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl;
							system("pause");
							system("cls");
							break;
						}
						case 7:{
							cout << endl << "FUNCION CORRESPONDIENTE AQUI" << endl;
							system("pause");
							system("cls");
							break;
						}
					}
				}while (opc != 8);
				break;
			}
			case 7: cout << "Fin del programa"; break;
		}
	}while (op != 7);
}

void menu(){
	int n = 1;
	cout << "Bingo!";
	textcolor(n+1);
	cout << endl << "Ingresar alias....................1";
	textcolor(n+2);
	cout << endl << "Modo: Una linea horizontal........2";
	textcolor(n+3);
	cout << endl << "Modo: Toda la carta...............3";
	textcolor(n+4);
	cout << endl << "Modo: Una diagonal principal......4";
	textcolor(n+5);
	cout << endl << "Modo: <PERSONALIZADO>.............5";
	textcolor(n+1);
	cout << endl << "Estadisticas......................6";
	textcolor(n+2);
	cout << endl << "Salir.............................7";
	textcolor(15);
	cout << endl << "Inserte opcion: ";
}

void submenu(){
	int n = 1;
	cout << "Estadisticas";
	textcolor(n+1);
	cout << endl << "Estadisticas registradas...........1";
	textcolor(n+2);
	cout << endl << "Estadisticas por jugador...........2";
	textcolor(n+3);
	cout << endl << "Estadisticas modo horizontal.......3";
	textcolor(n+4);
	cout << endl << "Estadisticas modo carta completa...4";
	textcolor(n+5);
	cout << endl << "Estadisticas modo diagonal.........5";
	textcolor(n+1);
	cout << endl << "Estadisticas modo <PERSONALIZADO>..6";
	textcolor(n+2);
	cout << endl << "Maximo ganador por modo............7";
	textcolor(n+3);
	cout << endl << "Volver.............................8";
	textcolor(15);
	cout << endl << "Inserte opcion: ";
}

char *captura(string texto){
	char *alias = new char[100];
	bool band = false;
	fstream file;
	char nomarch[30] = "estadisticas.txt";
	int i;
	do{
		cout << texto;
		fflush(stdin);
		cin.getline(alias,100);
		cin.clear();
		if (strlen(alias) >= 4 && strlen(alias) <= 12){
			if (isalpha(alias[0]) != 0){
				for (i=1; i<strlen(alias); i++){
					if (isalpha(alias[i]) != 0 || isdigit(alias[i]) != 0 || alias[i] == '_'){
						
					}
					else{
						textcolor(4);
						cout << "Algun caracter es invalido: '" << alias[i] << "'" << endl;
						cout << endl;
						textcolor(15);
						system("pause");
						system("cls");
						break;
					}
				}
				if (i == strlen(alias)){
					band = true;
					textcolor(10);
					cout << "Alias capturado correctamente!" << endl;;
					cout << endl;
					textcolor(15);
					system("pause");
					system("cls");
				}
			}
			else{
				textcolor(4);
				cout << "El primer caracter debe ser una letra" << endl;
				cout << endl;
				textcolor(15);
				system("pause");
				system("cls");
			}
		}
		else{
			textcolor(4);
			cout << "Longitud de alias incorrecta" << endl;
			cout << endl;
			textcolor(15);
			system("pause");
			system("cls");
		}
		
	}while (band == false);
	if (band == true){	//Guarda los alias en un archivo de texto
		file.open(nomarch,ios::out|ios::app); 
		file << alias;
		file << endl;
		file.close();
	}
	return alias;
}



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
	int i1,i2; // contadores para la posición donde se almacenarán los numeros que vayan saliendo en cada tablero
	i1=i2=0;
	for(int n=0;n<H_MAX;n++){
		system("cls");
		cout << "Salio el numero: " << bombo[n] << endl;
		cout << endl;
		
		mostrar(tablero1,tablero2,H_REN, H_COL,"BINGO HORIZONTAL",alias1,alias2);
		
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
		
		if(revisartablero(tablero1,H_REN,H_COL)){
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
		if(revisartablero(tablero2,H_REN,H_COL)){
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
		/* cout << endl << endl << "+++++++++++++++++++++++++++++++"<<endl; */
		Sleep(VEL);
	}
}

bool contiene(int **tablero, int ren, int col, int num){
	for(int i=0;i<ren;i++){
		for(int j=0;j<col;j++){
			if(tablero[i][j]==num){
				tablero[i][j] = 0;
				return true;
			}
		}
	}
	return false;
}

bool revisartablero(int **tablero, int ren, int col){
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


void mostrar(int **t1, int **t2, int ren, int col, string titulo, char *alias1, char *alias2){
    int xt1=5, xt2=60, y=10;
    gotoxy(20,2);
    cout << titulo;
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
			textcolor(2);
            gotoxy(xt1, 5);
            cout << alias1;
            gotoxy((j*4)+(xt1),(i*2)+y);
            cout << t1[i][j];

			textcolor(3);
            gotoxy(xt2, 5);
            cout << alias2;
            gotoxy((j*4)+(xt2),(i*2)+y);
            cout << t2[i][j];
        }
    }
}

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
		cout << "Salio el numero: " << bolsa[i] << "				Han salido: " << i + 1  << " numeros" << endl;
		cout << endl;
		mostrar(tablero1, tablero2, RENFULL, COLFULL , "BINGO CARTA COMPLETA", alias1, alias2);
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
			cout << endl;
			textcolor(6);
			cout << alias1 << " gano!" << endl;			
			cout << "Todos los numeros que salieron en su carta: "<<endl;
			for(int j=0; j<cont1; j++){
				sumatoria1 += valores2[j];
				cout << valores1[j] << " ";
			}
			cout << endl << "Total de puntos: " << sumatoria1;
			cout << endl;
			break;
		}
		if(revisarcompleto(tablero2, RENFULL, COLFULL)){
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
			break;
		}
		textcolor(15);
		Sleep(VEL);
	}
	system("pause");
	system("cls");
	menu();	
}

/* 
void imprimirtablero(int **tablero, int ren, int col) {
	for(int i=0;i<ren;i++){
		for(int j=0;j<col;j++){
			cout << setw(4) << setfill(' ');
			if(tablero[i][j]==0) {
				cout << 'X';
			} else {
				
				cout << tablero[i][j];
			}
								
		}
		cout <<endl;
	}
} */


int **pedirespacio(int ren, int col)
{
	int **aux;
	aux = new int *[ren];
	for(int i=0;i<ren;i++){
		aux[i] = new int[col];
	}
	return aux;
}
 

 void shuffle(int *array, int n) {
	if(n > 1) {
		int i;
		for(i=0;i<n-1;i++){
			int j = i + rand() / (RAND_MAX /  (n-i)+1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}


void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void textcolor(int n){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n); 
}

void setWindowTitle(string texto){
	string s = "title " + texto;
	system(s.c_str());
}


