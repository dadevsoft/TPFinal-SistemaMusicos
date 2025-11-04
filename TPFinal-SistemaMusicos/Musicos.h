#ifndef MUSICOS_H_INCLUDED
#define MUSICOS_H_INCLUDED

#include "Generos.h"
#include "Instrumentos.h"


class Musicos {

    private:
        int dni;
        char nombre[30];
        char apellido[30];
        char email[30];
        char telefono[30];
        int claustro;
        int instrumentoPrincipal;
        int tipoDeMusica;
        Fecha fechaInscripcion;
        float matricula;
        bool estado;

    public:
        // GETTERS
        int getDni(){return dni;};
        const char *getNombre(){return nombre;};
        const char *getaApellido() {return apellido;};
        const char *getEmail(){return email;};
        const char *getTelefono(){return telefono;};
        int getClaustro(){return claustro;};
        int getInstrumentoPrincipal(){return instrumentoPrincipal;};
        int getTipodeMusica(){return tipoDeMusica;};
        Fecha getFechaInscripcion(){return fechaInscripcion;};
        float getMatricula(){return matricula;};
        bool getEstado(){return estado;};
        // SETTERS
        void setDni(const int d){ dni = d;}
        void setNombre(const char *nomb){strcpy(nombre,nomb);}
        void setApellido(const char *apell){strcpy(apellido, apell);}
        void setEmail(const char *ema){strcpy(email, ema);}
        void setTelefono(const char *tele){strcpy(telefono, tele);}
        void setClaustro(const int claus){claustro = claus;}//se puede validar aca?
        void setInstrumentoPrincipal(const int instru){instrumentoPrincipal = instru;}
        void setTipoDeMusica(const int musica){tipoDeMusica = musica;}
        void setFechaInscripcion(Fecha f){fechaInscripcion=f;}
        void setMatricula(const float mat){matricula = mat;}
        void setEstado(const bool e){estado = e;}
        // METODOS

        bool Cargar(int verifDni);

        void Mostrar(){
            if(getEstado()==true){
                cout<<"DNI: "<<endl;
                cout<<dni<<endl;
                cout<<"Nombre: ";
                cout<<nombre<<endl;
                cout<<"APELLIDO: ";
                cout<<apellido<<endl;
                cout<<"EMAIL: ";
                cout<<email<<endl;
                cout<<"TELEFONO: ";
                cout<<telefono<<endl;
                cout<<"Fecha de inscripcion: ";
                fechaInscripcion.Mostrar();
                cout<<"Claustro: "<<endl;
                cout<<claustro<<endl;
                cout << "Instrumento Principal: " << endl;
                cout<<instrumentoPrincipal<<endl;
                cout << "Tipo de Musica: " <<endl;
                cout<<tipoDeMusica<<endl;
                cout << "Matricula: " <<endl;
                cout<<matricula<<endl;
                }
            }
        int validarClaustro(int clau);
        int validarInstruPrincipal(int instPrin);
        int validarTipoDeMusica(int tipoDeMu);
        float validarMatricula(float matri);
};

int Musicos::validarClaustro(int clau){
    while(clau<1 || clau>4){
        cout<<"El claustro ingresado es incorrecto."<<endl;
        cout<<"Debe ingresar un numero entre 1 y 4."<<endl;
        cout<<"Vuelva a ingresar el claustro: "<<endl;
        cin>>clau;
    }
    return clau;
}
int Musicos::validarInstruPrincipal(int instPrin){
///Retorna -1 si no encontro el ID en el archivo intrumentos
    Instrumentos rInstru;
    FILE *pIn;
    int pos=1;

    pIn=fopen("instrumentos.dat","rb");
    if(pIn==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return -2;
    }
    while(fread(&rInstru, sizeof rInstru, 1, pIn)==1){
        if(rInstru.getId()==instPrin && rInstru.getEstado()==true){
            fclose(pIn);
            return pos;
        }
        pos++;
    }
    fclose(pIn);
return -1;
}
int Musicos::validarTipoDeMusica(int tipoDeMu){
///Retorna -1 si no encontro el ID en el archivo genero
    Generos rGen;
    FILE *pGen;
    int pos=1;

    pGen=fopen("generos.dat","rb");
    if(pGen==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return -2;
    }
    while(fread(&rGen, sizeof rGen, 1, pGen)==1){
        if(rGen.getId()==tipoDeMu && rGen.getEstado()==true){
            fclose(pGen);
            return pos;
        }
        pos++;
    }
    fclose(pGen);
return -1;
}

float Musicos::validarMatricula(float matri){
    while(matri<0){
        cout<<"La Matricula ingresada es incorrecta."<<endl;
        cout<<"Debe ingresar un numer mayor o igual a 0."<<endl;
        cout<<"Vuelva a ingresar la matricula: "<<endl;
        cin>>matri;
    }
    return matri;
}


bool Musicos::Cargar(int verifDni){
    int clau, instruPri, tipoDeMu;
    float matri;
    dni=verifDni;
    cout <<"Nombre: " << endl;
    cargarCadena(nombre,29);
    cout <<"Apellido: " << endl;
    cin>>apellido;
    cout<<"Email: " << endl;
    cin>>email;
    cout <<"Telefono: " << endl;
    cin>>telefono;
    cout<<"Fecha de Inscripcion: "<<endl;
    fechaInscripcion.Cargar();
    cout<<"Claustro(1-4): "<<endl;
    cin >>clau;
    claustro=validarClaustro(clau);
    cout <<"Instrumento Principal: " << endl;
    cin>>instruPri;
    instrumentoPrincipal=validarInstruPrincipal(instruPri);
    if(instrumentoPrincipal==-2){
        cout<<"No se puede seguir con la carga de datos"<<endl;
        return false;
    }
    while(instrumentoPrincipal < 0){
            cout<<"Incorrecto"<<endl;
            cout<<"Ingrese un Instrumento Principal correspondiente con el ID en el archivo de intrumentos."<<endl;
            cout <<"Instrumento Principal: " << endl;
            cin>>instruPri;
            instrumentoPrincipal=validarInstruPrincipal(instruPri);
    }
    cout <<"Tipo de Musica: " << endl;
    cin >> tipoDeMu;
    tipoDeMusica=validarTipoDeMusica(tipoDeMu);
    if(instrumentoPrincipal==-2){
        cout<<"No se puede seguir con la carga de datos"<<endl;
        return false;
    }
    while(tipoDeMusica < 0){
        cout<<"Incorrecto"<<endl;
        cout<<"Ingrese un Tipo de Musica correspondiente con el ID en el archivo de generos."<<endl;
        cout <<"Tipo de Musica: " << endl;
        cin >> tipoDeMu;
        tipoDeMusica=validarTipoDeMusica(tipoDeMu);
    }
    cout <<"Matricula: " << endl;
    cin>>matri;
    matricula=validarMatricula(matri);
    estado=true;

return true;
}



#endif // MUSICOS_H_INCLUDED
