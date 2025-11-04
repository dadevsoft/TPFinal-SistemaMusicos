#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

//Prototipos
bool copiaSeguridadMusicos();
bool copiaSeguridadGeneros();
bool copiaSeguridadInstrumentos();
bool copiaSeguridadPaises();


bool restauArchivoMusicos();
bool restauArchivoGeneros();
bool restauArchivoInstrumentos();
bool restauArchivoPaises();


bool establecerDatosDeInicioPaso1();
bool establecerDatosDeInicioPaso2();

void subMenuConfiguracion(){
setlocale(LC_ALL,"Spanish");
    ArchivoMusicos archi1(ARCHIVO_MUSICOS);
    ArchivoGeneros archi2(ARCHIVO_GENEROS);

    int opci;
    bool copiMusi, copiGene, copI, copP, restauMusi, restauGene, restIn, restP;
    while(true){
        cout<< " MENU CONFIGURACIÓN"<< endl;
        cout<< "----------------"<< endl;
        cout<< "1) COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS"<< endl;
        cout<< "2) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<< endl;
        cout<< "3) COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUMENTOS"<< endl;
        cout<< "4) COPIA DE SEGURIDAD DEL ARCHIVO DE PAISES "<< endl;
        cout<< "5) RESTAURAR EL ARCHIVO DE MUSICOS"<< endl;
        cout<< "6) RESTAURAR EL ARCHIVO DE GENEROS"<< endl;
        cout<< "7) RESTAURAR EL ARCHIVO DE INSTRUMENTOS"<< endl;
        cout<< "8) RESTAURAR EL ARCHIVO DE PAISES"<< endl;
        cout<< "9) ESTABLECER DATOS DE INICIO"<< endl;
        cout<< "-------------------------------------"<< endl;
        cout<< "0) VOLVER AL MENU PRINCIPAL"<< endl;
        cout<< "-------------------------------------"<< endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opci;

        switch(opci){

            case 1: system("cls");
                    copiMusi=copiaSeguridadMusicos();
                    cout<<endl;
                    if(copiMusi) cout<<"SE REALIZO LA COPIA DEL ARCHIVO MUSICOS .dat-->.bkp"<<endl;
                    else {cout<<"NO SE PUDO REALIZAR LA COPIA DEL ARCHIVO MUSICOS."<<endl;}
                    break;

            case 2: system("cls");
                    copiGene=copiaSeguridadGeneros();
                    cout<<endl;
                    if(copiGene) cout<<"SE REALIZO LA COPIA DEL ARCHIVO GENEROS.dat-->.bkp"<<endl;
                    else {cout<<"NO SE PUDO REALIZAR LA COPIA DEL ARCHIVO GENEROS."<<endl;}
                    break;

            case 3: system("cls");
                    copI=copiaSeguridadInstrumentos();
                    cout<<endl;
                    if(copI) cout<<"SE REALIZO LA COPIA DEL ARCHIVO INSTRUMENTOS.dat-->.bkp"<<endl;
                    else {cout<<"NO SE PUDO REALIZAR LA COPIA DEL ARCHIVO INSTRUMENTOS."<<endl;}
                    break;

            case 4: system("cls");
                    copP=copiaSeguridadPaises();
                    cout<<endl;
                    if(copP) cout<<"SE REALIZO LA COPIA DEL ARCHIVO PAISES.dat-->.bkp"<<endl;
                    else {cout<<"NO SE PUDO REALIZAR LA COPIA DEL ARCHIVO PAISES."<<endl;}
                    break;


            case 5: system("cls");
                    restauMusi=restauArchivoMusicos();
                    cout<<endl;
                    if(restauMusi) cout<<"SE REALIZO LA RESTAURACION DEL ARCHIVO MUSICOS."<<endl;
                    else {cout<<"NO SE PUDO REALIZAR LA RESTAURACION DEL ARCHIVO MUSICOS."<<endl;}
                    break;

            case 6: system("cls");
                    restauGene=restauArchivoGeneros();
                    cout<<endl;
                    if(restauGene) cout<<"SE REALIZO LA RESTAURACION DEL ARCHIVO GENEROS."<<endl;
                    else {cout<<"NO SE PUDO REALIZAR LA RESTAURACION DEL ARCHIVO GENEROS."<<endl;}
                    break;

            case 7: system("cls");
                    restIn=restauArchivoInstrumentos();
                    cout<<endl;
                    if(restIn) cout<<"SE REALIZO LA RESTAURACION DEL ARCHIVO INSTRUMENTOS."<<endl;
                    else {cout<<"NO SE PUDO REALIZAR LA RESTAURACION DEL ARCHIVO INSTRUMENTOS."<<endl;}
                    break;

            case 8: system("cls");
                    restP=restauArchivoPaises();
                    cout<<endl;
                    if(restP) cout<<"SE REALIZO LA RESTAURACION DEL ARCHIVO PAISES."<<endl;
                    else {cout<<"NO SE PUDO REALIZAR LA RESTAURACION DEL ARCHIVO PAISES."<<endl;}
                    break;

            case 9: system("cls");
                    establecerDatosDeInicioPaso1();
                    establecerDatosDeInicioPaso2();
                    break;

            case 0: return;

        }
    system("pause");
    system("cls");
    }

return;

}

//FUNCIONES
bool copiaSeguridadMusicos(){//SE COPIAN LOS REGISTROS DEL .DAT AL .BKP
    Musicos registroMusi;
    FILE *muArchivo, *punteroBack;

    //Abro el archivo.DAT
    muArchivo=fopen("musicos.dat","rb");
    if(muArchivo==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    //Creo el archivo .BKP
    punteroBack=fopen("musicos.bkp","wb");
    if(punteroBack==NULL){
        cout<<"No se pudo crear el archivo de seguridad"<<endl;
        fclose(muArchivo);
        return false;
    }
    //Leo el archivo .DAT y mientras el valor de la funcion freed sea 1(encontro un registro)lo va a escribir en el .BKP
    while(fread(&registroMusi, sizeof registroMusi, 1, muArchivo)==1){
        fwrite(&registroMusi, sizeof registroMusi, 1, punteroBack);
    }
    fclose(punteroBack);
    fclose(muArchivo);
return true;

}

bool copiaSeguridadGeneros(){//SE COPIAN LOS REGISTROS DEL .DAT AL .BKP
    Generos registroGen;
    FILE *pGenero, *pBackGen;

    //Abro el archivo.DAT
    pGenero=fopen("generos.dat","rb");
    if(pGenero==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    //Creo el archivo .BKP
    pBackGen=fopen("generos.bkp","wb");
    if(pBackGen==NULL){
        cout<<"No se pudo crear el archivo de seguridad"<<endl;
        fclose(pGenero);
        return false;
    }
    while(fread(&registroGen, sizeof registroGen, 1, pGenero)==1){
        fwrite(&registroGen, sizeof registroGen, 1, pBackGen);
    }
    fclose(pBackGen);
    fclose(pGenero);
return true;
}

bool copiaSeguridadInstrumentos(){

    Instrumentos regIn;
    FILE *pI, *pBackIn;

    //Abro el archivo.DAT
    pI=fopen("instrumentos.dat","rb");
    if(pI==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    //Creo el archivo .BKP
    pBackIn=fopen("instrumentos.bkp","wb");
    if(pBackIn==NULL){
        cout<<"No se pudo crear el archivo de seguridad"<<endl;
        fclose(pI);
        return false;
    }
    while(fread(&regIn, sizeof regIn, 1, pI)==1){
        fwrite(&regIn, sizeof regIn, 1, pBackIn);
    }
    fclose(pBackIn);
    fclose(pI);
return true;
}

bool copiaSeguridadPaises(){

    Pais regP;
    FILE *p, *pBackPa;

    //Abro el archivo.DAT
    p=fopen("paises.dat","rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    //Creo el archivo .BKP
    pBackPa=fopen("paises.bkp","wb");
    if(pBackPa==NULL){
        cout<<"No se pudo crear el archivo de seguridad"<<endl;
        fclose(p);
        return false;
    }
    while(fread(&regP, sizeof regP, 1, p)==1){
        fwrite(&regP, sizeof regP, 1, pBackPa);
    }
    fclose(pBackPa);
    fclose(p);
return true;
}

bool restauArchivoMusicos(){
    Musicos registroMusi;
    FILE *muArchivo, *punteroBack;

    muArchivo=fopen("musicos.dat","wb");
    punteroBack=fopen("musicos.bkp","rb");

    if(muArchivo==NULL || punteroBack == NULL){
            return false;
    }
    while(fread(&registroMusi, sizeof registroMusi, 1, punteroBack)==1){
        fwrite(&registroMusi, sizeof registroMusi, 1, muArchivo);
    }
    fclose(punteroBack);
    fclose(muArchivo);
return true;
}

bool restauArchivoGeneros(){

    Generos registroGen;
    FILE *ArchivoGen, *pBack;

    ArchivoGen=fopen("generos.dat","wb");//vacio
    pBack=fopen("generos.bkp","rb");

    if(ArchivoGen==NULL || pBack == NULL){
        return false;
    }
    while(fread(&registroGen, sizeof registroGen, 1, pBack)==1){
        fwrite(&registroGen, sizeof registroGen, 1, ArchivoGen);
    }
    fclose(pBack);
    fclose(ArchivoGen);
return true;

}

bool restauArchivoInstrumentos(){

    Instrumentos regIn;
    FILE *aIn, *pBack;

    aIn=fopen("instrumentos.dat","wb");//vacio
    pBack=fopen("instrumentos.bkp","rb");

    if(aIn==NULL || pBack == NULL){
        return false;
    }
    while(fread(&regIn, sizeof regIn, 1, pBack)==1){
        fwrite(&regIn, sizeof regIn, 1, aIn);
    }
    fclose(pBack);
    fclose(aIn);
return true;

}

bool restauArchivoPaises(){

    Pais regP;
    FILE *aP, *pBack;

    aP=fopen("paises.dat","wb");//vacio
    pBack=fopen("paises.bkp","rb");

    if(aP==NULL || pBack == NULL){
        return false;
    }
    while(fread(&regP, sizeof regP, 1, pBack)==1){
        fwrite(&regP, sizeof regP, 1, aP);
    }
    fclose(pBack);
    fclose(aP);
return true;
}

bool establecerDatosDeInicioPaso1(){ // .DAT => .INI
//TODOS LOS ARCHIVOS->MUSICOS, GENEROS, INSTRUMENTOS, PAISES- se escriben en su propio.INI->datos por default
    Musicos musico;
    Generos genero;
    Instrumentos instrumento;
    Pais pais;

    FILE *m,*g,*i,*p;

    m = fopen("Musicos.ini", "wb");
    g = fopen("Generos.ini", "wb");
    i = fopen("Instrumentos.ini", "wb");
    p = fopen("Paises.ini", "wb");



    /// VALIDAR SI SE PUDO ABRIR EL ARCHIVO.

    if(m==NULL || g == NULL || i == NULL || p == NULL){
        return false;
    }

    ArchivoMusicos aMusico(ARCHIVO_MUSICOS);
    ArchivoGeneros aGenero(ARCHIVO_GENEROS);
    ArchivoInstrumentos aInstru(ARCHIVO_INSTRUMENTOS);
    ArchivoPaises aPaises(ARCHIVO_PAISES);

    int cantMusico = aMusico.contarRegistros();
    int cantGeneros = aGenero.contarRegistros();
    int cantInstrumentos = aInstru.contarRegistros();
    int cantPaises = aPaises.contarRegistros();

    for(int i = 0; i <cantMusico; i++){
        musico = aMusico.leerRegistro(i);
        fwrite(&musico, sizeof musico, 1, m);
    }

    for(int i= 0; i<cantGeneros; i++){
        genero = aGenero.leerRegistro(i);
        fwrite(&genero,sizeof genero,1,g);
    }

    for(int j=0; j<cantInstrumentos; j++){
        instrumento = aInstru.leerRegistro(j);
        fwrite(&instrumento,sizeof instrumento,1,i);
    }
    for(int i=0; i<cantPaises; i++){
        pais = aPaises.leerRegistro(i);
        fwrite(&pais,sizeof pais,1,p);
    }

   /* while(fread(&pais, sizeof pais, 1,pDat)==1){ //HACE LO MISMO QUE EL FOR
            fwrite(&pais, sizeof pais, 1, p);
    }*/

    fclose(m);
    fclose(g);
    fclose(i);
    fclose(p);
return true;
}

bool establecerDatosDeInicioPaso2(){ // .INI => .DAT

    Musicos musico;
    Generos genero;
    Instrumentos instrumento;
    Pais pais;

    ArchivoMusicos aMusico("Musicos.ini");
    ArchivoGeneros aGenero("Generos.ini");
    ArchivoInstrumentos aInstru("Instrumentos.ini");
    ArchivoPaises aPais("Paises.ini");

    FILE *pIni, *mDat, *gDat, *iDat,*pDat;

    mDat = fopen(ARCHIVO_MUSICOS,"wb");
    gDat = fopen(ARCHIVO_GENEROS,"wb");
    iDat = fopen(ARCHIVO_INSTRUMENTOS,"wb");
    pDat = fopen(ARCHIVO_PAISES,"wb");


    ///VALIDAR APERTURAS
    if(mDat==NULL || gDat == NULL || iDat == NULL || pDat == NULL){
        return false;
    }

    int cantMusico = aMusico.contarRegistros();
    int cantGeneros = aGenero.contarRegistros();
    int cantInstrumentos = aInstru.contarRegistros();
    int cantPaises = aPais.contarRegistros();


    for(int i = 0; i <cantMusico; i++){
        musico = aMusico.leerRegistro(i); //ini
        fwrite(&musico, sizeof musico, 1, mDat);
    }
    for(int i= 0; i<cantGeneros; i++){
        genero = aGenero.leerRegistro(i);
        fwrite(&genero,sizeof genero,1, gDat);
    }

    for(int j=0; j<cantInstrumentos; j++){
        instrumento = aInstru.leerRegistro(j);
        fwrite(&instrumento,sizeof instrumento,1,iDat);
    }
    for(int i=0; i<cantPaises; i++){
        pais = aPais.leerRegistro(i);
        fwrite(&pais,sizeof pais,1,pDat);
    }


    fclose(mDat);
    fclose(gDat);
    fclose(iDat);
    fclose(pDat);
return true;
}



#endif // SUBMENUCONFIGURACION_H_INCLUDED
