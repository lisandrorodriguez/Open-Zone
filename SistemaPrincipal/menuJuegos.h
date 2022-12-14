#include "Cyber-Games/Juegos/TaTeTi.h"
#include "Cyber-Games/Juegos/Ahorcado.h"
#include "Cyber-Games/Juegos/BlackJack.h"
#include "Cyber-Games/Juegos/Matematicas.h"
#include "configMostrarCuenta.h"
#include "SumarPuntos.h"

bool flag = true;
bool ganarFichas();
void menuJuegos(tDatosUsuario *);
void menuSwitchJuegos(int, tDatosUsuario *);
void imprimirTitulos();
void ganarSaldo(tDatosUsuario *);
bool compararSaldo(int);

void menuJuegos(tDatosUsuario *Userlogeado)
{
    actualizarConexion(Userlogeado);
    int respuesta;
    do
    {
        printf("\t\t---------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t-*- Juegos -*-\n");
        printf("\t\t\t\t\t<--- %s Tienes %d fichas --->\n", Userlogeado->nombreUsuario, Userlogeado->saldo);
        printf("\t\t---------------------------------------------------------------------\n");
        imprimirTitulos();
        if (!strcmp(Userlogeado->nombreUsuario, "admin"))
        {
            printf("\t\t\t\t6. Mostrar cuentas registradas de usuarios\n");
        }
        printf("\t\t\t\t>>> ");
        scanf("%d", &respuesta);
        menuSwitchJuegos(respuesta, Userlogeado);
        if (saldoen0(Userlogeado->saldo))
        {
            system("cls");
            printf("<---\tNo tienes mas fichas\t--->\n");
            if (ganarFichas())
                ganarSaldo(Userlogeado);
            else
                continue;
        }
    } while (Userlogeado->saldo > 0 && flag);
}

void menuSwitchJuegos(int pEleccion, tDatosUsuario *Userlogeado)
{
    switch (pEleccion)
    {
    case 1:
        mainmath(Userlogeado);
        break;
    case 2:
        menublackjack(Userlogeado);
        break;
    case 3:
        menuahorcado(Userlogeado);
        break;
    case 4:
        ganarSaldo(Userlogeado);
        break;
    case 5:
        printf("\t\t\t\tSaliendo...\n");
        system("pause");
        system("cls");
        flag = false;
        printf("\t\t\tSi va a entrar con otra cuenta por favor reinicie el programa.\n");
        actualizarPuntos(Userlogeado);
        actualizarFichas(Userlogeado);
        break;
    case 6:
        if (!strcmp(Userlogeado->nombreUsuario, "admin"))
        {
            procesarCuentasUsuarios();
            system("pause");
            system("cls");
            break;
        }
        else
        {
            system("cls");
            printf("\t\t\t\t\t\033[0;31m[X]Error opcion incorrecta[X]\033[0m\n");
            menuJuegos(Userlogeado);
            break;
        }
    default:
        system("cls");
        printf("\t\t\t\t\t\033[0;31m[X]Error opcion incorrecta[X]\033[0m\n");
        menuJuegos(Userlogeado);
        break;
    }
}

void imprimirTitulos()
{
    printf("\t\t\t\t1. Matematicas\n");
    printf("\t\t\t\t2. BlackJack\n");
    printf("\t\t\t\t3. Ahorcado\n");
    printf("\t\t\t\t4- TaTeTi vs Bot\n");
    printf("\t\t\t\t5- Salir\n");
}

bool compararSaldo(int saldo)
{
    return saldo > 0;
}

void ganarSaldo(tDatosUsuario *Userlogeado)
{
    programaTateti(Userlogeado);
}

bool ganarFichas()
{
    bool aux;
    int decision;
    printf("Para seguir jugando, tendras que ganar fichas contra el bot\nTambien puedes terminar tu turno\nChoose:\n(1) Jugar vs el bot\n(0) Terminar el turno\n>>> ");
    scanf("%d", &decision);
    aux = decision;
    return aux;
}