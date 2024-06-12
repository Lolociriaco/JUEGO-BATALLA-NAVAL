#include <iostream>
#include "rlutil.h"
#include <chrono>   // Para sleep
#include <thread>   // Para sleep
#include <iomanip> // Para setw
#define R   "\033[0m"  //RESETEAR
#define BL    "\033[34m"  //AZUL
#define B   "\033[0;38;2;139;69;19m"  //MARRON
#define ROJO  "\033[31m" //ROJO
#define YELLOW "\033[33m" // Amarillo
#define NEGRO "\x1B[30m"	 // Amarillo

using namespace std;

///DECLARACI0ON DE FUNCIONES:

void imprimirTablero(char (&m)[7][7]);

void avisoCargaFlota(string nombreJugador);

void CartelDeInicio();

void cartelReglas();

void cartelSalida();

void maquinaDeEscribir(string mensaje);

void felicitacionGanador(string ganador, int puntos);

int confCargaAutomatica(string jugador);

void dibujoBarco();

int ejecMenu();

void colorOpcionesMenu(string opcion, int posX, int posY, bool seleccionado);

int colorTablero(char (&matriz)[7][7], bool direccion, int tamBarco);

void colorCasillerosTablero(int posX, int posY, bool seleccionado, char ocupado);

///FUNCIONES:

void felicitacionGanador(string ganador, int puntos)
{
    int x = 0;
    system("cls");
    rlutil::locate(39,14);
    string mensaje = "Felicitaciones ";
    string mensaje1 = ", has Ganado el Juego!!! ";
    maquinaDeEscribir(mensaje);
    maquinaDeEscribir(ganador);
    maquinaDeEscribir(mensaje1);

    this_thread::sleep_for(chrono::seconds(1));
    for(x = 0; x < puntos; x += 5)
    {
        rlutil::locate(48,16);
        cout<<YELLOW<<"PUNTOS TOTALES: "<<x<<RESET;
        this_thread::sleep_for(chrono::milliseconds(3));
    }
    for(int y = 0; y <= 8; y ++)
    {
        rlutil::locate(48,16);
        cout<<NEGRO<<"PUNTOS TOTALES: "<<x<<RESET;
        this_thread::sleep_for(chrono::milliseconds(250));
        rlutil::locate(48,16);
        cout<<YELLOW<<"PUNTOS TOTALES: "<<x<<RESET;
        this_thread::sleep_for(chrono::milliseconds(250));

    }
        this_thread::sleep_for(chrono::seconds(2));
}


void CartelDeInicio()
{
    rlutil::locate(54,14);
    string mensaje = "Battleship...";
    maquinaDeEscribir(mensaje);
    system("cls");

}

//FUNCION MENU DE INICIO

int ejecMenu()
{
    int pos = 0;
    system("cls");

    //MENU
    dibujoBarco();

    while(true) //WHILE PARA MOVERME POR EL MENU HASTA QUE SE PRESIONE ENTER.
    {
        colorOpcionesMenu("1. Empezar una Partida", 10, 23, pos == 0);
        colorOpcionesMenu("2. Reglas Y Objetivos", 50, 23, pos == 40);
        colorOpcionesMenu("3. Salir del Juego", 90, 23, pos == 80);

        rlutil::hidecursor();

        switch(rlutil::getkey())
        {
        case 1: //ENTER
        {
            switch (pos)
            {
            case 0:
                return 1;

            case 40:
                return 2;

            case 80:
                return 3;

            default:
                break;
            }
            break;
        }
        case 16: // IZQUIERDA
        {
            pos-=40;
            if(pos<8)
            {
                pos = 0;
            }
            break;
        }

        case 97: // IZQUIERDA
        {
            pos-=40;
            if(pos<8)
            {
                pos = 0;
            }
            break;
        }

        case 100: // DERECHA
        {
            pos+= 40;
            if(pos>80)
            {
                pos = 80;
            }
            break;
        }


        case 17: //DERECHA
        {
            pos+=40;
            if(pos>80)
            {
                pos = 80;
            }
            break;
        }


        }
    }
    return 4;
}



void colorOpcionesMenu(string opcion, int posX, int posY, bool seleccionado)
{
    if(seleccionado)
    {
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::locate(posX,posY);//DOBLE FLECHA >>
        cout << (char)175 <<" "<<opcion<<" "<< (char)174 <<endl;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posX,posY);//DOBLE FLECHA >>
        cout << "  " <<opcion<< "  "<<endl;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
}

void dibujoBarco()
{
    cout <<endl<<endl<< "                                                         "<<B<<"|   |   |"<<R<<"                                                  \n";
    cout << "                                                      )_)  )_)  )_)                                                 \n";
    cout << "                                                     )___))___))___)\\                                              \n";
    cout << "                                                   )_____)____)_____)\\                                             \n";
    cout << "                                                )_____)_______)_______)\\                                           \n";
    cout << "                                            ___"<<B<<"|"<<R<<"____"<<B<<"|"<<R<<"____"<<B<<"|"<<R<<"____"<<B<<"|"<<R<<"____"<<B<<"|"<<R<<"____\\                                          \n";
    cout <<B<< "                                    -----------\\                   //--------                                      \n";
    cout << "                                (-----)()()))))))))))))))))))))))))))))))))))))))))))                               \n";
    cout << "                                  (----)()()))))))))))))))))))))))))))))))))))))))                                  \n";
    cout << BL<<"                        ^^^^^  ^^ ^^^"<<B<<"(---)()()))))))))))))))))))))))))))))))))))  "<<BL<<" ^^^^^^^^^^                       \n"<<R;
    cout << BL<<"               ^^^^       ^^^ "<<B<<"         (--)()())))))))))))))))))))))))))))  "<<BL<<"^^^^^^     ^^^                          \n";
    cout <<"                           ^^^^^    ^^    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^       ^^^                              \n";
    cout <<"                          ^^^^                  ^^^^^^^^^^            ^^      ^^^          ^^^^                     \n"<<R<<endl;
    cout << "                                                   === BATTLESHIP ===                                               \n"<<endl;
    cout << "====================================================================================================================="<<endl<<endl;
    cout << "====================================================================================================================="<<endl<<endl;

}


void avisoCargaFlota(string nombreJugador)
{
    cout <<endl<<"                                                    === BATTLESHIP ===                                               "<<endl<<endl;
    cout <<"======================================================================================================================"<<endl;
    rlutil::locate(47,5);
    cout <<"- POSICIONE SU FLOTA "<<nombreJugador<<endl;
    cout <<"======================================================================================================================"<<endl<<endl;
}





//FUNCION PARA IMPRIMIR TABLERO

void imprimirTablero(char (&m)[7][7])
{
    int columna,fila = 0;
    rlutil::locate(45,10);//51-55-59
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,11);
    cout<<"|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |"<<endl;rlutil::locate(45,12);
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,13);
    cout<<"| 1 |   |   |   |   |   |   |   |"<<endl;rlutil::locate(45,14);
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,15);
    cout<<"| 2 |   |   |   |   |   |   |   |"<<endl;rlutil::locate(45,16);
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,17);
    cout<<"| 3 |   |   |   |   |   |   |   |"<<endl;rlutil::locate(45,18);
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,19);
    cout<<"| 4 |   |   |   |   |   |   |   |"<<endl;rlutil::locate(45,20);
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,21);
    cout<<"| 5 |   |   |   |   |   |   |   |"<<endl;rlutil::locate(45,22);
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,23);
    cout<<"| 6 |   |   |   |   |   |   |   |"<<endl;rlutil::locate(45,24);
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,25);
    cout<<"| 7 |   |   |   |   |   |   |   |"<<endl;rlutil::locate(45,26);
    cout<<"+---+---+---+---+---+---+---+---+"<<endl;rlutil::locate(45,27);
    cout<<endl<<endl;

        for(int i = 13;i <= 26; i+=2)
        {
            columna = 0;
            for(int x = 50; x <= 74; x += 4)
            {
                if(m[fila][columna] == 'X')
                {
                    rlutil::locate(x,i);
                    rlutil::setBackgroundColor(rlutil::RED);
                    cout<<" X ";
                }
                else if(m[fila][columna] == 'Y')
                {
                    rlutil::locate(x,i);
                    rlutil::setBackgroundColor(rlutil::RED);
                    cout<<" Y ";
                }
                else if(m[fila][columna] == 'Q')
                {
                    rlutil::locate(x,i);
                    rlutil::setBackgroundColor(rlutil::RED);
                    cout<<" Q ";
                }
                else if(m[fila][columna] == 'Z')
                {
                    rlutil::locate(x,i);
                    rlutil::setBackgroundColor(rlutil::RED);
                    cout<<" Z ";
                }
                else if(m[fila][columna] == 'O')
                {
                    rlutil::locate(x,i);
                    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
                    cout<<" O ";
                }
                else
                {
                    rlutil::locate(x,i);
                    rlutil::setBackgroundColor(rlutil::BLACK);
                    cout<<" - ";
                }
                columna++;
            }
            fila++;

        }
        rlutil::setBackgroundColor(rlutil::BLACK);
}



void cartelReglas()
{
    system("cls");
    cout <<endl<<ROJO<< "    1. REGLAS DEL JUEGO:"<<R<<endl;
    cout << "       - Cada jugador coloca sus barcos en un tablero de 7x7 casilleros."<<endl;
    cout << "       - Los barcos no pueden superponerse ni colocarse en diagonal."<<endl;
    cout << "       - Los barcos son de tres distintos tamaños: 2, 3 y 4 casillas."<<endl;
    cout << "       - Los jugadores se turnan para intentar adivinar la ubicación de los barcos del oponente."<<endl;
    cout << "       - Si un jugador derriva un barco, puede continuar disparando hasta que erre su tiro."<<endl;
    cout << "       - Gana el jugador que hunda todos los barcos del oponente primero."<<endl<<endl;
    cout <<ROJO<< "   2. OBJETIVOS DEL JUEGO:"<<R<<endl;
    cout << "       - Hundir todos los barcos del oponente antes de que él hunda los tuyos."<<endl;
    cout << "       - Utilizar estrategia y deducción para adivinar la ubicación de los barcos enemigos."<<endl;
    cout << "       - Proteger tus propios barcos y tratar de engañar al oponente con tu disposición."<<endl<<endl;
    cout <<ROJO<< "   3. DETALLES:"<<R<<endl;
    cout << "       - Los barcos son cargados de IZQUIERDA A DERECHA O DE ARRIBA HACIA ABAJO segun haya ingresado antes de ingresar \n         las coordenadas."<<endl;
    cout << "         Tenga esto en cuenta ya que si el barco esta mal posicionado, el juego no lo dejara utilizar esa posicion."<<endl;
    cout << "       - Podra decidir si reposicionar sus tropas de manera distinta antes de que el rival cargue las suyas."<<endl;
    cout << "       - Si ingresa una direccion del barco invalida, el juego se lo indicara y le permitira ingresarla nuevamente."<<endl<<endl<<"         ";

    system("pause");

}

void cartelSalida()
{
    system("cls");
    rlutil::locate(54,14);
    string mensaje = "Cerrando el juego...";
    maquinaDeEscribir(mensaje);
    system("cls");
}

void maquinaDeEscribir(string mensaje)
{
    int contadorPuntos = 0;
    for (char c : mensaje)
    {
        cout << c << flush; // flush para forzar la salida

        if(contadorPuntos == 2)
        {
            this_thread::sleep_for(chrono::seconds(2)); // Pausa más larga para saltos de línea
        }
        else if (c == '.')
        {
            contadorPuntos++;
            this_thread::sleep_for(chrono::milliseconds(50)); // Pausa estándar para otros caracteres
        }

        else
        {
            this_thread::sleep_for(chrono::milliseconds(50)); // Pausa estándar para otros caracteres
        }
    }
}



int confCargaAutomatica(string jugador)
{
    bool ret;
    system("cls");
    rlutil::locate(34,14);
    cout<<"Es su turno "<<jugador<<", ingrese de que modo quiere cargar su flota"<<endl;
    ret = botones(2);
    system("cls");
    return ret;
}



int colorTablero(char (&matriz)[7][7], bool direccion, int tamBarco) //FUNCION PARA PODER ELEGIR LA POSICION CON LAS FLECHAS
{
    int pos = 0;
    int posCopy;
    int extra=0;
    int filas, columna;
    int casilleroSeleccionado=0;
    int xSeleccionada;
    int iSeleccionada;

    while(true) //WHILE PARA MOVERME POR EL MENU HASTA QUE SE PRESIONE ENTER.
    {
        extra = 0;
        filas = 0;

        for(int i = 13;i <= 26; i+=2)
        {
            columna = 0;
            for(int x = 50; x <= 74; x += 4)
            {
                colorCasillerosTablero(x, i, pos == extra, matriz[filas][columna]);
                if(pos == extra)
                {
                    casilleroSeleccionado = pos;
                    xSeleccionada = x;
                    iSeleccionada = i;
                }
                extra++;
                columna++;
            }
            filas++;

        }
        if(direccion == 0)
        {
            for(int x = xSeleccionada;x <= xSeleccionada+(tamBarco-1)*4; x+=4)
            {
                colorCasillerosTablero(x,iSeleccionada, true, '-');
            }
        }
        else
        {
            for(int i = iSeleccionada;i <= iSeleccionada+(tamBarco-1)*2; i+=2)
            {
                colorCasillerosTablero(xSeleccionada,i, true, '-');
            }
        }

        rlutil::hidecursor();

        switch(rlutil::getkey())
        {
        case 1: //ENTER
        {
            return pos;
            break;
        }


        case 97: // IZQUIERDA
        case 16: // IZQUIERDA
        {
            pos--;
            if(pos<0)
            {
                pos = 0;
            }
            else if(direccion == 0 && pos == 6)
            {
                pos = 7;
            }
            else if(direccion == 0 && pos == 13)
            {
                pos = 14;
            }
            else if(direccion == 0 && pos == 20)
            {
                pos = 21;
            }
            else if(direccion == 0 && pos == 27)
            {
                pos = 28;
            }
            else if(direccion == 0 && pos == 34)
            {
                pos = 35;
            }
            else if(direccion == 0 && pos == 41)
            {
                pos = 42;
            }

            break;
        }


        case 17: //DERECHA
        case 100: // DERECHA
        {
            posCopy = pos;
            pos++;
            if(direccion == 0 && pos + tamBarco == 8)
            {
                pos = posCopy;
            }
            else if(direccion == 0 && pos + tamBarco == 15)
            {
                pos = posCopy;
            }
            else if(direccion == 0 && pos + tamBarco == 22)
            {
                pos = posCopy;
            }
            else if(direccion == 0 && pos + tamBarco == 29)
            {
                pos = posCopy;
            }
            else if(direccion == 0 && pos + tamBarco == 36)
            {
                pos = posCopy;
            }
            else if(direccion == 0 && pos + tamBarco == 43)
            {
                pos = posCopy;
            }
            else if(direccion == 0 && pos + tamBarco == 50)
            {
                pos = posCopy;
            }
            else if(direccion == 1 && pos + (tamBarco-1)*7 > 48)
            {
                pos = posCopy;
            }

            break;
        }


        case 14: // ARRIBA
        case 119: // ARRIBA
            posCopy = pos;
            pos -= 7;
            if(pos < 0)
            {
                pos = posCopy;
            }
            break;


        case 115: // ABAJO
        case 15: // ABAJO
            posCopy = pos;
            pos += 7;
            if(pos>48)
            {
                pos = posCopy;
            }
            else if(direccion == 1 && pos + (tamBarco-1)*7 > 48)
            {
                pos = posCopy;
            }
            break;


        }
    }
    //return 4;
}

void colorCasillerosTablero(int posX, int posY, bool seleccionado, char ocupado)//FUNCION PARA CAMBIAR EL COLOR DE LOS CASILLEROS OCUPADOS Y SELECCIONADOS
{
    if(seleccionado)
    {
        rlutil::setBackgroundColor(rlutil::GREEN);
        rlutil::locate(posX,posY);
        cout <<" - "<<endl;
    }
    else if(ocupado != '-')
    {
        rlutil::setBackgroundColor(rlutil::RED);
        rlutil::locate(posX,posY);
        cout <<" "<<ocupado<<" "<<endl;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posX,posY);
        cout <<" - "<<endl;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
}

