#include <iostream>
#define RED     "\033[31m" //ROJO
#define RESET   "\033[0m" //RESETEAR
#define GREEN   "\033[32m" //VERDE
#define YELLOW "\033[33m" // Amarillo

using namespace std;

///DECLARACION DE FUNCIONES:

int imprimirComienzoBatalla(int NroJugador,string jugador, char (&matrizVisual)[7][7], char (&mPlayer)[7][7]);

void disparoRecibido(int disparos);

int mostrarPuntos(int tamBarco, int disparo);

//LLAMAR FUNCIONES DE OTROS HEADERS

void cartelBattleship();

//COMIENZO DE BATALLA

int imprimirComienzoBatalla(int NroJugador,string jugador, char (&matrizVisual)[7][7], char (&mPlayer)[7][7])
{
    int filaDisparo;
    int columnaDisparo;
    bool banderaDisparo;
    bool banderaEspacioAtacado;
    int contDisparosContinuos = 0;
    static int acuPuntosP1=0, acuPuntosP2=0;
    string anuncio;
    static int contadorAciertosN1 = 0;
    static int contadorAciertosN2 = 0;
    static int barcoXjugador1 = 0;
    static int barcoYjugador1 = 0;
    static int barcoQjugador1 = 0;
    static int barcoZjugador1 = 0;

    static int barcoXjugador2 = 0;
    static int barcoYjugador2 = 0;
    static int barcoQjugador2 = 0;
    static int barcoZjugador2 = 0;

    //CARGO UNA MATRIZ CON  Y CUANDO RECIBO UN DISPARO CAMBIO EL CARACTER A X OR O SI NO SE ENCONTRO EL BLANCO
    //UTILIZO UN DO WHILE PARA QUE EL JUGADOR PUEDA SEGUIR DISPARANDO MIENTRAS SIGA ACERTANDO LOS DISPAROS

    system("cls");

    do
    {
        cartelBattleship();
        //IMPRIMO EL TABLERO Y MUESTRO LOS DISPAROS RECIBIDOS, AGUAS Y CASILLEROS SIN ATACAR
        imprimirTablero(matrizVisual);

        if(NroJugador == 1)
        {
            rlutil::locate(46,29);
            cout<<GREEN<<"Cantidad de Aciertos "<<jugador<<": "<<contadorAciertosN1<<"/11"<<endl<<RESET;
            rlutil::locate(10,23);
            cout<<YELLOW<<"Pts Totales: "<<acuPuntosP1<<RESET;
        }
        else
        {
            rlutil::locate(46,29);
            cout<<GREEN<<"Cantidad de Aciertos "<<jugador<<": "<<contadorAciertosN2<<"/11"<<endl<<RESET;
            rlutil::locate(14,23);
            cout<<YELLOW<<"Pts Totales: "<<acuPuntosP2<<RESET;
        }


        //INGRESO COORDENADAS PARA LOS DISPAROS

        asignacionMatrizProceso(filaDisparo,columnaDisparo,matrizVisual);

        //LOGICA PARA ASEGURAR ESPACIO NO ATACADO ANTERIORMENTE

        banderaEspacioAtacado = 0;

        while(banderaEspacioAtacado == 0)
        {

            //VERIFICO SI LA POSICION NO A SIDO UTILIZADA

            if(matrizVisual[filaDisparo-1][columnaDisparo-1] == '-')
            {
                banderaEspacioAtacado = 1;
            }
            else //ALERTO DEL ERROR Y PIDO LOS DATOS NUEVAMENTE
            {
                rlutil::locate(31,31);
                cout<<RED<<"ESTA POSICION YA A SIDO BOMBARDEADA SOLDADO, TENGA MAS CUIDADO"<<RESET;
                asignacionMatrizProceso(filaDisparo,columnaDisparo,matrizVisual);
            }

        }

        ///COMPARO EL DISPARO CON LOS VALORES GUARDADOS EN LA MATRIZ DEL JUGADOR Y GUARDO EL RESULTADO

        if(mPlayer[filaDisparo-1][columnaDisparo-1] == 'X')
        {
            banderaDisparo = 1;
            contDisparosContinuos++;
            matrizVisual[filaDisparo-1][columnaDisparo-1] = 'X';
        }
        else if(mPlayer[filaDisparo-1][columnaDisparo-1] == 'Y')
        {
            banderaDisparo = 1;
            contDisparosContinuos++;
            matrizVisual[filaDisparo-1][columnaDisparo-1] = 'X';
        }
        else if(mPlayer[filaDisparo-1][columnaDisparo-1] == 'Q')
        {
            banderaDisparo = 1;
            contDisparosContinuos++;
            matrizVisual[filaDisparo-1][columnaDisparo-1] = 'X';
        }
        else if(mPlayer[filaDisparo-1][columnaDisparo-1] == 'Z')
        {
            banderaDisparo = 1;
            contDisparosContinuos++;
            matrizVisual[filaDisparo-1][columnaDisparo-1] = 'X';
        }
        else
        {
            banderaDisparo = 0;
            matrizVisual[filaDisparo-1][columnaDisparo-1] = 'O';
        }

        ///MUESTRO EL TABLERO CON LOS VALORES ACTUALIZADOS

        system("cls");
        cartelBattleship();
        imprimirTablero(matrizVisual);

        ///MUESTRO UN CARTEL SEGUN EL DISPARO O SI DERRIBO UN BARCO

        if(mPlayer[filaDisparo-1][columnaDisparo-1] == 'X')
        {
            if(NroJugador == 1 && barcoXjugador1 < 3)
            {
                disparoRecibido(contDisparosContinuos);
                barcoXjugador1++;
                if(contDisparosContinuos > 1)
                {
                    acuPuntosP1 += contDisparosContinuos*100;
                }

            }
            else if(NroJugador == 1 && barcoXjugador1 == 3)
            {
                barcoXjugador1++;
                rlutil::locate(48,29);
                anuncio = GREEN "BARCO DE 4 UNIDADES UNDIDO!" RESET;
                maquinaDeEscribir(anuncio);
                acuPuntosP1 += 400 + mostrarPuntos(4,contDisparosContinuos);
            }
            else if(NroJugador == 2 && barcoXjugador2 < 3)
            {
                disparoRecibido(contDisparosContinuos);
                barcoXjugador2++;
                if(contDisparosContinuos > 1)
                {
                    acuPuntosP2 += contDisparosContinuos*100;
                }

            }
            else
            {
                barcoXjugador2++;
                rlutil::locate(48,29);
                anuncio = GREEN "BARCO DE 4 UNIDADES UNDIDO!" RESET;
                maquinaDeEscribir(anuncio);
                acuPuntosP2 += 400 + mostrarPuntos(4,contDisparosContinuos);
            }

        }
        else if(mPlayer[filaDisparo-1][columnaDisparo-1] == 'Y')
        {
            if(NroJugador == 1 && barcoYjugador1 < 2)
            {
                disparoRecibido(contDisparosContinuos);
                barcoYjugador1++;
                if(contDisparosContinuos > 1)
                {
                    acuPuntosP1 += contDisparosContinuos*100;
                }

            }
            else if(NroJugador == 1 && barcoYjugador1 == 2)
            {
                barcoYjugador1++;
                rlutil::locate(48,29);
                anuncio = GREEN "BARCO DE 3 UNIDADES UNDIDO!" RESET;
                maquinaDeEscribir(anuncio);
                acuPuntosP1 += 300 + mostrarPuntos(3,contDisparosContinuos);
            }
            else if(NroJugador == 2 && barcoYjugador2 < 2)
            {
                disparoRecibido(contDisparosContinuos);
                barcoYjugador2++;
                if(contDisparosContinuos > 1)
                {
                    acuPuntosP2 += contDisparosContinuos*100;
                }

            }
            else
            {
                barcoYjugador2++;
                rlutil::locate(48,29);
                anuncio = GREEN "BARCO DE 3 UNIDADES UNDIDO!" RESET;
                maquinaDeEscribir(anuncio);
                acuPuntosP2 += 300 + mostrarPuntos(3,contDisparosContinuos);
            }
        }
        else if(mPlayer[filaDisparo-1][columnaDisparo-1] == 'Q')
        {
            if(NroJugador == 1 && barcoQjugador1 < 1)
            {
                disparoRecibido(contDisparosContinuos);
                barcoQjugador1++;
                if(contDisparosContinuos > 1)
                {
                    acuPuntosP1 += contDisparosContinuos*100;
                }

            }
            else if(NroJugador == 1 && barcoQjugador1 == 1)
            {
                barcoQjugador1++;
                rlutil::locate(48,29);
                anuncio = GREEN "BARCO DE 2 UNIDADES UNDIDO!" RESET;
                maquinaDeEscribir(anuncio);
                acuPuntosP1 += 200 + mostrarPuntos(2,contDisparosContinuos);
            }
            else if(NroJugador == 2 && barcoQjugador2 < 1)
            {
                disparoRecibido(contDisparosContinuos);
                barcoQjugador2++;
                if(contDisparosContinuos > 1)
                {
                    acuPuntosP2 += contDisparosContinuos*100;
                }

            }
            else
            {
                barcoQjugador2++;
                rlutil::locate(48,29);
                anuncio = GREEN "BARCO DE 2 UNIDADES UNDIDO!" RESET;
                maquinaDeEscribir(anuncio);
                acuPuntosP2 += 200 + mostrarPuntos(2,contDisparosContinuos);
            }
        }
        else if(mPlayer[filaDisparo-1][columnaDisparo-1] == 'Z')
        {
            if(NroJugador == 1 && barcoZjugador1 < 1)
            {
                disparoRecibido(contDisparosContinuos);
                barcoZjugador1++;
                if(contDisparosContinuos > 1)
                {
                    acuPuntosP1 += contDisparosContinuos*100;
                }

            }
            else if(NroJugador == 1 && barcoZjugador1 == 1)
            {
                barcoZjugador1++;
                rlutil::locate(48,29);
                anuncio = GREEN "BARCO DE 2 UNIDADES UNDIDO!" RESET;
                maquinaDeEscribir(anuncio);
                acuPuntosP1 += 200 + mostrarPuntos(2,contDisparosContinuos);
            }
            else if(NroJugador == 2 && barcoZjugador2 < 1)
            {
                disparoRecibido(contDisparosContinuos);
                barcoZjugador2++;
                if(contDisparosContinuos > 1)
                {
                    acuPuntosP2 += contDisparosContinuos*100;
                }

            }
            else
            {
                barcoZjugador2++;
                rlutil::locate(48,29);
                anuncio = GREEN "BARCO DE 2 UNIDADES UNDIDO!" RESET;
                maquinaDeEscribir(anuncio);
                acuPuntosP2 += 200 + mostrarPuntos(2,contDisparosContinuos);

            }
        }

        else
        {
            rlutil::locate(48,29);//ternminadfakdsjfasfd
            string anuncio = RED "NINGUN OBJETIVO ALCANZADO." RESET;
            maquinaDeEscribir(anuncio);
        }


        rlutil::locate(42,31);
        system("pause");

        //SUMO EL DISPARO RECIBIDO AL CONTADOR DEL JUGADOR NECESARIO

        if(NroJugador == 1 && banderaDisparo == 1)
        {
            contadorAciertosN1++;
        }
        else if(NroJugador == 2 && banderaDisparo == 1)
        {
            contadorAciertosN2++;
        }

        system("cls");
        //CONDICION DO WHILE
    }
    while(banderaDisparo == 1 && contadorAciertosN1 < 11 && contadorAciertosN2 < 11);

    if(NroJugador == 1)
    {
        return acuPuntosP1;
    }
    else
    {
        return acuPuntosP2;
    }
}


void disparoRecibido(int disparos)
{
    rlutil::locate(53,29);
    string mensaje = GREEN "DISPARO RECIBIDO!" RESET;
    maquinaDeEscribir(mensaje);
    if(disparos > 1)
    {
        this_thread::sleep_for(chrono::seconds(1));
        for(int x = 0; x <= disparos* 100; x += 5)
        {
        rlutil::locate(54,29);
        cout<<"                             ";
        rlutil::locate(46,29);
        cout<<YELLOW<<"+"<<x<<"PTS POR ACIERTO CONSECUTIVO!"<<RESET;
        this_thread::sleep_for(chrono::milliseconds(15));
        }
    }
}



int mostrarPuntos(int tamBarco, int disparos)
{
    this_thread::sleep_for(chrono::seconds(1));
    for(int x = 0; x <= tamBarco* 100; x += 5)
    {
        rlutil::locate(48,29);
        cout<<"                             ";
        rlutil::locate(48,29);
        cout<<YELLOW<<"+"<<x<<"PTS POR BARCO DERRIBADO"<<RESET;
        this_thread::sleep_for(chrono::milliseconds(15));
    }
        if(disparos > 1)
    {
        this_thread::sleep_for(chrono::seconds(1));
        for(int x = 0; x <= disparos* 100; x += 5)
        {
        rlutil::locate(48,29);
        cout<<"                             ";
        rlutil::locate(46,29);
        cout<<YELLOW<<"+"<<x<<"PTS POR ACIERTO CONSECUTIVO!"<<RESET;
        this_thread::sleep_for(chrono::milliseconds(15));
        }
    }
    return disparos*100;
}





