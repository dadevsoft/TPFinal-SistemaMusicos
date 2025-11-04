#ifndef SUBMENUINSTRUMENTOS_H_INCLUDED
#define SUBMENUINSTRUMENTOS_H_INCLUDED

/*

*/

void subMenuIntrumentos(){
setlocale(LC_ALL,"Spanish");
    ArchivoInstrumentos archi3(ARCHIVO_INSTRUMENTOS);
    int opci, id;
    bool agrego, encontro, modifico, baja;
    while(true){
        cout<< " MENU INSTRUMENTOS"<< endl;
        cout<< "----------------"<< endl;
        cout<< "1) AGREGAR INSTRUMENTO"<< endl;
        cout<< "2) LISTAR INSTRUMENTO POR ID"<< endl;
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
                    agrego=archi3.agregarInstrumento();
                    if(agrego) cout<<"SE AGREGO CORRECTAMENTE EL INSTRUMENTO."<<endl;
                    else {cout<<"NO SE PUDO AGREGAR EL INSTRUMENTO."<<endl;}
                    break;

            case 2: system("cls");
                    cout<<"Ingrese el ID: ";
                    cin>>id;
                    cout<<endl;
                    encontro=archi3.mostrarID_Buscado(id);
                    cout<<endl;
                    if(encontro==false)cout<<"NO SE A ENCONTRADO REGISTRO CON ESE ID."<<endl;
                    break;

            case 3: system("cls");
                    archi3.mostrarRegistroInstrumento();
                    break;

            case 4: system("cls");
                    modifico=archi3.modificarNombre();
                    cout<<endl;
                    if(modifico)cout<<"SE CAMBIO EL NOMBRE CORRECTAMENTE"<<endl;
                    else{cout<<"NO SE PUDO REALIZAR LA MODIFICACION DEL NOMBRE."<<endl;}
                    break;

            case 5: system("cls");
                    baja=archi3.bajaLogicaInstrumento();
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

#endif // SUBMENUINSTRUMENTOS_H_INCLUDED
