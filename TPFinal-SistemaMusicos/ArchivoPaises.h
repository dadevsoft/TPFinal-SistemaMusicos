#ifndef ARCHIVOPAISES_H_INCLUDED
#define ARCHIVOPAISES_H_INCLUDED

class ArchivoPaises{
    private:
        char nombre[30];
    public:
        ArchivoPaises(const char *n){
            strcpy(nombre,n);
        }
        //ALTA
        bool agregarPais();
        //BAJA
        int buscarPaisPorID(int id);
        Pais leerRegistro(int pos);
        bool bajaLogicaPais();

        //MODIFICACIONES
        bool modificarNombre();

        //LISTADOS
        bool mostrarID_Buscado(int id);
        bool sobreEscribirRegistro(Pais registroPais, int pos);//maxi lo hizo bool para ver si se pudo o no
        void mostrarRegistroPais();

        int contarRegistros(){
            FILE *p;
            p=fopen(nombre, "rb");
            if(p==NULL) return -1;
            fseek(p, 0,2);
            int tam=ftell(p);
            fclose(p);
            return tam/sizeof(Pais);
        }

        //GETTER
        const char *getNombre(){return nombre;}

        //METODOS
        int generarID();

};

int ArchivoPaises::generarID(){
    Pais registroPais;
    int pos = 1;
    FILE *pPais;

    pPais = fopen(nombre, "rb");
    if(pPais == NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return 0;
    }
    while(fread(&registroPais, sizeof registroPais,1, pPais) == 1){
        pos=pos+1;
    }
    fclose(pPais);
    return pos;
}

bool ArchivoPaises::agregarPais(){
    Pais registroPais;
    FILE *pPais;

    pPais=fopen(nombre, "ab");
    if(pPais==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    cout<<"Agregue un Pais "<<endl<<endl;
    int auxID;

    auxID=generarID();
    registroPais.setId(auxID);

    cout<<"ID del Pais(AUTONUMERICO): "<<registroPais.getId()<<endl;

    if(registroPais.Cargar()){
        fwrite(&registroPais,sizeof registroPais, 1, pPais);
        fclose(pPais);
        cout<<endl;
        return true;
    }
    fclose(pPais);
return false;
}

void ArchivoPaises::mostrarRegistroPais(){
    Pais registroPais;
    FILE *pPais;

    cout<<"se listaran TODOS los paises cargados: "<<endl<<endl;

    pPais=fopen(nombre, "rb");
    if(pPais==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&registroPais, sizeof registroPais, 1, pPais)==1){
        registroPais.Mostrar();
        cout<<endl;
	}
	fclose(pPais);
}

bool ArchivoPaises::mostrarID_Buscado(int id){
    Pais registroPais;
    FILE *pPais;

    pPais=fopen(nombre,"rb");
    if(pPais==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    while(fread(&registroPais, sizeof registroPais, 1, pPais)==1){
        if(registroPais.getId()==id&& registroPais.getEstado()==true){
            registroPais.Mostrar();
            return true;
        }
    }
    fclose(pPais);
    return false;
}

int ArchivoPaises::buscarPaisPorID(int id){ ///Retorna -1 si no encontro el ID, sino retorna la posicion
    Pais registroPais;
    FILE *p;
    int pos=0;

    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return -2;
    }
    while(fread(&registroPais, sizeof registroPais, 1, p)==1){
        if(registroPais.getId()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
return -1;
}

Pais ArchivoPaises::leerRegistro(int pos){//devuelde la posicion del registro
    Pais registroPais;
    FILE *p;

    registroPais.setId(-1);//define un absurdo para que si encuentra otro ID lo cambie en el set

    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return registroPais;
    }
    fseek(p, sizeof(Pais)*pos,0);//se posiciona
    fread(&registroPais, sizeof registroPais, 1, p);//lo lee
    fclose(p);

return registroPais;
}

bool ArchivoPaises::sobreEscribirRegistro(Pais registroPais, int pos){
    FILE *p;

    p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    fseek(p, pos*sizeof registroPais, 0);//se posiciona
    fwrite(&registroPais, sizeof registroPais, 1, p);//lo sobreescribe

    fclose(p);
return true;
}

bool ArchivoPaises::modificarNombre(){
    int id, pos;

    Pais registroPais;
    FILE *pPais;

    cout<<"Ingrese el ID del pais: ";
    cin>>id;
    cout<<endl;
    pPais=fopen(ARCHIVO_PAISES,"ab");
    if(pPais==NULL) return false;

    //Buscar el registro del instrumento a eliminar
    pos=buscarPaisPorID(id);
    if(pos==-1){
    cout<<"No existe un registro con ese ID"<<endl;
    system("pause");
    return false;
    }
    if(pos==-2){
    cout<<"No se pudo abrir el archivo de paises"<<endl;
    system("pause");
    return false;
    }
    ///Leer el registro(escribirlo en una variable de memoria)-->en un objeto?
    registroPais=leerRegistro(pos);
    ///Cambiar el estado del campo
    char nom[30];
    cout<<"Ingrese un nuevo nombre: " << endl;
    cin>>nom;
    cout<<endl;
    registroPais.setNombre(nom);
    ///Sobrescribir el registro en la misma posicion del archivo en que se encontraba
    if(sobreEscribirRegistro(registroPais, pos)){
        cout<<"Se sobrescribio con exito el registro en el archivo."<<endl<<endl;
    }else{cout<<"No se pudo sobrescribir."<<endl;}

return true;
}

bool ArchivoPaises::bajaLogicaPais(){
    Pais registroPais;
    int id, pos;

    cout<<"Ingrese el ID del Pais a eliminar: "<<endl;
    cin>>id;

///Buscar el registro a eliminar
    pos=buscarPaisPorID(id);
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
    registroPais=leerRegistro(pos);
///Cambiar el estado del campo
    registroPais.setEstado(false);
///Sobrescribir el registro en la misma posicion del archivo en el que se encontraba
    if(sobreEscribirRegistro(registroPais, pos)){
        cout<<"Se sobrescribio el estado con exito."<<endl<<endl;
    }else{cout<<"No se pudo sobrescribir el estado."<<endl;}
return true;
}

#endif // ARCHIVOPAISES_H_INCLUDED
