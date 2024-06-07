#include <iostream>
#include <chrono>   // Para sleep
#include <thread>   // Para sleep

// FUNCIONES
#include "funcionesGraficas.h"
#include "funcionCarga.h"
#include "IU.h"
#include "funcionProceso.h"
#include "funcionesExtras.h"
#include "aleatoriedad.h"

using namespace std;

int main()
{
    rlutil::hidecursor();

    //Declaro las variables
    bool ejecucion = 1;
    int puntosGanador = 1000;
    string jugador1;
    string jugador2;
    string ganador;
    char mPlayer1[7][7];
    char mPlayer2[7][7];
    char matrizVisualPlayer1[7][7];
    char matrizVisualPlayer2[7][7];


    //PANTALLA DE BIENVENIDA

    CartelDeInicio();

    //FUNCION MENU y LOGICA PARA APAGAR EL JUEGO

    while(ejecucion == 1)
    {
        switch (ejecMenu())
        {
        case 1:
        {
            ///WHILE DE CARGA Y JUEGO

            cargaNombreJugadores(jugador1,jugador2);    //FUNCION DE CARGA LOS NOMBRES DE LOS JUGADORES

            do //DO WHILE PARA VALIDAR QUE EL USUARIO ESTE SATISFECHO CON LA POSICION DE LOS BARCOS
            {

                inicializadorMatrizes(mPlayer1);    // FUNCION PARA ESTABLECER LA MATRIZ EN #

                if(confCargaAutomatica(jugador1) == 0)
                {

                    for(int BARC = 4;BARC >= 1; BARC--)     //FUNCIONES PARA PEDIR LOS BARCOS DEL PRIMER JUGADOR
                    {
                        pedirBarcos(BARC,mPlayer1,jugador1);
                    }
                }else
                {
                    for(int BARC = 4;BARC >= 1; BARC--)     //FUNCIONES PARA PEDIR LOS BARCOS DEL PRIMER JUGADOR
                    {

                        cargaAutomatica(BARC,mPlayer1);
                    }
                }

                cartelBattleship();
            }
            while(funValidacionBarcos(mPlayer1) == 0);

            do //DO WHILE PARA VALIDAR QUE EL USUARIO ESTE SATISFECHO CON LA POSICION DE LOS BARCOS
            {
                ///CARGA DE DATOS SEGUNDO JUGADOR

                system("cls");

                inicializadorMatrizes(mPlayer2);        // FUNCION PARA ESTABLECER LA MATRIZ EN #

                if(confCargaAutomatica(jugador2) == 0)
                {

                    for(int BARC = 4;BARC >= 1; BARC--)     //FUNCIONES PARA PEDIR LOS BARCOS DEL PRIMER JUGADOR
                    {
                        pedirBarcos(BARC,mPlayer2,jugador2);
                    }
                }else
                {
                    for(int BARC = 4;BARC >= 1; BARC--)     //FUNCIONES PARA PEDIR LOS BARCOS DEL PRIMER JUGADOR
                    {

                        cargaAutomatica(BARC,mPlayer2);
                    }
                }
                cartelBattleship();
            }
            while(funValidacionBarcos(mPlayer2) == 0);//VERIFICO QUE LA MATRIZ ESTE BIEN CARGADA

            ///COMIENZO GUERRA

            inicializadorMatrizes(matrizVisualPlayer1);     //CARGO LAS MATRIZES VISUALES CON '#'
            inicializadorMatrizes(matrizVisualPlayer2);

            while(1)
            {
                puntosGanador = imprimirComienzoBatalla(1,jugador1,matrizVisualPlayer1,mPlayer2);

                if(determinarGanador(matrizVisualPlayer1) == 11)
                {
                    ganador = jugador1;
                    break;
                }

                puntosGanador = imprimirComienzoBatalla(2,jugador2,matrizVisualPlayer2,mPlayer1);

                if(determinarGanador(matrizVisualPlayer2) == 11)
                {
                    ganador = jugador2;
                    break;
                }
            }

            felicitacionGanador(ganador, puntosGanador); //FUNCION PARA FELICITAR AL GANADOR

            //FUNCIONES DE OPCIONES DEL MENU

            break;
        }
        case 2:
        {
            cartelReglas();
            break;
        }
        case 3:
        {
            ejecucion = 0;
            cartelSalida();
            break;
        }

        default:
            break;
        }
    }

    return 0;

}












