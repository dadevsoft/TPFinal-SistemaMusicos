#ifndef ARCHIVOMUSICOS_H_INCLUDED
#define ARCHIVOMUSICOS_H_INCLUDED

class ArchivoMusicos{
    private:
        char nombre[30];
    public:
        ArchivoMusicos(const char *n){
            strcpy(nombre,n);
        }
        //ALTA
        bool agregarMusico();

        //BAJA
        int buscarMusicoPorDni(int dni);
        Musicos leerRegistro(int pos);
        bool bajaLogicaMusico();

        //int validarTipoMusica(int dni)

        //MODIFICACIONES
        bool modificarFechaInscripcion();

        //LISTADOS
        bool MostrarDNI_buscado(int dni);
        void sobreEscribirRegistro(Musicos registroMusi, int pos);//maxi lo hizo bool para ver si se pudo o no
        void mostrarRegistroMusico();



        int contarRegistros(){
            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Musicos);
        }
        const char *getNombre(){return nombre;}

};


bool ArchivoMusicos::agregarMusico(){//ES bool para saber si se púdo agregar el musico en el menu
    Musicos registroMusi;
    FILE *muArchivo;

    muArchivo=fopen(nombre, "ab");
    if(muArchivo==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }

    cout<<"Agregue un Musico: "<<endl<<endl;

    int verifDni;
    cout<<"DNI: ";
    cin>>verifDni;

    if(buscarMusicoPorDni(verifDni)>-1){
        cout<<endl;
        cout<<"EL DNI INGRESADO YA SE ENCUENTRA CARGADO EN EL ARCHIVO."<<endl;
        return false;
    }



    if(registroMusi.Cargar(verifDni)){
        fwrite(&registroMusi,sizeof registroMusi, 1, muArchivo);
        fclose(muArchivo);
        return true;
    }
    fclose(muArchivo);
	return false;
}

void ArchivoMusicos::mostrarRegistroMusico(){
    Musicos registroMusi;
    FILE *muArchivo;

    cout<<"se mostraran los musicos cargados: "<<endl;
    muArchivo=fopen(nombre, "rb");
    if(muArchivo==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&registroMusi, sizeof registroMusi, 1, muArchivo)==1){
        registroMusi.Mostrar();
        cout<<endl;
	}
	fclose(muArchivo);
}

bool ArchivoMusicos::bajaLogicaMusico(){
    Musicos registroMusi;
    int dni, pos;

    cout<<"Ingrese el DNI del musico a eliminar: "<<endl;
    cin>>dni;

///Buscar el registro a eliminar
    pos=buscarMusicoPorDni(dni);
    if(pos==-1){
        cout<<"No existe un registro con ese DNI"<<endl;
        system("pause");
        return false;
    }
    if(pos==-2){
        cout<<"No se pudo abrir el archivo de musicos"<<endl;
        system("pause");
        return false;
    }
///Leer el registro(escribirlo en una variable de memoria)
    registroMusi=leerRegistro(pos);
///Cambiar el estado del campo
    registroMusi.setEstado(false);
///Sobrescribir el registro en la misma posicion del archivo en que se encontraba
    sobreEscribirRegistro(registroMusi, pos);
    return true;
}


bool ArchivoMusicos::MostrarDNI_buscado(int dni){
    Musicos registroMusi;
    FILE *muArchivo;

    muArchivo=fopen(nombre,"rb");
    if(muArchivo==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    while(fread(&registroMusi, sizeof registroMusi, 1, muArchivo)==1){
        if(registroMusi.getDni()==dni && registroMusi.getEstado()==true){
            registroMusi.Mostrar();
            cout<<endl;
            return true;
        }

    }
    fclose(muArchivo);
    return false;
}

Musicos ArchivoMusicos::leerRegistro(int pos){
    Musicos registroMusi;
    FILE *muArchivo;
    registroMusi.setDni(-1);//define un absurdo para que si encuentra otro DNI lo cambie el set

    muArchivo=fopen(nombre, "rb");
    if(muArchivo==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return registroMusi;
    }
    fseek(muArchivo, sizeof(Musicos)*pos,0);//se posiciona
    fread(&registroMusi, sizeof registroMusi , 1, muArchivo);//lo lee
    fclose(muArchivo);

return registroMusi;

}

int ArchivoMusicos::buscarMusicoPorDni(int dni){ ///Retorna -1 si no encontro el DNI, sino retorna la posicion
    Musicos registroMusi;
    FILE *muArchivo;
    int pos=0;

    muArchivo=fopen(nombre,"rb");
    if(muArchivo==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return -2;
    }
    while(fread(&registroMusi, sizeof registroMusi, 1, muArchivo)==1){
        if(registroMusi.getDni()==dni && registroMusi.getEstado()){
            fclose(muArchivo);
            return pos;
        }
        pos++;
    }

fclose(muArchivo);
return -1;
}

bool ArchivoMusicos::modificarFechaInscripcion(){
    int dni, pos;

    Musicos registroMusi;
    FILE *muArchivo;

    cout<<"Ingrese el DNI del musico: "<<endl;
    cin>>dni;

    muArchivo=fopen(ARCHIVO_MUSICOS,"ab");
    if(muArchivo==NULL) return false;

    //Buscar el registro del Musico a eliminar
    pos=buscarMusicoPorDni(dni);
    if(pos==-1){
    cout<<"No existe un registro con ese DNI"<<endl;
    system("pause");
    return false;
    }
    if(pos==-2){
    cout<<"No se pudo abrir el archivo de musicos"<<endl;
    system("pause");
    return false;
    }
    ///Leer el registro(escribirlo en una variable de memoria)
    registroMusi=leerRegistro(pos);
    ///Cambiar el estado del campo
    Fecha fechaNueva;
    cout<<"Ingrese una nueva fecha de inscripcion: "<<endl;
    fechaNueva.Cargar();
    registroMusi.setFechaInscripcion(fechaNueva);
    ///Sobrescribir el registro en la misma posicion del archivo en que se encontraba
    sobreEscribirRegistro(registroMusi, pos);
    return true;

}

void ArchivoMusicos::sobreEscribirRegistro(Musicos registroMusi, int pos){
    FILE *muArchivo;

    muArchivo=fopen(nombre,"rb+");
    if(muArchivo==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return;
    }
    fseek(muArchivo, pos*sizeof registroMusi, 0);//se posiciona
    fwrite(&registroMusi, sizeof registroMusi, 1, muArchivo);//lo sobreescribe

fclose(muArchivo);
}




#endif // ARCHIVOMUSICOS_H_INCLUDED
