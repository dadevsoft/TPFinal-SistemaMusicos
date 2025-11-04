#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED

class Instrumentos{
    private:
        int id;
        char nombre[30];
        int clasificacion;
        bool estado;

    public:
        // GETTERS
        int getId(){return id;};
        const char *getNombre(){return nombre;};
        int getClasificacion(){return clasificacion;};
        bool getEstado(){return estado;};
        // SETTERS
        void setId(const int d){id = d;}
        void setNombre(const char *nomb){strcpy(nombre,nomb);}
        void setClasificacion(const int clasi){clasificacion = clasi;}
        void setEstado(const bool e){estado = e;}
        //METODOS
        bool Cargar();
        void Mostrar();

};

bool Instrumentos::Cargar(){

    cout<<"Nombre: "<<endl;
    cargarCadena(nombre,29);
    cout<<"Clasificacion: "<<endl;
    cin>>clasificacion;

    estado=true;
    return true;

}

void Instrumentos::Mostrar(){

            if(estado){
                cout<<"ID: ";
                cout<<id<<endl;
                cout<<"Nombre: ";
                cout<<nombre<<endl;
                cout<<"Clasificacion: "<<endl;
                cout<<clasificacion<<endl;
                }
}

#endif // INSTRUMENTOS_H_INCLUDED
