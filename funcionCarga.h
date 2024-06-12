#include <iostream>
#include "rlutil.h"
#define ROJO     "\033[31m" //ROJO
#define RESET   "\033[0m" //RESETEAR

using namespace std;

///DECLARACION DE FUNCIONES

void pedirBarcos(int tamBarco,char (&mPlayer1)[7][7],string jugador);

void imprimirTablero(char (&mPlayer)[7][7]);

void avisoCargaFlota(string nombreJugador);

void asignacionMatrizCarga(int &fila, int &columna,char (&matriz)[7][7], bool direccion, int tamBarco);

int colorTablero(char (&matriz)[7][7],bool direccion, int tamBarco);

///FUNCIONES:


//FUNCION PARA PEDIR LOS BARCOS DE TRES UNIDADES

void pedirBarcos(int tamBarco,char (&mPlayer)[7][7], string jugador)
{
    int fila, columna,banderaEspacioError,cantidadCasilleros;
    int i, x;
    char caracter;
    bool direccion;

    switch (tamBarco)
    {

    case 4:
        cantidadCasilleros = 4;
        caracter = 'X';
        x = 1;
        break;

    case 3:
        cantidadCasilleros = 3;
        caracter = 'Y';
        x = 1;
        break;

    case 2:
        cantidadCasilleros = 2;
        caracter = 'Z';
        x = 2;
        break;

    case 1:
        cantidadCasilleros = 2;
        caracter = 'Q';
        x = 1;
        break;
    }

    avisoCargaFlota(jugador);
    imprimirTablero(mPlayer);

    cout<<endl<<"Barcos de "<<cantidadCasilleros<<" unidades disponibles: "<< x <<endl;

    rlutil::locate(40,28);
    cout<<"DE QUE MANERA QUIERES POSICIONAR ESTE BARCO?";
    direccion = botones(3);

    asignacionMatrizCarga(fila, columna, mPlayer, direccion, cantidadCasilleros);

    //--> VALIDACION DE POSICION INGRESADA TANTO SI ES MAYOR A SIETE O SI ESTA REPETIDA

    banderaEspacioError = 0;

    while(banderaEspacioError == 0)
    {

        if(direccion == 0)
        {
            for(i = columna; i < columna+cantidadCasilleros; i++)
            {
                if(mPlayer[fila-1][i-1] != '-')
                {
                    system("cls");
                    avisoCargaFlota(jugador);
                    imprimirTablero(mPlayer);

                    rlutil::locate(30,8);
                    cout<<ROJO<<"------->> ESTE ESPACIO YA ESTA ASIGNADO, TEN MAS CUIDADO MARINERO! <<-------"<<RESET<<endl<<endl;
                    rlutil::locate(40,28);
                    cout<<"DE QUE MANERA QUIERES POSICIONAR ESTE BARCO?";
                    direccion = botones(3);

                    asignacionMatrizCarga(fila, columna,mPlayer,direccion, cantidadCasilleros);
                    banderaEspacioError = 0;
                    break;
                }
                else if(columna+cantidadCasilleros > 8)
                {
                    system("cls");
                    avisoCargaFlota(jugador);
                    imprimirTablero(mPlayer);

                    rlutil::locate(30,8);
                    cout<<ROJO<<"------->> ESTE ESPACIO NO EXISTE, TEN MAS CUIDADO MARINERO! <<-------"<<RESET<<endl<<endl;
                    rlutil::locate(40,28);
                    cout<<"DE QUE MANERA QUIERES POSICIONAR ESTE BARCO?";
                    direccion = botones(3);

                    asignacionMatrizCarga(fila, columna,mPlayer,direccion, cantidadCasilleros);
                }
                else
                {
                    banderaEspacioError = 1;
                }
            }
        }
        else if(direccion == 1)
        {
            for(i = fila; i < fila+cantidadCasilleros; i++)
            {
                if(mPlayer[i-1][columna-1] != '-')
                {
                    system("cls");
                    avisoCargaFlota(jugador);
                    imprimirTablero(mPlayer);

                    rlutil::locate(30,8);
                    cout<<ROJO<<"------->> ESTE ESPACIO YA ESTA ASIGNADO, TEN MAS CUIDADO MARINERO! <<-------"<<RESET<<endl;
                    rlutil::locate(40,28);
                    cout<<"DE QUE MANERA QUIERES POSICIONAR ESTE BARCO?";
                    direccion = botones(3);

                    asignacionMatrizCarga(fila, columna, mPlayer,direccion, cantidadCasilleros);

                    banderaEspacioError = 0;
                    break;
                }
                else if(fila+cantidadCasilleros > 8)
                {
                    system("cls");
                    avisoCargaFlota(jugador);
                    imprimirTablero(mPlayer);

                    rlutil::locate(30,8);
                    cout<<ROJO<<"------->> ESTE ESPACIO NO EXISTE, TEN MAS CUIDADO MARINERO! <<-------"<<RESET<<endl<<endl;
                    rlutil::locate(40,28);
                    cout<<"DE QUE MANERA QUIERES POSICIONAR ESTE BARCO?";
                    direccion = botones(3);

                    asignacionMatrizCarga(fila, columna, mPlayer,direccion, cantidadCasilleros);
                }
                else
                {
                    banderaEspacioError = 1;
                }
            }
        }
        else
        {
            banderaEspacioError = 1;

        }
    }


    if(direccion == 0)//ASIGNACION DE LOS VALORES INGRESADOS A LA MATRIZ
    {
        for(i = columna; i < columna+cantidadCasilleros; i++)
        {
            mPlayer[fila-1][i-1] = caracter;
        }
    }
    else
    {
        for(i = fila; i < fila+cantidadCasilleros; i++)
        {
            mPlayer[i-1][columna-1] = caracter;
        }
    }


    system("cls");

}



void asignacionMatrizCarga(int &fila, int &columna, char (&matriz)[7][7], bool direccion, int tamBarco)
{
    int casilla;
    casilla = colorTablero(matriz,direccion,tamBarco)+1;
    if(casilla <= 7)
    {
        fila = 1;
        columna = casilla;
    }
    else if(casilla <= 14)
    {
        fila = 2;
        columna = casilla-7;
    }
    else if(casilla <=21)
    {
        fila = 3;
        columna = casilla-14;
    }
    else if(casilla <=28)
    {
        fila = 4;
        columna = casilla-21;
    }
    else if(casilla <= 35)
    {
        fila = 5;
        columna = casilla-28;
    }
    else if(casilla <= 42)
    {
        fila = 6;
        columna = casilla-35;
    }
    else
    {
        fila = 7;
        columna = casilla-42;
    }

}

