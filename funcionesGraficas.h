#include "rlutil.h"

using namespace std;

///INCIALIZACION FUNCIONES

int procesoColorTablero(char (&matriz)[7][7]);

void asignacionMatrizProceso(int &fila, int &columna, char (&matriz)[7][7]);

void procesoColorCasillerosTablero(int posX, int posY, bool seleccionado, bool ocupado, bool agua);

void colorBotones(string opcion, int posX, int posY, bool seleccionado);

bool botones(int opcion);

///DECLARACION DE FUNCIONES

int procesoColorTablero(char (&matriz)[7][7]) //FUNCION PARA PODER ELEGIR LA POSICION CON LAS FLECHAS
{
    int pos = 0;
    int posCopy;
    int extra=0;
    int filas, columna;

    while(true) //WHILE PARA MOVERME POR EL MENU HASTA QUE SE PRESIONE ENTER.
    {
        extra = 0;
        filas = 0;

        for(int i = 13;i <= 26; i+=2)
        {
            columna = 0;
            for(int x = 50; x <= 74; x += 4)
            {
                procesoColorCasillerosTablero(x, i, pos == extra, matriz[filas][columna] != '-', matriz[filas][columna] == 'O');
                extra++;

                columna++;
            }
            filas++;
        }

        rlutil::hidecursor();

        switch(rlutil::getkey())
        {
        case 1: //ENTER
        {
            return pos;
            break;
        }
        case 16: // IZQUIERDA
        case 97: // IZQUIERDA
        {
            pos--;
            if(pos<0)
            {
                pos = 0;
            }
            break;
        }

        case 100: // DERECHA
        case 17: //DERECHA
        {
            pos++;
            if(pos>48)
            {
                pos = 48;
            }
            break;
        }


        case 119: // ARRIBA
        case 14: // ARRIBA
            posCopy = pos;
            pos -= 7;
            if(pos < 0)
            {
                pos = posCopy;
            }
            break;


        case 15: // ABAJO
        case 115: // ABAJO
            posCopy = pos;
            pos += 7;
            if(pos>48)
            {
                pos = posCopy;
            }
            break;


        }
    }
    //return 4;
}

void procesoColorCasillerosTablero(int posX, int posY, bool seleccionado, bool ocupado, bool agua)//FUNCION PARA CAMBIAR EL COLOR DE LOS CASILLEROS OCUPADOS Y SELECCIONADOS
{
    if(seleccionado)
    {
        rlutil::setBackgroundColor(rlutil::GREEN);
        rlutil::locate(posX,posY);
        cout <<" - "<<endl;
    }
    else if(agua)
    {
        rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        rlutil::locate(posX,posY);
        cout <<" O "<<endl;
    }
    else if(ocupado)
    {
        rlutil::setBackgroundColor(rlutil::RED);
        rlutil::locate(posX,posY);
        cout <<" X "<<endl;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posX,posY);
        cout <<" - "<<endl;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
}




void asignacionMatrizProceso(int &fila, int &columna, char (&matriz)[7][7])
{
    int casilla;
    casilla = procesoColorTablero(matriz)+1;
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





bool botones(int opcion)
{
    int pos = 0;

    while(true) //WHILE PARA MOVERME POR EL MENU HASTA QUE SE PRESIONE ENTER.
    {
        switch (opcion)
        {
        case 1:
            colorBotones("SI", 37, 31, pos == 0);
            colorBotones("NO", 80, 31, pos == 1);
            break;

        case 2:
            colorBotones("MANUALMENTE", 32, 16, pos == 0);
            colorBotones("AUTOMATICAMENTE", 76, 16, pos == 1);
            break;

        case 3:
            colorBotones("HORIZONTALMENTE", 32, 30, pos == 0);
            colorBotones("VERTICALMENTE", 76, 30, pos == 1);
            break;

        default:
            break;
        }


        rlutil::hidecursor();

        switch(rlutil::getkey())
        {
        case 1: //ENTER
        {
            switch (pos)
            {
            case 0:
                return 0;

            case 1:
                return 1;

            default:
                break;
            }
            break;
        }
        case 16: // IZQUIERDA
        case 97: // IZQUIERDA
        {
            pos--;
            if(pos<0)
            {
                pos = 0;
            }
            break;
        }

        case 100: // DERECHA
        case 17: //DERECHA
        {
            pos++;
            if(pos>1)
            {
                pos = 1;
            }
            break;
        }


        }
    }
    return 4;
}



void colorBotones(string opcion, int posX, int posY, bool seleccionado)
{
    if(seleccionado)
    {
        rlutil::locate(posX,posY);//DOBLE FLECHA >>
        rlutil::setBackgroundColor(rlutil::BLUE);
        cout << (char)175 <<" "<<opcion<<" "<< (char)174;
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posX,posY);//DOBLE FLECHA >>
        cout << "  " <<opcion<< "  "<<endl;
        rlutil::setBackgroundColor(rlutil::BLACK);
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
}

