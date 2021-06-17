# include "bingo.h"
# include <fstream>

using namespace std;

void guardar(Estadisticas estadistica){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::out|ios::app);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	fs.write((char*)(&estadistica),sizeof(Estadisticas));
	cout << endl << "Se guardo estadistica del jugador "<< estadistica.alias<<endl;
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
	fontcolor(0,4);
	cout << left << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl;
	textcolor(15);
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		cout << setw(20) << aux.alias;
		cout << setw(20) << mododejuego(aux.modo);
		cout << setw(16) << aux.puntuacion;
		cout << setw(25) <<aux.fecha<<endl;
	}

	fs.close();
}

void estadisticasHorizontal(){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::in);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	fontcolor(0,4);
	cout << left <<setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl;
	textcolor(15);
	bool existe=false;
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		if(aux.modo==HORIZONTAL){
			cout << setw(20) << aux.alias;
			cout << setw(20) << mododejuego(aux.modo);
			cout << setw(16) << aux.puntuacion;
			cout << setw(25) <<aux.fecha<<endl;
			existe=true;
		}		
	}
	if(!existe){
		cout << endl << "No hay registros! ):" <<endl;
	}

	fs.close();
}

void estadisticasCompleta(){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::in);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	textcolor(2);
	cout << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl;
	textcolor(15);
	bool existe=false;
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		if(aux.modo==COMPLETA){
			cout << setw(20) << aux.alias;
			cout << setw(20) << mododejuego(aux.modo);
			cout << setw(16) << aux.puntuacion;
			cout << setw(25) <<aux.fecha<<endl;
			existe=true;
		}		
	}
	if(!existe){
		cout << endl << "No hay registros! ):" <<endl;
	}

	fs.close();
}

void estadisticasDiagonal() {
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::in);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	textcolor(2);
	cout << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl;
	textcolor(15);
	bool existe=false;
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		if(aux.modo==DIAGONAL){
			cout << setw(20) << aux.alias;
			cout << setw(20) << mododejuego(aux.modo);
			cout << setw(16) << aux.puntuacion;
			cout << setw(25) <<aux.fecha<<endl;
			existe=true;
		}		
	}
	if(!existe){
		cout << endl << "No hay registros! ):" <<endl;
	}

	fs.close();
}

void estadisticasVertical() {
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::in);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	fontcolor(0,4);
	cout << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl;
	textcolor(15);
	bool existe=false;
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		if(aux.modo==VERTICAL){
			cout << setw(20) << aux.alias;
			cout << setw(20) << mododejuego(aux.modo);
			cout << setw(16) << aux.puntuacion;
			cout << setw(25) <<aux.fecha<<endl;
			existe=true;
		}		
	}
	if(!existe){
		cout << endl << "No hay registros! ):" <<endl;
	}

	fs.close();
}


void estadisticasUsuario(string nombre){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::in);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	bool existe=false;
	fontcolor(0,4);
	cout << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl;
	textcolor(15);
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		if(nombre==aux.alias){
			cout << setw(20) << aux.alias;
			cout << setw(20) << mododejuego(aux.modo);
			cout << setw(16) << aux.puntuacion;
			cout << setw(25) << aux.fecha<<endl;
			existe = true;
		}
	}
	if(!existe){
		cout << endl << "No hay registros de ese alias"<<endl;
	}

	fs.close();
}

void maximosGanadores(){
	fstream fs;
	fs.open(ARCHIVO,ios::binary|ios::in);
	if(!fs){
		cout << "No se pudo abrir"<<endl;
		return;
	}
	Estadisticas aux;
	struct Ganador {
		string nombre;
		int veces=0;
		MODOS modo;
	} distintos[100];
	int distintos_cont=0;
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		bool encontrado=false;
		for(int i=0;i<=distintos_cont;i++){ // recorre el registro de distintos para ver si se repite el nombre
			if(aux.alias==distintos[i].nombre && aux.modo == distintos[i].modo){
				distintos[i].veces++;
				encontrado = true;
			}
		}
		if(!encontrado){ // si no esta repetido entonces es distinto a los demas y se debe registrar
			distintos[distintos_cont].nombre = aux.alias;
			distintos[distintos_cont].veces++;
			distintos[distintos_cont].modo = aux.modo;
			distintos_cont++;
		}

	}


	int mejorhorizontal=0, mejorcompleta=0, mejordiagonal=0, mejorvertical=0;
	int poshorizontal=0, poscompleta=0, posdiagonal=0, posvertical=0;
	int n=0;
	for(int i=0;i<=distintos_cont;i++){
		switch(distintos[i].modo){
			case HORIZONTAL:
				if(distintos[i].veces>mejorhorizontal){
					mejorhorizontal=distintos[i].veces;
					poshorizontal=i;
				}
				break;
			case COMPLETA:
				if(distintos[i].veces>mejorcompleta){
					mejorcompleta=distintos[i].veces;
					poscompleta=i;
				}
				break;
			case DIAGONAL:
				if(distintos[i].veces>mejordiagonal){
					mejordiagonal=distintos[i].veces;
					posdiagonal=i;
				}
				break;
			case VERTICAL:
				if(distintos[i].veces>mejorvertical){
					mejorvertical=distintos[i].veces;
					posvertical=i;
				}
				break;
		}
	}

	/* while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		switch(aux.modo){
			case HORIZONTAL:
				if(aux.puntuacion>mejorhorizontal){
					mejorhorizontal=aux.puntuacion;
					poshorizontal=n;
				}
				break;
			case COMPLETA:
				if(aux.puntuacion>mejorcompleta){
					mejorcompleta=aux.puntuacion;
					poscompleta=n;
				}
				break;
			case DIAGONAL:
				if(aux.puntuacion>mejordiagonal){
					mejordiagonal=aux.puntuacion;
					posdiagonal=n;
				}
				break;
			case VERTICAL:
				if(aux.puntuacion>mejorvertical){
					mejorvertical=aux.puntuacion;
					posvertical=n;
				}
				break;
		}
		n++;
	} */
	
	
	fontcolor(0,4);
	cout << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Veces Ganadas"<<endl <<endl;
	fontcolor(15,1);
	if(mejorhorizontal>0){
		cout << setw(20) << distintos[poshorizontal].nombre << setw(20)<<mododejuego(distintos[poshorizontal].modo)<<setw(16)<<distintos[poshorizontal].veces<<endl;
	} else {
		textcolor(4);
		cout << "No hay registros para modo de juego " << mododejuego(HORIZONTAL)<<endl;
	}
	fontcolor(15,2);
	if(mejorcompleta>0){
		cout << setw(20) << distintos[poscompleta].nombre << setw(20)<<mododejuego(distintos[poscompleta].modo)<<setw(16)<<distintos[poscompleta].veces<<endl;
	} else {
		textcolor(4);
		cout << "No hay registros para modo de juego " << mododejuego(COMPLETA)<<endl;
	} 
	fontcolor(15,3);
	if(mejordiagonal>0){
		cout << setw(20) << distintos[posdiagonal].nombre << setw(20)<<mododejuego(distintos[posdiagonal].modo)<<setw(16)<<distintos[posdiagonal].veces<<endl;
	} else {
		textcolor(4);
		cout << "No hay registros para modo de juego " << mododejuego(DIAGONAL)<<endl;
	}
	fontcolor(15,5);
	if(mejorvertical>0){
		cout << setw(20) << distintos[posvertical].nombre << setw(20)<<mododejuego(distintos[posvertical].modo)<<setw(16)<<distintos[posvertical].veces<<endl;
	} else {
		textcolor(4);
		cout << "No hay registros para modo de juego " << mododejuego(VERTICAL)<<endl;
	}
	
	fs.close();
	gotoxy(0,25);
	textcolor(15);
}