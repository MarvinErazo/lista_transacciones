/*TRANSACIONES BANCARIAS

OBJETIVO: Control de una lista de depositos y retiros de
una cuenta bancaria que implemente:

estado de la cuenta
suma de depositos
suma de retiros
historial de depositos en el dia
hitorial de retiros en el dia

Autor: Marvin Erazo
Version 1.0

fecha: 14/11/2019

*/

//======LIBRERIAS=======
#include<iostream>
#include<stdlib.h>
#include<windows.h>

using namespace std;

//======VARIABLES GLOBALES Y ESTRUCUTRAS=======
int totdeb;
int totret;
int estado;

typedef struct Tcredito{
    int credito;

    Tcredito *sig;
};
Tcredito *cabC,*auxcabC;

typedef struct Tdebito{
    int debito;
    Tdebito *sig;
};
Tdebito *cabD,*auxcabD;

//========DECLARACION DE FUNCIONES======

int ingresarCredito(Tcredito *,int);
int ingresarDebito(Tdebito *,int);
int historialCreditos(Tcredito*);
int historialDebitos(Tdebito *);
int totalCreditos(Tcredito *);
int totalDebitos(Tdebito *);
int ingresarMonto();
int menu();

//=====FUNCON PRINICPAL ========
int main(){
    cabC=NULL;
    cabD=NULL;
    int op;
    int saldoI;

    cout<<"INGRESE EL SALDO INICAL";
    saldoI=ingresarMonto();
    estado=saldoI;

    do{
       op=menu();
        switch (op){

            case 1: {
                int cred;
                system("cls");
                cout<<"Ingrese credito ";
                cred=ingresarMonto();
                estado=estado+cred;
                ingresarCredito(cabC,cred);
            break;}

            case 2: {
                int deb;
                system("cls");
                cout<<"Ingrese debito ";
                deb=ingresarMonto();
                estado=estado-deb;
                ingresarDebito(cabD,deb);
            break;}

            case 3: {
                system("cls");
                historialCreditos(cabC);
                system("pause");
            break;}

            case 4: {
                system("cls");
                historialDebitos(cabD);
                system("pause");
            break;}

            case 5: {
                system("cls");
                cout<<"SU SALDO TOTAL DE CREDITOS ES: "<< totalCreditos(cabC)<<endl;
                system("pause");
            break;}

            case 6: {
                system("cls");
                cout<<"SU SALDO TOTAL DE DEBITOS ES: "<< totalDebitos(cabD)<<endl;
                system("pause");
            break;}

            case 7: {
                system("cls");
                cout<<"SU SALDO ACTUAL ES DE: "<< estado<<endl;
                system("pause");

            break;}

        }
        system("cls");
    }while(op!=8);


}

//=======INTANCIACION DE FUNCIONES===================
int menu(){
    int op;
    cout<<"============BANCO============"<<endl;
    cout<<"1: Credito"<<endl;
    cout<<"2: Debito"<<endl;
    cout<<"3: Historial de creditos"<<endl;
    cout<<"4: Historial de debitos"<<endl;
    cout<<"5: Total de creditos"<<endl;
    cout<<"6: Total de debitos"<<endl;
    cout<<"7: Estado de cuenta"<<endl;
    cout<<"8: Salir"<<endl;
    do{
        cout<<"=> ";
        cin>>op;
    }while(op<1 || op >8);

    return op;
}

int ingresarMonto(){
    int monto;
    do{
        cout<<"=> ";
        cin>>monto;
    }while(monto<0);
    return monto;
}

int ingresarCredito(Tcredito *pcredito,int credito){
    pcredito=new Tcredito;

    pcredito->credito=credito;
    pcredito->sig=cabC;
    cabC=pcredito;

    return 1;
}

int ingresarDebito(Tdebito *pdebito,int debito){
    pdebito=new Tdebito;

    pdebito->debito=debito;
    pdebito->sig=cabD;
    cabD=pdebito;

    return 1;
}

int historialCreditos(Tcredito *pcredito){
    auxcabC = pcredito;
    int cont=1;
	cout << endl << "=====HISTORIAL DE CREDITOS ======="<<endl;
	do{

        cout<<cont<<"=> "<<auxcabC->credito;
        cont++;
        cout<<endl;
        auxcabC=auxcabC->sig;
   }	while(auxcabC!=NULL);

    return 1;
}

int historialDebitos(Tdebito *pdebito){
    auxcabD = pdebito;
    int cont=1;
	cout << endl << "=====HISTORIAL DE DEBITOS ======="<<endl;
	do{
        cout<<cont<<"=> "<<auxcabD->debito;
        cont++;
        cout<<endl;
        auxcabD=auxcabD->sig;
   }	while(auxcabD!=NULL);

    return 1;
}

int totalCreditos(Tcredito *pcredito){
    auxcabC = pcredito;
    int sum=0;
    do{
        sum=sum+auxcabC->credito;
        auxcabC=auxcabC->sig;
   }while(auxcabC!=NULL);

   return sum;

}

int totalDebitos(Tdebito *pdebito){
    auxcabD = pdebito;
    int sum=0;
    do{
        sum=sum+auxcabD->debito;
        auxcabD=auxcabD->sig;
   }while(auxcabD!=NULL);

   return sum;

}
