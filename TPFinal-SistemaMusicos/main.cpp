#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

/*
version final del TP

*/

const char *ARCHIVO_MUSICOS = "musicos.dat";
const char *ARCHIVO_GENEROS = "generos.dat";
const char *ARCHIVO_INSTRUMENTOS = "instrumentos.dat";
const char *ARCHIVO_PAISES = "paises.dat";

using namespace std;
#include "FuncionesEsenciales.h"
#include "Fecha.h"


#include "Musicos.h"
#include "ArchivoMusicos.h"

#include "Generos.h"
#include "ArchivoGeneros.h"

#include "subMenuMusicos.h"
#include "subMenuGeneros.h"

#include "Instrumentos.h"
#include "ArchivoInstrumentos.h"
#include "subMenuInstrumentos.h"

#include "Pais.h"
#include "ArchivoPaises.h"
#include "subMenuPaises.h"

#include "subMenuConfiguracion.h"






int main(){
setlocale(LC_ALL,"Spanish");
    ArchivoMusicos archi(ARCHIVO_MUSICOS);
    int opci, dni;
    bool agrego, encontro, modifico, baja;
    while(true){
        cout<< " ------- MENU PRINCIPAL -------- "  << endl;
        cout<< "1) MENU MUSICOS"<< endl;
        cout<< "2) MENU GENEROS"<< endl;
        cout<< "3) MENU INSTRUMENTOS"<< endl;
        cout<< "4) MENU PAISES"<< endl;
        cout<< "5) REPORTES"<< endl;
        cout<< "6) CONFIGURACION"<< endl;
        cout<< "---------------------------------"<< endl;
        cout<< "0) FIN DEL PROGRAMA"<< endl;
        cout<< "---------------------------------"<< endl;
        cout<<" SELECCIONE UNA DE LAS OPCIONES: ";
         cin >> opci;

        switch(opci){

            case 1: system("cls");
                    subMenuMusicos();
                    break;

            case 2: system("cls");
                    subMenuGeneros();
                    break;

            case 3: system("cls");
                    subMenuIntrumentos();
                    break;

            case 4: system("cls");
                    subMenuPaises();
                    break;

            case 5: system("cls");
                    subMenuConfiguracion();
                    break;


            case 0: return 0;

        }
    system("pause");
    system("cls");
    }
    return 0;
}
