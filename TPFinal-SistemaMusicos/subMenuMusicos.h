#ifndef SUBMENUMUSICOS_H_INCLUDED
#define SUBMENUMUSICOS_H_INCLUDED

void subMenuMusicos(){
setlocale(LC_ALL,"Spanish");
    ArchivoMusicos archi(ARCHIVO_MUSICOS);
    int opci, dni;
    bool agrego, encontro, modifico, baja;
    while(true){
        cout<< " ------- MENU MUSICOS -------- "  << endl;
        cout<< "1) AGREGAR MUSICOS"<< endl;
        cout<< "2) LISTAR MUSICO POR DNI"<< endl;
        cout<< "3) LISTAR TODOS LOS MUSICOS"<< endl;
        cout<< "4) MODIFICAR FECHA DE INSCRIPCION"<< endl;
        cout<< "5) ELIMINAR MUSICO"<< endl;
        cout<< "---------------------------------"<< endl;
        cout<< "0) VOLVER AL MENU PRINCIPAL"<< endl;
        cout<< "---------------------------------"<< endl;
        cout<<" SELECCIONE UNA DE LAS OPCIONES: ";
         cin >> opci;

        switch(opci){

            case 1: system("cls");
                    agrego=archi.agregarMusico();
                    if(agrego) cout<<"EL MUSICO SE AGREGO CORRECTAMENTE."<<endl;
                    else {cout<<"NO SE PUDO AGREGAR EL MUSICO."<<endl;}
                    break;

            case 2: system("cls");
                    cout<<"Ingrese DNI: "<<endl;
                    cin>>dni;
                    cout<<endl;
                    encontro=archi.MostrarDNI_buscado(dni);
                    cout<<endl;
                    if(encontro)cout<<"Se encontro el registro con el dni: "<<dni<<endl;
                    else{cout<<"NO SE AH ENCONTRADO REGISTRO CON ESE DNI."<<endl;}
                    break;

            case 3: system("cls");
                    archi.mostrarRegistroMusico();
                    break;

            case 4: system("cls");
                    modifico=archi.modificarFechaInscripcion();
                    cout<<endl;
                    if(modifico)cout<<"Se cambio la fecha correctamente"<<endl;
                    else{cout<<"NO SE PUDO REALIZAR LA MODIFICACION."<<endl;}
                    break;

            case 5: system("cls");
                    baja=archi.bajaLogicaMusico();
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

#endif // SUBMENUMUSICOS_H_INCLUDED
