/*
Proyecto Final 2021
BINGO!
Juan Miguel Casillas Romo
Iker Jimenez Tovar
Sergio Fernando Marentes Jimenez
Ernesto Rodrigo Ramirez Briano 
*/

// 07/06/21

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
#define ARCHIVO "estadisticas.dat"

using namespace std;
using std::cout;

enum MODOS {
	HORIZONTAL=1,COMPLETA,DIAGONAL,VERTICAL
};

struct Estadisticas {
	char alias[15];
	MODOS modo;
	int puntuacion;
	char fecha[25];
};


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
void mostrar(int **t1, int **t2, int ren, int col, string titulo, char *alias1, char *alias2, int*v1, int tv1,int*v2,int tv2);
bool revisartablero(int **tablero, int ren, int col);
bool contiene(int **tablero, int ren, int col, int num);
void bingohorizontal(char*, char*);
void setWindowTitle(string texto);
int **pedirespacio(int ren, int col);
void shuffle(int *array, int n);
void cartacompleta(char *alias1, char *alias2);
bool revisarcompleto(int **tablero, int ren, int col);
void bingodiagonal(char* alias1, char*alias2);
bool revisardiagonal(int num, int **m,int ren, int col,int *vec, int &indice);
bool ganardiagonal(int **mat,int ren,int col);
void llenardiagonal(int **matriz, int ren, int col);
void bingovertical(char* alias1, char*alias2);
bool revisarvertical(int num, int **m,int ren, int col,int *vec, int &indice);
bool ganarvertical(int **mat,int ren,int col);
void llenarvertical(int **matriz, int ren, int col);
void guardar(Estadisticas stats);
void mostrarEstadisticas();
void estadisticasUsuario(string nombre);
char *obtenerhora();


int main(){
	srand(time(NULL));
	system("cls");// garantiza una pantalla limpia si se ejecuta desde cmd o PowerShell (evita sobreescritura del buffer anterior)
	mainmenu(); //Inicio de la presentacion
	system("cls");
	options(); //muestra el menu de opciones
	return 0;
}

void mainmenu(){ //Menu de inicio, se muestran datos del equipo y se incia el juego
	cout << obtenerhora();
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
			//////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 5:{
				if (capturadas == true){
					bingovertical(alias1, alias2);
				}
				else{
					cout << "Primero captura alias!" << endl;
				}
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
							mostrarEstadisticas();
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
	cout << endl << "Modo: Vertical....................5";
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
	cout << endl << "Estadisticas modo vertical.........6";
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
	//char nomarch[30] = "estadisticas.txt";
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
	/*if (band == true){	//Guarda los alias en un archivo de texto
		file.open(nomarch,ios::out|ios::app); 
		file << alias;
		file << endl;
		file.close();
	}*/
	return alias;
}

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
		cout<<endl<<endl<<"Salio el numero: "<<bolsa[i];
		cout << endl;
		
		//mostrar(tablero1,tablero2,dim, dim,"BINGO DIAGONAL",alias1,alias2);
		
		
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
			cout << endl;
			textcolor(2);
			cout << alias1 << " gano!" << endl;			
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int j=0;j<in1;j++) {
				cout<<okv1[j]<<" ";
			}
			cout << endl;
			break;
		}
		
		if(ganardiagonal(tablero2,dim,dim)){
			cout << endl;
			textcolor(6);
			cout <<  alias2 << " gano!" << endl;
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int j=0; j<in2; j++){
				cout<<okv2[j]<<" ";
			}
			cout << endl;
			break;
		}
		textcolor(15);
		Sleep(VEL);
	}
	cout<<endl;
}

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
				cout<<endl<<endl<<"El "<<num<<" esta en el tablero. "<<endl;
				vec[indice]=num;
				indice++;
				m[i][c]=0;
			}
		}
	}
	return false;
}

bool ganarvertical(int **mat,int ren,int col){
	bool band=false;
	int cont;
	int suma;
	int c;
	c=2;
	for(int j=0; j<col; j++){
		cont=0;
		suma=0;
		for(int i=0; i<ren; i++){
			if(mat[i][c]==0){
				suma=suma+mat[i][j];
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
	int *val1,*val2;
	
	tablero1=pedirespacio(5,5);
	tablero2=pedirespacio(5,5);
	
	llenarvertical(tablero1,5,5);
	llenarvertical(tablero2,5,5);
	
	
	

	int *bolsa= new int[100];
	for(int i=0; i<=100; i++){
		bolsa[i]=i;
	}
	shuffle(bolsa,100);
	
	bool vertical1= false, vertical2=false;
	int okv1[100], in1=0;
	int okv2[100], in2=0;
	
	
	for(int i=0; i<100; i++){
		system("cls");
		cout<<endl<<endl<<"Salio el numero: "<<bolsa[i];
		cout << endl;
		
		mostrar(tablero1,tablero2,5, 5,"BINGO VERTICAL",alias1,alias2,okv1,in1,okv2,in2);
		
		
		if(revisarvertical(bolsa[i],tablero1,5,5,okv1,in1)){
			cout << endl;
			textcolor(2);
			cout << bolsa[i] << " se encuentra en el tablero de "<<alias1  <<endl;
		}
		if(revisarvertical(bolsa[i],tablero2,5,5,okv2,in2)){
			cout << endl;
			textcolor(3);
			cout << bolsa[i]<< " se encuentra en el tablero de "<<alias2<<endl;
		}
		
		if(ganarvertical(tablero1,5,5)){
			cout << endl;
			textcolor(2);
			cout << alias1 << " gano!" << endl;			
			cout << "Todos los numeros que salieron en su carta: "<<endl;

			for(int j=0;j<in1;j++) {
				cout<<okv1[j]<<" ";
			}
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
			}
			cout << endl;
			break;
		}
		textcolor(15);
		Sleep(VEL);
	}
	cout<<endl;
	
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


void mostrar(int **t1, int **t2, int ren, int col, string titulo, char *alias1, char *alias2, int*v1, int tv1,int*v2,int tv2){
    int xt1=5, xt2=60, y=10;
    gotoxy(20,2);
    cout << titulo;
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
			textcolor(2);
            gotoxy(xt1, 5);
            cout << alias1;
            gotoxy(xt1, 6);
            cout << "Aciertos: "<<tv1;
            gotoxy(xt1, 7);
            cout << "Han salido: ";
            for(int i=0;i<tv1;i++){
            	cout << v1[i] <<" ";
			}
            gotoxy((j*4)+(xt1),(i*2)+y);
            cout << t1[i][j];

			textcolor(3);
            gotoxy(xt2, 5);
            cout << alias2;
            gotoxy(xt2, 6);
            cout << "Aciertos: "<<tv2;
            gotoxy(xt2, 7);
            cout << "Han salido: ";
            for(int i=0;i<tv2;i++){
            	cout << v2[i] <<" ";
			}
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
 

 void shuffle(int *array, int n){
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

void guardar(Estadisticas estadistica){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::out|ios::app);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	fs.write((char*)(&estadistica),sizeof(Estadisticas));
	fs.close();	
}

void mostrarEstadisticas(){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::in);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	cout << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl;
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		cout << setw(20) << aux.alias;
		cout << setw(20) <<aux.modo;
		cout << setw(16) << aux.puntuacion;
		cout << setw(25) <<aux.fecha<<endl;
	}

	fs.close();
}

void estadisticasUsuario(string nombre){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::out|ios::app);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		if(nombre==aux.alias){
			cout << aux.alias<<endl;
			cout << aux.modo<<endl;
			cout << aux.puntuacion<<endl;
		}
	}

	fs.close();
}

void maximosGanadores(){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::out|ios::app);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	int mejorhorizontal=0, mejorcompleta=0, mejordiagonal=0, mejorvertical=0;
	/*while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		switch(aux.modo){
			case HORIZONTAL:
				if()
				break;
			case COMPLETA:
				break;
			case DIAGONAL:
				break;
			case VERTICAL:
				break;
		}
	}*/

	fs.close();
}

char *obtenerhora() {
	char *cadena = new char[25];
    time_t ahora = time(0);
	struct tm* localt = localtime(&ahora);
	strftime(cadena, 25,"%d/%m/%y %X",localt);
	//strftime(hora, htam,"%X",localt);
	return cadena;
}

