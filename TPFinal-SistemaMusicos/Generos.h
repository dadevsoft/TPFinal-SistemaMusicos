#ifndef GENEROS_H_INCLUDED
#define GENEROS_H_INCLUDED

class Generos{
    private:
        int id;
        char nombre[30];
        int paisOrigen;
        Fecha anioOrigen;
        bool estado;

    public:
         // GETTERS
        int getId(){return id;};
        const char *getNombre(){return nombre;};
        int getPaisOrigen(){return paisOrigen;};
        Fecha getAnioOrigen(){return anioOrigen;};
        bool getEstado(){return estado;};
        // SETTERS
        void setId(const int d){id = d;}
        void setNombre(const char *nomb){strcpy(nombre,nomb);}
        void setPaisOrigen(const int paisOri){paisOrigen = paisOri;}
        Fecha setAnioOrigen(Fecha fe){anioOrigen = fe;}
        void setEstado(const bool e){estado = e;}

        //METODOS
        bool Cargar();
        void Mostrar();
};

bool Generos::Cargar(){
    cout<<"Nombre: "<<endl;
    cargarCadena(nombre,29);
    cout<<"Pais de origen(1-100): "<<endl;
    cin>>paisOrigen;
    while(paisOrigen<1 || paisOrigen>100){
        cout<<"Pais de origen ingresado INCORRECTO"<<endl;
        cout<<"Debe ingresar un Pais de origen del 1 al 100"<<endl;
        cin>>paisOrigen;
    }
    anioOrigen.cargarAnio();
    estado=true;
return true;
}

void Generos::Mostrar(){
    if(estado){
    cout<<"ID: ";
    cout<<id<<endl;
    cout<<"Nombre: ";
    cout<<nombre<<endl;
    cout<<"Pais de origen: "<<endl;
    cout<<paisOrigen<<endl;
    anioOrigen.mostrarAnio();
    cout<<endl;
    }

}

#endif // GENEROS_H_INCLUDED
