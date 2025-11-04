#ifndef SUBMENUGENEROS_H_INCLUDED
#define SUBMENUGENEROS_H_INCLUDED

/*
Restricciones

-El ID no debe repetirse en el archivo. Preferentemente se debe asignar de manera automática
incrementando de a 1 entre registro y registro.-->listo
-Los campos que tienen valores definidos (país y año de origen) no deben aceptar otros valores que no sean los indicados.-->listo
-El estado debe ser verdadero para que el sistema utilice el registro.-->listo
DUDA-Si hago una baja logica sobre un registro deberia contarlo en el id??

*/

void subMenuGeneros(){

    setlocale(LC_ALL,"Spanish");
    ArchivoGeneros archi2(ARCHIVO_GENEROS);
    int opci, id;
    bool agrego, encontro, modifico, baja;

    while(true){
        cout<< " MENU GÉNEROS"<< endl;
        cout<< "----------------"<< endl;
        cout<< "1) AGREGAR GÉNERO"<< endl;
        cout<< "2) LISTAR GÉNERO POR ID"<< endl;
        cout<< "3) LISTAR TODO"<< endl;
        cout<< "4) MODIFICAR AÑO DE ORIGEN"<< endl;
        cout<< "5) ELIMINAR REGISTRO"<< endl;
        cout<< "-------------------------------------"<< endl;
        cout<< "0) VOLVER AL MENU PRINCIPAL"<< endl;
        cout<< "-------------------------------------"<< endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
         cin >> opci;

        switch(opci){

            case 1: system("cls");
                    agrego=archi2.agregarGenero();
                    if(agrego) cout<<"SE AGREGO CORRECTAMENTE EL GENERO."<<endl;
                    else {cout<<"NO SE PUDO AGREGAR EL GENERO."<<endl;}
                    break;

            case 2: system("cls");
                    cout<<"Ingrese el ID: ";
                    cin>>id;
                    cout<<endl;
                    encontro=archi2.mostrarID_Buscado(id);
                    cout<<endl;
                    if(encontro==false)cout<<"NO SE A ENCONTRADO REGISTRO CON ESE ID."<<endl;
                    break;

            case 3: system("cls");
                    archi2.mostrarRegistroGenero();
                    break;

            case 4: system("cls");
                    modifico=archi2.modificarAnioOrigen();
                    cout<<endl;
                    if(modifico)cout<<"SE CAMBIO EL AÑO CORRECTAMENTE"<<endl;
                    else{cout<<"NO SE PUDO REALIZAR LA MODIFICACION."<<endl;}
                    break;

            case 5: system("cls");
                    baja=archi2.bajaLogicaGenero();
                    if(baja)cout<<"BAJA REALIZADA"<<endl;
                    else{cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;}
                    break;

            case 0: return;

        }
    system("pause");
    system("cls");
    }
//return;
}

#endif // SUBMENUGENEROS_H_INCLUDED
