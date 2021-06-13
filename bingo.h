#ifndef BINGO_H
    #define BINGO_H
    #include <iostream>
    #include <cstring>
    #include <iomanip>
    #define SLEEPBINGO 200	//Tiempo que se tarda en mostrar la palabra "BINGO!"
    #define VEL 500 //tiempo de espera en partida
    #define WINDOW_TITLE_PREFIX "BINGO!"
    #define ARCHIVO "estadisticas.dat"

    using std::string;

    enum MODOS {
        HORIZONTAL=1,COMPLETA,DIAGONAL,VERTICAL
    };

    struct Estadisticas {
        char alias[15];
        MODOS modo;
        int puntuacion;
        char fecha[25];
    };

    void shuffle(int *array, int n);
    void gotoxy(int x, int y);
    void textcolor(int n);
    void mainmenu();
    void uaalogo();
    void bingologo();
    void options();
    void menu();
    void submenu();
    char *captura(string texto);
    string mododejuego(int modo);
    void mostrar(int **t1, int **t2, int ren, int col, string titulo, char *alias1, char *alias2, int*v1, int tv1,int*v2,int tv2);
    void llenarhorizontal(int** tablero, int ren, int col);
    bool revisarhorizontal(int **tablero, int ren, int col);
    void bingohorizontal(char*, char*);
    bool contiene(int **tablero, int ren, int col, int num);
    int **pedirespacio(int ren, int col);
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
    void estadisticasHorizontal();
    void estadisticasCompleta();
    void estadisticasDiagonal();
    void estadisticasVertical();
    void maximosGanadores();
    char *obtenerhora();
    void setWindowTitle(string texto);
#endif