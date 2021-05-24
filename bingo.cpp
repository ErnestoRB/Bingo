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
#define SLEEPBINGO 200	//Tiempo que se tarda en mostrar la palabra "BINGO!"

using namespace std;

void gotoxy(int x, int y);
void textcolor(int n);
void mainmenu();
void uaalogo();
void bingologo();
void options();
void menu();
void submenu();
char *captura(string texto);


int main(){
	mainmenu(); //Inicio de la presentacion
	system("cls");
	options(); //muestra el menu de opciones
	return 0;
}

void mainmenu(){ //Menu de inicio, se muestran datos del equipo y se incia el juego
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
/*	//////   /  //      /   ///////   /////////  //
	******   *  **      *   *******   *********  **
	*     *  *  * *     *  *      *   *       *  **
	*     *  *  *  *    *  *          *       *  **
	******   *  *   *   *  *          *       *  **
	*     *  *  *    *  *  *    ****  *       *  **
	*     *  *  *     * *  *       *  *       *  
	******   *  *      **   *******   *********  **
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
	do{
		do{
			menu(); //Menu 1
			cin >> op;
			Beep(370, 200); //Sonido de pulso (Frecuencia en Hz, Tiempo en milisegundos) 370 = F#4/Gb4
			system("cls");
		}while (op < 1 || op > 7);
		switch(op){
			case 1:{
				system("cls");
				char *alias1, *alias2;
				alias1 = captura("Inserte Alias #1: ");
				alias2 = captura("Inserte Alias #2: ");
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
	char *alias = new char[15];
	bool band = false;
	fstream file;
	char nomarch[30] = "estadisticas.txt";
	int i;
	do{
		cout << texto;
		cin >> alias;
		if (strlen(alias) >= 4 && strlen(alias) <= 12){
			if (isalpha(alias[0]) != 0){
				for (i=1; i<strlen(alias); i++){
					if (isalpha(alias[i]) != 0 || isdigit(alias[i]) != 0 || alias[i] == '_'){
						
					}
					else{
						textcolor(4);
						cout << "Algun caracter es invalido: " << alias[i] << endl;
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
