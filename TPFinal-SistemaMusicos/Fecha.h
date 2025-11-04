#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }
    bool cargarAnio(){
        cout<<"Ingrese año de origen: "<<endl;
        cin>>anio;
        while(anio<1500 || anio>2023){
            cout<<"No es valido - Vuelva a ingrese un año de origen (1500-Actualidad): "<<endl;
            cin>>anio;
        }
    dia= 0;
    mes= 0;
    }
    void mostrarAnio(){
        cout<<"Año de origen: "<<endl;
        cout<<anio;
    }

        //sets
        void setDia(int x){dia=x;}
        void setMes(int x){mes=x;}
        void setAnio(int x){anio=x;}
        //gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        void Cargar();
        void Mostrar();

};


void Fecha::Cargar(){

        cout<<"Ingrese el dia (1-31): "<<endl;
        cin>>dia;
        while(dia<1 || dia>31){
            cout<<"Ingrese un dia valido(1-31)"<<endl;
            cin>>dia;
        }
        cout<<"Ingrese el mes (1-12): "<<endl;
        cin>>mes;
        while(mes<1 || mes>12){
            cout<<"Ingrese un mes(1-12) valido"<<endl;
            cin>>mes;
        }
        cout<<"Ingrese el año: "<<endl;
        cin>>anio;
        while(anio<1500 || anio>2023){
        cout<<"Ingrese un año valido entre el 1500 y la Actualidad"<<endl;
        cin>>anio;

        }
}

void Fecha::Mostrar(){
cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

#endif // FECHA_H_INCLUDED
