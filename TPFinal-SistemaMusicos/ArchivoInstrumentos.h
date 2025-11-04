#ifndef ARCHIVOINSTRUMENTOS_H_INCLUDED
#define ARCHIVOINSTRUMENTOS_H_INCLUDED

class ArchivoInstrumentos{
    private:
        char nombre[30];
    public:
        ArchivoInstrumentos(const char *n){
            strcpy(nombre,n);
        }
        //ALTA
        bool agregarInstrumento();
        //BAJA
        int buscarInstrumentoPorID(int id);
        Instrumentos leerRegistro(int pos);
        bool bajaLogicaInstrumento();

        //MODIFICACIONES
        bool modificarNombre();

        //LISTADOS
        bool mostrarID_Buscado(int id);
        bool sobreEscribirRegistro(Instrumentos registroInst, int pos);
        void mostrarRegistroInstrumento();

        //GETTER
        const char *getNombre(){return nombre;}

        //METODOS
        int generarID();

         int contarRegistros(){
            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Instrumentos);
        }

};

int ArchivoInstrumentos::generarID(){
    Instrumentos registroInst;
    int pos = 1;
    FILE *pInstrumento;

    pInstrumento = fopen(nombre, "rb");
    if(pInstrumento == NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return 0;
    }
    while(fread(&registroInst, sizeof registroInst,1, pInstrumento) == 1){
        pos=pos+1;
    }
    fclose(pInstrumento);
    return pos;
}

bool ArchivoInstrumentos::agregarInstrumento(){
    Instrumentos registroInst;
    FILE *pInstrumento;

    pInstrumento=fopen(nombre, "ab");
    if(pInstrumento==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    cout<<"Agregue un Instrumento "<<endl<<endl;
    int auxID;

    auxID=generarID();
    registroInst.setId(auxID);

    cout<<"ID de Instrumento(AUTONUMERICO): "<<registroInst.getId()<<endl;

    if(registroInst.Cargar()){
        fwrite(&registroInst,sizeof registroInst, 1, pInstrumento);
        fclose(pInstrumento);
        cout<<endl;
        return true;
    }
    fclose(pInstrumento);
return false;
}

void ArchivoInstrumentos::mostrarRegistroInstrumento(){
    Instrumentos registroInst;
    FILE *pInstrumento;

    cout<<"se listaran TODOS los instrumentos cargados: "<<endl<<endl;

    pInstrumento=fopen(nombre, "rb");
    if(pInstrumento==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&registroInst, sizeof registroInst, 1, pInstrumento)==1){
        registroInst.Mostrar();
        cout<<endl;
	}
	fclose(pInstrumento);
}

bool ArchivoInstrumentos::mostrarID_Buscado(int id){
    Instrumentos registroInst;
    FILE *pInst;

    pInst=fopen(nombre,"rb");
    if(pInst==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    while(fread(&registroInst, sizeof registroInst, 1, pInst)==1){
        if(registroInst.getId()==id && registroInst.getEstado()==true){
            registroInst.Mostrar();
            cout<<endl;
            return true;
        }
    }
    fclose(pInst);
    return false;
}

int ArchivoInstrumentos::buscarInstrumentoPorID(int id){
    Instrumentos registroInst;
    FILE *pInst;
    int pos=0;

    pInst=fopen(nombre,"rb");
    if(pInst==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return -2;
    }
    while(fread(&registroInst, sizeof registroInst, 1, pInst)==1){
        if(registroInst.getId()==id){
            fclose(pInst);
            return pos;
        }
        pos++;
    }

    fclose(pInst);
return -1;
}

Instrumentos ArchivoInstrumentos::leerRegistro(int pos){
    Instrumentos registroInst;
    FILE *pInst;

    registroInst.setId(-1);

    pInst=fopen(nombre, "rb");
    if(pInst==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return registroInst;
    }
    fseek(pInst, sizeof(Instrumentos)*pos,0);//se posiciona
    fread(&registroInst, sizeof registroInst, 1, pInst);//lo lee
    fclose(pInst);

return registroInst;
}

bool ArchivoInstrumentos::sobreEscribirRegistro(Instrumentos registroInst, int pos){
    FILE *pInstrumento;

    pInstrumento=fopen(nombre,"rb+");
    if(pInstrumento==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    fseek(pInstrumento, pos*sizeof registroInst, 0);//se posiciona
    fwrite(&registroInst, sizeof registroInst, 1, pInstrumento);//lo sobreescribe

    fclose(pInstrumento);
return true;
}

bool ArchivoInstrumentos::modificarNombre(){
    int id, pos;

    Instrumentos registroInst;
    FILE *pInstrumento;

    cout<<"Ingrese el ID del instrumento: ";
    cin>>id;
    cout<<endl;
    pInstrumento=fopen(ARCHIVO_INSTRUMENTOS,"ab");
    if(pInstrumento==NULL) return false;

    pos=buscarInstrumentoPorID(id);
    if(pos==-1){
    cout<<"No existe un registro con ese ID"<<endl;
    system("pause");
    return false;
    }
    if(pos==-2){
    cout<<"No se pudo abrir el archivo de instrumentos"<<endl;
    system("pause");
    return false;
    }
    registroInst=leerRegistro(pos);
    char nom[30];
    cout<<"Ingrese un nuevo nombre: " << endl;
    cin>>nom;
    cout<<endl;
    registroInst.setNombre(nom);
    if(sobreEscribirRegistro(registroInst, pos)){
        cout<<"Se sobrescribio con exito el registro en el archivo."<<endl<<endl;
    }else{cout<<"No se pudo sobrescribir."<<endl;}

return true;
}

bool ArchivoInstrumentos::bajaLogicaInstrumento(){
    Instrumentos registroInst;
    int id, pos;

    cout<<"Ingrese el ID del instrumento a eliminar: "<<endl;
    cin>>id;

///Buscar el registro a eliminar
    pos=buscarInstrumentoPorID(id);
    if(pos==-1){
        cout<<"No existe un registro con ese ID"<<endl;
        system("pause");
        return false;
    }
    if(pos==-2){
        cout<<"No se pudo abrir el archivo de instrumentos"<<endl;
        system("pause");
        return false;
    }
///Leer el registro(escribirlo en una variable de memoria)
    registroInst=leerRegistro(pos);
///Cambiar el estado del campo
    registroInst.setEstado(false);
///Sobrescribir el registro en la misma posicion del archivo en el que se encontraba
    if(sobreEscribirRegistro(registroInst, pos)){
        cout<<"Se sobrescribio el estado con exito."<<endl<<endl;
    }else{cout<<"No se pudo sobrescribir el estado."<<endl;}
return true;
}

#endif // ARCHIVOINSTRUMENTOS_H_INCLUDED
