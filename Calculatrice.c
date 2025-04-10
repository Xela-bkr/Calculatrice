/**
 * @file Calculatrice.c
 * @brief Implémentation d'une calculatrice simple pour apprendre à manipuler le langage C
 * 
 * @author Alexandre Bakiri
 * @version 1.0
 * 
 * @date 09/04/2025
 */
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>

// Codes ASCII de chaque opérateur //
#define PLUS 43
#define MOINS 45
#define DIVISER 47
#define MULTIPLIER 42
#define ET_BAB 38
#define MODULO 37
#define OU_BAB 124
#define CHEVRON_DROITE 62
#define CHEVRON_GAUCHE 60

// Codes d'échappement ANSI

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

// Autres constantes

#define NOMBRE_CHAR_AFFICHAGE 60
#define TITLE "Calculatrice"
#define BORDER() printf(GREEN "| " RESET);

/**
 * Division
 * @brief fonction pour effectuer une divition, vérifie l'erreur division par 0
 * 
 * @param integer numerateur a
 * @param integer denominateur b
 * 
 * @return float result
 */
float div(long int a, long int b){
    if(b == 0){
        BORDER()
        printf(RED"Erreur : divison par 0\n" RESET);
        return 0;
    }
    return a/b;
}

/**
 * Affichage
 * @brief fonction pour afficher un cadre de calculatrice fancy
 * 
 * @param void
 * 
 * @return void
 */
void start(void){
    for(int i = 0; i<NOMBRE_CHAR_AFFICHAGE+1; i++){
        if(i==NOMBRE_CHAR_AFFICHAGE/2){printf(BLUE TITLE RESET);}
        else{printf(GREEN "-" RESET);}
    }
    printf(GREEN "\n|" RESET);
    for(int i = 0; i<NOMBRE_CHAR_AFFICHAGE + sizeof(TITLE) -3; i++){
        printf(" ");
    }
    printf(GREEN "|\n" RESET);
    //for(int i = 0; i<NOMBRE_CHAR_AFFICHAGE+sizeof(TITLE)-1; i++){
        //printf(GREEN "-" RESET);
    //}
    //printf("\n");
}

////**** MAIN ****////
int main(void){
    long int a, b;
    char c[4] = {0,0,0,0};

    start();

    BORDER()
    printf(BLUE "Entrez un nombre : " RESET);
    scanf("%d", &a);

    BORDER()
    printf(BLUE "Entrez un opérateur : " RESET);
    scanf("%s", &c);

    BORDER()
    printf(BLUE "Entrez un nombre : " RESET);
    scanf("%d", &b);

    BORDER()
    printf(BLUE "Votre opération : "RESET"%d %s %d\n", a, c, b);

    switch (c[0]){
        case PLUS :
        {
            int16_t addition = a+b;
            BORDER()
            printf(YELLOW "Rélustat : "RESET"%d\n",addition);
        }break;
        case MOINS :
        {
            int16_t soustraction = (a-b);
            BORDER()
            printf(YELLOW "Rélustat : "RESET"%d\n",soustraction);
        }break;
        case MULTIPLIER :
        {
            int16_t multiplication = a*b;
            BORDER()
            printf(YELLOW "Rélustat : "RESET"%d\n", multiplication);
        }break;
        case DIVISER :
        {
            float division = div(a,b);
            BORDER()
            printf(YELLOW "Rélustat : "RESET"%d\n", division);
        }break;
        case CHEVRON_DROITE :
        {
            if(c[1] == CHEVRON_DROITE){
                int16_t cd = a >> b;
                BORDER()
                printf(YELLOW " Rélustat : "RESET"%d\n", cd);
            }
            else{
                printf("Erreur de saisie : '><'");
                return 0;
            }
        }break;
        case CHEVRON_GAUCHE :
        {
            if(c[1]==CHEVRON_GAUCHE){
                int16_t cg = a << b;
                BORDER()
                printf(YELLOW " Rélustat : "RESET"%d\n", cg);
            }
            else{
                printf(RED"Erreur de saisie : "RESET"'<>'");
                return 0;
            }
        }break;
        case OU_BAB :
        {
            BORDER()
            printf(YELLOW " Rélustat : "RESET"%d\n", a | b);
        }break;
        case ET_BAB :
        {
            BORDER()
            printf(YELLOW " Rélustat : "RESET"%d\n", a & b);
        }break;
        case MODULO :
        {
            BORDER()
            printf(YELLOW " Rélustat : "RESET"%d\n", a % b);
        }break;
        default :
        {
            BORDER()
            printf(RED" Opérateur non reconnu"RESET);
        }
            break;
        return 0;
    }
}