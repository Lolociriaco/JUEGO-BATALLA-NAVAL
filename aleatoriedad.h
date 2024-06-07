#include <iostream>
#include <cstdlib>  // para rand() y srand()
#include <ctime>    // para time()
#include <thread>  // para std::this_thread::sleep_for
#include <chrono>
#include <time.h>


void cargaAutomatica(int tamBarco,char (&mPlayer)[7][7])
{
    int columna, fila, direccion, cantidadCasilleros, banderaEspacioError;
    int TAM = 7;
    char caracter;
    srand(time(NULL));

    switch (tamBarco)
    {

    case 4:
        cantidadCasilleros = 4;
        caracter = 'X';
        break;

    case 3:
        cantidadCasilleros = 3;
        caracter = 'Y';
        break;

    case 2:
        cantidadCasilleros = 2;
        caracter = 'Z';
        break;

    case 1:
        cantidadCasilleros = 2;
        caracter = 'Q';
        break;
    }

        direccion = rand()% 2 + 1;
        fila = rand()% TAM + 1;
        columna = rand()% TAM + 1;

        //--> VALIDACION DE POSICION INGRESADA TANTO SI ES MAYOR A SIETE O SI ESTA REPETIDA

        banderaEspacioError = 0;

            while(banderaEspacioError == 0)
            {
                direccion = rand()% 2 + 1;
                fila = rand()% TAM + 1;
                columna = rand()% TAM + 1;
                if(direccion == 1)
                {
                    for(int i = columna; i < columna+cantidadCasilleros; i++)
                    {
                        if(mPlayer[fila-1][i-1] != '-')
                        {
                            banderaEspacioError = 0;
                            break;
                        }
                         else if(columna+cantidadCasilleros > 8)
                        {
                            banderaEspacioError = 0;
                            break;
                        }
                        else
                        {
                            banderaEspacioError = 1;
                        }
                    }
                }
                else if(direccion == 2)
                {
                    for(int i = fila; i < fila+cantidadCasilleros; i++)
                    {
                        if(mPlayer[i-1][columna-1] != '-')
                        {
                            banderaEspacioError = 0;
                            break;
                        }
                        else if(fila+cantidadCasilleros > 8)
                        {
                            banderaEspacioError = 0;
                            break;
                        }
                        else
                        {
                            banderaEspacioError = 1;
                        }
                    }
                }
            }

        //ASIGNACION DE LOS VALORES INGRESADOS A LA MATRIZ

        if(direccion == 1)
        {
            for(int i = columna; i < columna+cantidadCasilleros; i++)
            {
                mPlayer[fila-1][i-1] = caracter;
            }
        }
        else
        {
            for(int i = fila; i < fila+cantidadCasilleros; i++)
            {
                mPlayer[i-1][columna-1] = caracter;
            }
        }
        system("cls");
}

