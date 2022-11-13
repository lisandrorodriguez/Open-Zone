
#include "Juegos/Matematicas.h"
#include "Juegos/Vibora.h"
#include "Juegos/TaTeTi.h"
#include "Juegos/BlackJack.h"



bool ganarFichas();
bool compararSaldo(int);

void imprimirTitulos() {
    printf("Elija un juego\n");
    printf("1. Matematicas\n");
    printf("2. BlackJack\n");
    printf("3. Vibora\n");
    printf("4- TaTeTi vs Bot | Ganar Saldo\n");
    printf("5- Salir\n>>> ");

}

void jugarsegunEleccion(int pEleccion, int * pSaldo) {
    switch (pEleccion)
    {
    case 1: mainmath(pSaldo); break;
    case 2: menublackjack(pSaldo);break;
    case 3: menusnake(pSaldo);break;
    case 4: ganarSaldo(pSaldo); break;
    case 5: exit(0);
    default: printf("Valor ingresado erroneo!"); break;
    }
}

void menudeJuegos() {
    int ingreso;
    int contador = 1;
    do 
    {
        system("cls");
        printf("<---\tTienes %d ficha/s\t--->\n", contador);
        imprimirTitulos();
        scanf("%d", &ingreso);
        jugarsegunEleccion(ingreso, &contador);
        if (saldoen0(contador)){
            saldo0 : ;
            printf("<---\tNo tienes mas fichas\t--->\n");
            if (ganarFichas()) ganarSaldo(&contador);
            else continue;
        }

    } while(contador>0); 

}
    
bool compararSaldo(int saldo) {
    return saldo > 0;
}

void ganarSaldo(int * pSaldo) {
    programaTateti(pSaldo);
}

bool ganarFichas() {
    int decision;
    printf("Para seguir jugando, tendras que ganar fichas contra el bot\nTambien puedes terminar tu turno\nChoose:\n(1) Jugar vs el bot\n(0) Terminar el turno\n>>> ");
    scanf("%d", &decision);
    return decision;
}




