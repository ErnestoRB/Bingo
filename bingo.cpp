/*
Proyecto Final 2021
BINGO!
Juan Miguel Casillas Romo
Iker Jimenez Tovar
Sergio Fernando Marentes Jimenez
Ernesto Rodrigo Ramirez Briano 
*/

// 07/06/21

# include "bingo.h"
# include <windows.h>
# include <ctime>


using namespace std;

int main(){
	system("mode con cols=120 lines=40");
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
	fontcolor(13,13);
	for(int lines=0;lines<40;lines++){
		for(int cols=0;cols<120;cols++){

			if(lines==1 || lines==38){
				gotoxy(cols,lines);
				cout << " ";
			}
			if(cols==1 || cols==118){
				gotoxy(cols,lines);
				cout << " ";
			}
		}
	}
	textcolor(15);
	/* for(int lines=0;lines<40;lines++){
		fontcolor(7,7);
		gotoxy(0,lines);
		cout << " ";
		fontcolor(14,14);
		gotoxy(118,lines);
		cout << " ";
	} */

	
	int x=30, y=15;
	uaalogo(); //Logo UAA
	gotoxy(x, y+1);
	cout << "UNIVERSIDAD AUTONOMA DE AGUASCALIENTES" << endl;
	gotoxy(x, y+2);
	cout << "ISC              2B";
	gotoxy(x, y+3);
	cout << "BINGO!";
	gotoxy(x, y+4);
	cout << "Profesora: Georgina Salazar Partida";
	gotoxy(x, y+5);
	cout << "INTEGRANTES";
	textcolor(4);
	gotoxy(x, y+6);
	cout << "Ernesto Rodrigo Ramirez Briano";
	gotoxy(x, y+7);
	textcolor(1);
	cout << "Iker Jimenez Tovar";
	gotoxy(x, y+8);
	textcolor(14);
	cout << "Sergio Fernando Marentes Jimenez";
	gotoxy(x, y+9);
	textcolor(10);
	cout << "Juan Miguel Casillas Romo";
	textcolor(15);
	gotoxy(x, y+15);
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
	int x = 35, y = 4;
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
	fontcolor(14,14);
	for(int lines=0;lines<40;lines++){
		for(int cols=0;cols<120;cols++){

			if(lines==1 || lines==38){
				gotoxy(cols,lines);
				cout << " ";
			}
			if(cols==1 || cols==118){
				gotoxy(cols,lines);
				cout << " ";
			}
		}
	}

	int x = 2, y = 5;
	textcolor(1);
	gotoxy(x, y);
	cout << R"(__/\\\\\\\\\\\\\\______/\\\\\\\\\\\____/\\\\\\______/\\\______/\\\\\\\\\\\\\_________/\\\\\________)";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+1);
	textcolor(2);
	cout << R"( _\/\\\//////////\\\___\/////\\\///____\/\\\\\\\_____/\\\____/\\\///////////________/\\\///\\\______)";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+2);
	textcolor(3);
	cout << R"(  _\/\\\________\/\\\_______\/\\\_______\/\\\\\\\\___\/\\\___\/\\\_________________/\\\/__\///\\\____)";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+3);
	textcolor(4);
	cout << R"(   _\/\\\\\\\\\\\\\\/________\/\\\_______\/\\\\\\\\\__\/\\\___\/\\\_____/\\\\\\\___/\\\______\//\\\___)";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+4);
	textcolor(5);
	cout << R"(    _\/\\\/////////\\_________\/\\\_______\/\\\\\\\\\\\\\\\\___\/\\\____\/////\\\__\/\\\_______\/\\\___)";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+5);
	textcolor(6);
	cout << R"(      _\/\\\/////////\\_________\/\\\_______\/\\\\\\\\\\\\\\\\___\/\\\____\/////\\\__\/\\\_______\/\\\___)";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+6);
	textcolor(7);
	cout << R"(       _\/\\\________\/\\\_______\/\\\_______\/\\\///\/\\\\\\\\___\/\\\________\/\\\__\//\\\______/\\\____)";
	Sleep(SLEEPBINGO);
	gotoxy(x, y+7);
	textcolor(8);
	cout << R"(        _\/\\\\\\\\\\\\\/______/\\\\\\\\\\\___\/\\\____\//\\\\\\___\//\\\\\\\\\\\\\/______\///\\\\\/_______)";
	textcolor(9);
	gotoxy(x, y+8);
	cout << R"(         _\/////////////_______\///////////____\///______\//////_____\/////////////__________\/////_________)";
	textcolor(10);
	Sleep(SLEEPBINGO);
	gotoxy(35, 25);
	textcolor(15);
	cout << "Version 1.0						    ISC 2B";
	gotoxy(20, 25);
	system("pause");

	/*int x = 30, y = 1;
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
	system("pause");*/
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
				if (capturadas == true){
					bingodiagonal(alias1,alias2);
				}
				else{
					cout << "Primero captura alias!" << endl;
				}
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
				do{
					do{
						system("cls");
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
							string alias;
							cout << endl << "Que alias quieres buscar?"<<endl;
							cin >> alias;
							estadisticasUsuario(alias);
							system("pause");
							system("cls");
							break;
						}
						case 3:{
							estadisticasHorizontal();
							system("pause");
							system("cls");
							break;
						}
						case 4:{
							estadisticasCompleta();
							system("pause");
							system("cls");
							break;
						}
						case 5:{
							estadisticasDiagonal();
							system("pause");
							system("cls");
							break;
						}
						case 6:{
							estadisticasVertical();
							system("pause");
							system("cls");
							break;
						}
						case 7:{
							maximosGanadores();
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
	fontcolor(4,4);
	for(int lines=0;lines<40;lines++){
		for(int cols=0;cols<120;cols++){

			if(lines==1 || lines==38){
				gotoxy(cols,lines);
				cout << " ";
			}
			if(cols==1 || cols==118){
				gotoxy(cols,lines);
				cout << " ";
			}
		}
	}
	int n = 1;
	gotoxy(5,8);
	textcolor(10);
	cout << "Bingo!";
	textcolor(n+1);
	gotoxy(5,11);
	cout <<  "Ingresar alias....................1";
	textcolor(n+2);
	gotoxy(5,12);
	cout <<  "Modo: Una linea horizontal........2";
	textcolor(n+3);
	gotoxy(5,13);
	cout <<  "Modo: Toda la carta...............3";
	textcolor(n+4);
	gotoxy(5,14);
	cout <<  "Modo: Una diagonal principal......4";
	textcolor(n+5);
	gotoxy(5,15);
	cout << "Modo: Vertical....................5";
	textcolor(n+1);
	gotoxy(5,16);
	cout <<  "Estadisticas......................6";
	textcolor(n+2);
	gotoxy(5,17);
	cout << "Salir.............................7";
	textcolor(15);
	gotoxy(5,20);
	cout << "Inserte opcion: ";
}

void submenu(){
	fontcolor(9,9);
	for(int lines=0;lines<40;lines++){
		for(int cols=0;cols<120;cols++){

			if(lines==1 || lines==38){
				gotoxy(cols,lines);
				cout << " ";
			}
			if(cols==1 || cols==118){
				gotoxy(cols,lines);
				cout << " ";
			}
		}
	}
	int n = 1;
	gotoxy(5,8);
	fontcolor(0,15);
	cout << "Estadisticas";
	textcolor(n+1);
	gotoxy(5,11);
	cout << "Estadisticas registradas...........1";
	textcolor(n+2);
	gotoxy(5,12);
	cout << "Estadisticas por jugador...........2";
	textcolor(n+3);
	gotoxy(5,13);
	cout << "Estadisticas modo horizontal.......3";
	textcolor(n+4);
	gotoxy(5,14);
	cout << "Estadisticas modo carta completa...4";
	textcolor(n+5);
	gotoxy(5,15);
	cout << "Estadisticas modo diagonal.........5";
	textcolor(n+1);
	gotoxy(5,16);
	cout << "Estadisticas modo vertical.........6";
	textcolor(n+2);
	gotoxy(5,17);
	cout << "Maximo ganador por modo............7";
	textcolor(n+3);
	gotoxy(5,18);
	cout << "Volver.............................8";
	textcolor(1);
	gotoxy(5,19);
	cout << "Inserte opcion: ";
}

char *captura(string texto){
	char *alias = new char[100];
	bool band = false;
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
	return alias;
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





void mostrar(int **t1, int **t2, int ren, int col, string titulo, char *alias1, char *alias2, int*v1, int tv1,int*v2,int tv2){
    int xt1=5, xt2=60, y=15;
    gotoxy(30,5);
    cout << titulo;
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
			textcolor(2);
            gotoxy(xt1, y/2+1);
            cout << alias1;
            gotoxy(xt1, y/2+2);
            cout << "Aciertos: "<<tv1;
            gotoxy(xt1, y/2+3);
            cout << "Han salido: ";
            for(int i=0;i<tv1;i++){
            	cout << v1[i] <<" ";
			}
            gotoxy((j*4)+(xt1),(i*2)+y);
			if(t1[i][j]==0){
				fontcolor(15,4);
				cout << "X"<<endl;
			} else {
				textcolor(15);
				cout << t1[i][j];
			}
           

			textcolor(3);
            gotoxy(xt2, y/2+1);
            cout << alias2;
            gotoxy(xt2, y/2+2);
            cout << "Aciertos: "<<tv2;
            gotoxy(xt2, y/2+3);
            cout << "Han salido: ";
            for(int i=0;i<tv2;i++){
            	cout << v2[i] <<" ";
			}
            gotoxy((j*4)+(xt2),(i*2)+y);
            if(t2[i][j]==0){
				fontcolor(15,4);
				cout << "X"<<endl;
			} else {	
				textcolor(15);			
				cout << t2[i][j];
			}
        }
    }
	textcolor(14);
}

string mododejuego(int modo){
	switch(modo){
		case HORIZONTAL:
		return "Horizontal";
		break;
		case COMPLETA:
		return "C. Completa";
		break;
		case DIAGONAL:
		return "Diagonal";
		break;
		case VERTICAL:
		return "Vertical";
		break;
	}
	return "";
}


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



