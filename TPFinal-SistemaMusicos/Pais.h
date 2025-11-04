#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

class Pais{
    private:
        int id;
        char nombre[30];
        char continente[30];
        bool estado;

    public:
         // GETTERS
        int getId(){return id;};
        const char *getNombre(){return nombre;};
        const char *getContinente(){return continente;};
        bool getEstado(){return estado;};
        // SETTERS
        void setId(const int d){id = d;}
        void setNombre(const char *nomb){strcpy(nombre,nomb);}
        void setContinente(const char *conti){strcpy(continente,conti);}
        void setEstado(const bool e){estado = e;}
        //METODOS
        bool Cargar();
        void Mostrar();
};

bool Pais::Cargar(){
    cout<<"Nombre del pais: "<<endl;
    cargarCadena(nombre,29);
    cout<<"Continente al que pertenece: "<<endl;
    cargarCadena(continente,29);
    estado=true;
return true;
}

void Pais::Mostrar(){
    if(estado){
        cout<<"ID: ";
        cout<<id<<endl;
        cout<<"Nombre del pais: ";
        cout<<nombre<<endl;
        cout<<"Continente al que pertenece: "<<endl;
        cout<<continente<<endl;
    }
}

#endif // PAIS_H_INCLUDED
