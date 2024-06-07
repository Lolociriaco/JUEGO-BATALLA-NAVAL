#include <iostream>

using namespace std;

///DECLARO LAS FUNCIONES;

void inicializadorMatrizes(char (&matriz)[7][7]);

int determinarGanador(char (&matrizVisual)[7][7]);

void cargaNombreJugadores(int &jugador1, int &jugador2);

int funValidacionBarcos(char (&mPlayer)[7][7]);

void cartelBattleship();

///INICIALIZO LAS FUNCIONES:


void cartelBattleship()
{
    cout <<endl<<endl<<"                                                   === BATTLESHIP ===                                               "<<endl<<endl;
    cout <<"======================================================================================================================"<<endl<<endl;
    cout <<"======================================================================================================================";
}



//FUNCION DE INICIALIZACION EN '-'

void inicializadorMatrizes(char (&matriz)[7][7])
{
    for(int x = 0; x < 7; x++)
    {
        for(int i = 0; i < 7; i++)
        {
            matriz[x][i] = '-';
        }
    }
}


//FUNCION DE CARGA DE LOS NOMBRES DE LOS JUGADORES

void cargaNombreJugadores(string &jugador1, string &jugador2)
{
    rlutil::showcursor();
    system("cls");
    cout <<endl<<"                                                   === BATTLESHIP ===" << endl;
    cout <<"===================================================================================================================="<<endl;
    cout <<"                          - INGRESE EL NOMBRE DEL PRIMER JUGADOR: ";
    cin>>jugador1;
    cout <<"===================================================================================================================="<<endl;
    cout <<"                          - INGRESE EL NOMBRE DEL SEGUNDO JUGADOR: ";
    cin>>jugador2;
    cout<<endl;
    system("cls");
}


///BUCLE PARA DETERMINAR AL GANADOR SEGUN LA CANTIDAD DE 'X' EN LA MATRIZ VISUAL

int determinarGanador(char (&matrizVisual)[7][7])
    {
        int contadorAciertos = 0;
        for(int x = 0; x < 7; x++)
        {
            for(int i = 0; i < 7; i++)
            {
                if(matrizVisual[x][i] == 'X')
                {
                    contadorAciertos++;
                }
            }

        }
        return contadorAciertos;
    }


int funValidacionBarcos(char (&mPlayer)[7][7])
{
    int validacion;
    imprimirTablero(mPlayer);
    rlutil::locate(45,29);
    cout<<"-Desea reposicionar sus tropas?"<<endl;
    validacion = botones(1);
    return validacion;
    system("cls");
}
