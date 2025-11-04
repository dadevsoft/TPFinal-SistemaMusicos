#ifndef SUBMENUPAISES_H_INCLUDED
#define SUBMENUPAISES_H_INCLUDED

void subMenuPaises(){
setlocale(LC_ALL,"Spanish");
    ArchivoPaises archi4(ARCHIVO_PAISES);
    int opci, id;
    bool agrego, encontro, modifico, baja;
    while(true){
        cout<< " MENU PAISES"<< endl;
        cout<< "----------------"<< endl;
        cout<< "1) AGREGAR PAIS"<< endl;
        cout<< "2) LISTAR PAIS POR ID"<< endl;
        cout<< "3) LISTAR TODO"<< endl;
        cout<< "4) MODIFICAR NOMBRE"<< endl;
        cout<< "5) ELIMINAR REGISTRO"<< endl;
        cout<< "-------------------------------------"<< endl;
        cout<< "0) VOLVER AL MENU PRINCIPAL"<< endl;
        cout<< "-------------------------------------"<< endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
         cin >> opci;

        switch(opci){

            case 1: system("cls");
                    agrego=archi4.agregarPais();
                    if(agrego) cout<<"SE AGREGO CORRECTAMENTE EL PAIS."<<endl;
                    else {cout<<"NO SE PUDO AGREGAR EL PAIS."<<endl;}
                    break;

            case 2: system("cls");
                    cout<<"Ingrese el ID: ";
                    cin>>id;
                    cout<<endl;
                    encontro=archi4.mostrarID_Buscado(id);
                    cout<<endl;
                    if(encontro==false)cout<<"NO SE A ENCONTRADO REGISTRO CON ESE ID."<<endl;
                    break;

            case 3: system("cls");
                    archi4.mostrarRegistroPais();
                    break;

            case 4: system("cls");
                    modifico=archi4.modificarNombre();
                    cout<<endl;
                    if(modifico)cout<<"SE CAMBIO EL NOMBRE CORRECTAMENTE"<<endl;
                    else{cout<<"NO SE PUDO REALIZAR LA MODIFICACION DEL NOMBRE."<<endl;}
                    break;

            case 5: system("cls");
                    baja=archi4.bajaLogicaPais();
                    if(baja)cout<<"BAJA REALIZADA"<<endl;
                    else{cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;}
                    break;

            case 0: return;

        }
    system("pause");
    system("cls");
    }
return;
}

#endif // SUBMENUPAISES_H_INCLUDED
