#ifndef ARCHIVOGENEROS_H_INCLUDED
#define ARCHIVOGENEROS_H_INCLUDED

class ArchivoGeneros{
    private:
        char nombre[30];
    public:
        ArchivoGeneros(const char *n){
            strcpy(nombre,n);
        }
        //ALTA
        bool agregarGenero();
        //BAJA
        int buscarGeneroPorID(int dni);
        Generos leerRegistro(int pos);
        bool bajaLogicaGenero();

        //MODIFICACIONES
        bool modificarAnioOrigen();

        //LISTADOS
        bool mostrarID_Buscado(int id);
        bool sobreEscribirRegistro(Generos registroGen, int pos);//maxi lo hizo bool para ver si se pudo o no
        void mostrarRegistroGenero();

        //GETTER
        const char *getNombre(){return nombre;}

        //METODOS
        int contarRegistros(){
            FILE *genArchivo;
            genArchivo=fopen(nombre, "rb");
            if(genArchivo==NULL) return -1;
            fseek(genArchivo, 0,2);
            int tam=ftell(genArchivo);
            fclose(genArchivo);
            return tam/sizeof(Generos);
        }

        int generarID();

};

int ArchivoGeneros::generarID(){
    Generos registroGen;
    int pos = 1;
    FILE *pGenero;

    pGenero = fopen(nombre, "rb");
    if(pGenero == NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return 0;
    }
    while(fread(&registroGen, sizeof registroGen,1, pGenero) == 1){
        pos=pos+1;
    }
    fclose(pGenero);
    return pos;
}


bool ArchivoGeneros::agregarGenero(){
    Generos registroGen;
    FILE *genArchivo;

    genArchivo=fopen(nombre, "ab");
    if(genArchivo==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }

    cout<<"Agregue un Genero "<<endl<<endl;

    int auxID;

    auxID=generarID();
    registroGen.setId(auxID);

    cout<<"ID de genero(AUTONUMERICO): "<<registroGen.getId()<<endl;
    if(registroGen.Cargar()){
        fwrite(&registroGen,sizeof registroGen, 1, genArchivo);
        fclose(genArchivo);
        cout<<endl;
        return true;
    }
    fclose(genArchivo);
return false;
}

void ArchivoGeneros::mostrarRegistroGenero(){
    Generos registroGen;
    FILE *genArchivo;

    cout<<"se listaran TODOS los generos cargados: "<<endl<<endl;


    genArchivo=fopen(nombre, "rb");

    if(genArchivo==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }
	while(fread(&registroGen, sizeof registroGen, 1, genArchivo)==1){
        registroGen.Mostrar();
        cout<<endl;
	}

	fclose(genArchivo);
}

bool ArchivoGeneros::mostrarID_Buscado(int id){
    Generos registroGen;
    FILE *pGenero;

    pGenero=fopen(nombre,"rb");
    if(pGenero==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    while(fread(&registroGen, sizeof registroGen, 1, pGenero)==1){
        if(registroGen.getId()==id && registroGen.getEstado()==true){
            registroGen.Mostrar();
            cout<<endl;
            return true;
        }
    }
    fclose(pGenero);
return false;
}

int ArchivoGeneros::buscarGeneroPorID(int id){ ///Retorna -1 si no encontro el ID, sino retorna la posicion
    Generos registroGen;
    FILE *pGenero;
    int pos=0;

    pGenero=fopen(nombre,"rb");
    if(pGenero==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return -2;
    }
    while(fread(&registroGen, sizeof registroGen, 1, pGenero)==1){
        if(registroGen.getId()==id && registroGen.getEstado()){
            fclose(pGenero);
            return pos;
        }
        pos++;
    }

    fclose(pGenero);

return -1;

}

Generos ArchivoGeneros::leerRegistro(int pos){
    Generos registroGen;
    FILE *pGenero;

    registroGen.setId(-1);

    pGenero=fopen(nombre, "rb");
    if(pGenero==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return registroGen;
    }
    fseek(pGenero, sizeof(Generos)*pos,0);
    fread(&registroGen, sizeof registroGen, 1, pGenero);
    fclose(pGenero);

return registroGen;
}

bool ArchivoGeneros::sobreEscribirRegistro(Generos registroGen, int pos){
    FILE *pGenero;

    pGenero=fopen(nombre,"rb+");
    if(pGenero==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    fseek(pGenero, pos*sizeof registroGen, 0);
    fwrite(&registroGen, sizeof registroGen, 1, pGenero);

    fclose(pGenero);
return true;
}

bool ArchivoGeneros::modificarAnioOrigen(){
    int id, pos;

    Generos registroGen;
    FILE *pGenero;

    cout<<"Ingrese el ID del genero: ";
    cin>>id;
    cout<<endl;
    pGenero=fopen(ARCHIVO_GENEROS,"ab");
    if(pGenero==NULL) return false;

    pos=buscarGeneroPorID(id);
    if(pos==-1){
    cout<<"No existe un registro con ese ID"<<endl;
    system("pause");
    return false;
    }
    if(pos==-2){
    cout<<"No se pudo abrir el archivo de generos"<<endl;
    system("pause");
    return false;
    }
    registroGen=leerRegistro(pos);
    Fecha anioOrigen ;
    anioOrigen.cargarAnio();
    cout<<endl;
    registroGen.setAnioOrigen(anioOrigen);
    if (sobreEscribirRegistro(registroGen, pos)){
            cout<<"Se sobrescribio con exito el registro en el archivo."<<endl<<endl;
    }else{cout<<"No se pudo sobrescribir."<<endl;}

return true;
}

bool ArchivoGeneros::bajaLogicaGenero(){
    Generos registroGen;
    int id, pos;

    cout<<"Ingrese el ID del genero a eliminar: "<<endl;
    cin>>id;

///Buscar el registro a eliminar
    pos=buscarGeneroPorID(id);
    if(pos==-1){
        cout<<"No existe un registro con ese ID"<<endl;
        system("pause");
        return false;
    }
    if(pos==-2){
        cout<<"No se pudo abrir el archivo de generos"<<endl;
        system("pause");
        return false;
    }
///Leer el registro(escribirlo en una variable de memoria)
    registroGen=leerRegistro(pos);
///Cambiar el estado del campo
    registroGen.setEstado(false);
///Sobrescribir el registro en la misma posicion del archivo en el que se encontraba
    if(sobreEscribirRegistro(registroGen, pos)){
        cout<<"Se sobrescribio el estado con exito."<<endl<<endl;
    }else{cout<<"No se pudo sobrescribir el estado."<<endl;}
return true;
}



#endif // ARCHIVOGENEROS_H_INCLUDED
