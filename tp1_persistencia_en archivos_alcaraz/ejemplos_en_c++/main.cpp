#include <iostream>
#include <fstream>

using namespace std;

int contador;

void guardarPunt(string name, int puntaje, string tiempo);
void leerPunt();

int main()
{
    guardarPunt("Pepe", 108, "4:16");
    guardarPunt("Juana", 2315, "8:42");
    leerPunt();

}

void guardarPunt(string name, int puntaje, string tiempo)
{
    ofstream guardarLis;
    guardarLis.open("puntajes.txt", ios::app);

    if(guardarLis.is_open()){
        guardarLis << name << " " << puntaje << " " << tiempo << endl; 
    }
    else{
        cout << "\n\n---> El archivo no ha sido encontrado" << endl;
        cin.get();
        main();
    }

    guardarLis.close();
}


void leerPunt()
{
    string name, tiempo;
    int puntaje;

    ifstream cargarLis;
    cargarLis.open("puntajes.txt", ios::in);

    if(cargarLis.is_open()){

        while(!cargarLis.eof()){
            /*cargarLis >> name;
            cargarLis >> puntaje;
            cargarLis >> tiempo;
            cout << name << " " << puntaje << " " << tiempo << endl;*/
            getline(cargarLis, name);
            cout << name << endl;
        }
    }
    else{
        cout << "\n\n---> El archivo no ha sido encontrado" << endl;
    }

    cargarLis.close();
}

