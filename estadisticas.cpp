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
	int mejorhorizontal=0, mejorcompleta=0, mejordiagonal=0, mejorvertical=0;
	int poshorizontal=0, poscompleta=0, posdiagonal=0, posvertical=0;
	int n=0;
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
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
	}
	
	
	fontcolor(0,4);
	cout << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl<<endl <<endl;
	fontcolor(15,1);
	fs.close();
	fs.open(ARCHIVO,ios::binary|ios::in);
	if(mejorhorizontal>0){
		fs.seekg(poshorizontal*sizeof(Estadisticas)); // salta a la posición en bytes desde el inicio
		fs.read((char*)(&aux),sizeof(Estadisticas)); // lee datos
		cout << setw(20) << aux.alias;
		cout << setw(20) << mododejuego(aux.modo);
		cout << setw(16) << aux.puntuacion;
		cout << setw(25) << aux.fecha<<endl<<endl;
	} else {
		textcolor(4);
		cout << "No hay registros para modo de juego " << mododejuego(HORIZONTAL)<<endl;
	}
	fontcolor(15,2);
/* 	fs.close();
	fs.open(ARCHIVO,ios::binary|ios::in); */
	if(mejorcompleta>0){
		fs.seekg(poscompleta*sizeof(Estadisticas)); // salta a la posición en bytes desde el inicio
		fs.read((char*)(&aux),sizeof(Estadisticas)); // lee datos
		cout << setw(20) << aux.alias;
		cout << setw(20) << mododejuego(aux.modo);
		cout << setw(16) << aux.puntuacion;
		cout << setw(25) << aux.fecha<<endl<<endl;
	} else {
		textcolor(4);
		cout << "No hay registros para modo de juego " << mododejuego(COMPLETA)<<endl;
	} 
	fontcolor(15,3);
/* 	fs.close();
	fs.open(ARCHIVO,ios::binary|ios::in); */
	if(mejordiagonal>0){
		fs.seekg(posdiagonal*sizeof(Estadisticas)); // salta a la posición en bytes desde el inicio
		fs.read((char*)(&aux),sizeof(Estadisticas)); // lee datos
		cout << setw(20) << aux.alias;
		cout << setw(20) << mododejuego(aux.modo);
		cout << setw(16) << aux.puntuacion;
		cout << setw(25) << aux.fecha<<endl<<endl;
	} else {
		textcolor(4);
		cout << "No hay registros para modo de juego " << mododejuego(DIAGONAL)<<endl;
	}
	fontcolor(15,5);
/* 	fs.close();
	fs.open(ARCHIVO,ios::binary|ios::in); */
	if(mejorvertical>0){
		fs.seekg(posvertical*sizeof(Estadisticas)); // salta a la posición en bytes desde el inicio
		fs.read((char*)(&aux),sizeof(Estadisticas)); // lee datos
		cout << setw(20) << aux.alias;
		cout << setw(20) << mododejuego(aux.modo);
		cout << setw(16) << aux.puntuacion;
		cout << setw(25) << aux.fecha<<endl<<endl;
	} else {
		textcolor(4);
		cout << "No hay registros para modo de juego " << mododejuego(VERTICAL)<<endl;
	}
	
	fs.close();
	gotoxy(0,25);
	textcolor(15);
}