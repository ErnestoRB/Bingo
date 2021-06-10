# include "bingo.h"
# include <windows.h>
# include <ctime>


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


char *obtenerhora() {
	char *cadena = new char[25];
    time_t ahora = time(0);
	struct tm* localt = localtime(&ahora);
	strftime(cadena, 25,"%d/%m/%y %X",localt);
	//strftime(hora, htam,"%X",localt);
	return cadena;
}
