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
	textcolor(2);
	cout << setw(20) << "Alias"<<setw(20)<<"Modo"<<setw(16)<<"Puntuacion"<<setw(25)<<"Fecha"<<endl;
	textcolor(15);
	while(fs.read((char*)(&aux),sizeof(Estadisticas))){
		cout << setw(20) << aux.alias;
		cout << setw(20) << mododejuego(aux.modo);
		cout << setw(16) << aux.puntuacion;
		cout << setw(25) <<aux.fecha<<endl;
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
	textcolor(2);
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
		cout << "No hay registros de ese alias"<<endl;
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